#ifndef __SENSORS_H
#define __SENSORS_H
#include "stabilizer_types.h"

/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 * ALIENTEK MiniFly
 * ���������ƴ���	
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2017/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
 * All rights reserved
********************************************************************************/

//#define SENSORS_ENABLE_MAG_AK8963
#define SENSORS_ENABLE_PRESSURE_BMP280	/*��ѹ��ʹ��bmp280*/

#define BARO_UPDATE_RATE		RATE_50_HZ
#define SENSOR9_UPDATE_RATE   	RATE_500_HZ
#define SENSOR9_UPDATE_DT     	(1.0f/SENSOR9_UPDATE_RATE)

/**
 * Set ACC_WANTED_LPF1_CUTOFF_HZ to the wanted cut-off freq in Hz.
 * The highest cut-off freq that will have any affect is fs /(2*pi).
 * E.g. fs = 350 Hz -> highest cut-off = 350/(2*pi) = 55.7 Hz -> 55 Hz
 */
#define SENSORS_ACC_WANTED_LPF_CUTOFF_HZ  4
/**
 * Attenuation should be between 1 to 256.
 *
 * f0 = fs / 2*pi*attenuation ->
 * attenuation = fs / 2*pi*f0
 */
#define SENSORS_ACC_IIR_LPF_ATTENUATION (SENSOR9_UPDATE_RATE / (2 * 3.1415 * SENSORS_ACC_WANTED_LPF_CUTOFF_HZ))
#define SENSORS_ACC_IIR_LPF_ATT_FACTOR  (int)(((1<<IIR_SHIFT) / SENSORS_ACC_IIR_LPF_ATTENUATION) + 0.5)
#define SENSORS_ACC_IIR_FACTOR		(float)(1/(1+SENSORS_ACC_IIR_LPF_ATTENUATION))
	
void sensorsInit(void);	/*��������ʼ��*/
bool sensorsTest(void);	/*����������*/
bool sensorsAreCalibrated(void);	/*����������У׼*/
void sensorsAcquire(sensorData_t *sensors, const u32 tick);/*��ȡ����������*/
void getSensorRawData(Axis3i16* acc, Axis3i16* gyro, Axis3i16* mag);
bool getIsMPU9250Present(void);
bool getIsBaroPresent(void);

#endif //__SENSORS_H
