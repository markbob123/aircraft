#include "string.h"
#include <math.h>
#include "remoter_ctrl.h"
#include "config_param.h"
#include "commander.h"
#include "flip.h"
#include "radiolink.h"
#include "sensors.h"
#include "pm.h"
#include "stabilizer.h"

/*FreeRTOS���ͷ�ļ�*/
#include "FreeRTOS.h"
#include "task.h"

/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
 * ALIENTEK MiniFly
 * �ֻ�wifi������������	
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2017/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
 * All rights reserved
********************************************************************************/

static ctrlVal_t remoterCtrl;/*���͵�commander��̬��������*/
static MiniFlyMsg_t msg;

/*����������Ϣ*/
void sendMsgACK(void)
{
	msg.version = configParam.version;
	msg.mpu_selfTest = getIsMPU9250Present();
	msg.baro_slfTest = getIsBaroPresent();
	msg.isCanFly = getIsCalibPass();
	msg.isLowpower = getIsLowpower();
	
	atkp_t p;
	p.msgID = UP_REMOTER;
	p.dataLen = sizeof(msg)+1;
	p.data[0] = ACK_MSG;
	memcpy(p.data+1, &msg, sizeof(msg));
	radiolinkSendPacketBlocking(&p);	
}

/*ң�����ݽ��մ���*/
void remoterCtrlProcess(atkp_t* pk)
{	
	if(pk->data[0] == REMOTER_CMD)
	{
		switch(pk->data[1])
		{
			case CMD_FLIGHT_LAND:
				if(getCommanderKeyFlight() != true)
				{
					setCommanderKeyFlight(true);
					setCommanderKeyland(false);
				}
				else
				{
					setCommanderKeyFlight(false);
					setCommanderKeyland(true);
				}
				break;

			case CMD_EMER_STOP:
				setCommanderKeyFlight(false);
				setCommanderKeyland(false);
				break;
			
			case CMD_FLIP:
				setFlipDir(pk->data[2]);
				break;
			
			case CMD_GET_MSG:
				sendMsgACK();
				break;
		}
	}
	else if(pk->data[0] == REMOTER_DATA)
	{
		remoterData_t remoterData = *(remoterData_t*)(pk->data+1);
		
		remoterCtrl.roll = remoterData.roll;
		remoterCtrl.pitch = remoterData.pitch;
		remoterCtrl.yaw = remoterData.yaw;
		remoterCtrl.thrust = remoterData.thrust * 655.35f;
		remoterCtrl.trimPitch = remoterData.trimPitch;
		remoterCtrl.trimRoll = remoterData.trimRoll;
		
		setCommanderAltholdMode(remoterData.ctrlMode);
		setCommanderFlightmode(remoterData.flightMode);
		flightCtrldataCache(ATK_REMOTER, remoterCtrl);
	}
}
