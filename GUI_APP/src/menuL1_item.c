#include "menuL1_item.h"
#include "menu_ui.h"
#include "windows.h"
#include "scrollbar.h"
#include "joystick.h"
#include "keyTask.h"
#include "display.h"
#include "OLED.h"
#include "config_param.h"
#include "24l01.h"
#include "menuL2_item.h"

/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 * ALIENTEK MiniFly_Remotor
 * һ���˵���������	
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2017/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
 * All rights reserved
********************************************************************************/

#define  MAIN_MENU_ITEMNUM    		9	//���˵�����

MenuItem_Typedef  mainMenu[MAIN_MENU_ITEMNUM];

/****** ��ָ��ťͼ�� ���� ����ʽ ˳��(��λ��ǰ) *****/
const u8 finger_img[32]={
0x07,0xF0,0x04,0x10,0x04,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x04,0x20,0x04,
0x41,0x54,0x4D,0x5C,0x75,0x70,0x05,0xC0,0x05,0x00,0x05,0x00,0x05,0x00,0x02,0x00,
};

const u8 mainMenuTitle[] = "ATK Mini Flyer";

const u8* mainMenuLanguage[3][MAIN_MENU_ITEMNUM]={
{
"1.����ģʽ",
"2.����ģʽ",
"3.�����ٶ�",
"4.����ʹ��",
"5.ҡ��У׼",
"6.ƥ������",
"7.����ѡ��",
"8.����",
"9.�˳�",	
},
{
"1.Control Mode",
"2.Flight Mode",
"3.Flight Speed",
"4.Flip Enable",
"5.Joystick Calib",
"6.Match MiniFly",
"7.Language",
"8.Reset",
"9.Exit",
},
{
"1.����ģʽ",
"2.�w��ģʽ",
"3.�w���ٶ�",
"4.���Lʹ��",
"5.�u�UУ��",
"6.ƥ�����S",
"7.�Z���x��",
"8.����",
"9.�˳�",
},
};

void gotoJoystickCalibUI(void)
{
	exitMenu();
	setShow_ui(JOYSTICK_CALIB_UI);
}

void gotoMatchMiniFlyUI(void)
{
	exitMenu();
	setShow_ui(MATCH_UI);
}

void gotoResetUI(void)
{
	exitMenu();
	setShow_ui(RESET_UI);
}

/*��ʼ�����˵�*/
void mainMenuInit(void)
{	
	for(int i=0; i<MAIN_MENU_ITEMNUM; i++)
	{
		mainMenu[i].menuItemCount = MAIN_MENU_ITEMNUM;
		mainMenu[i].isSelect = false;
		mainMenu[i].icoSelected = finger_img;
		mainMenu[i].icoUnselected = NULL;
		mainMenu[i].title = mainMenuLanguage[configParam.language][i];
		mainMenu[i].Function = NULL;
		mainMenu[i].parentMenu = NULL;
		mainMenu[i].childrenMenu = NULL;
	}
	mainMenu[0].isSelect = true;
	mainMenu[0].Function = gotoNextMenu;
	mainMenu[0].childrenMenu = controlmodeMenu;

	mainMenu[1].Function = gotoNextMenu;
	mainMenu[1].childrenMenu = flymodeMenu;
	
	mainMenu[2].Function = gotoNextMenu;
	mainMenu[2].childrenMenu = flyspeedMenu;
	
	mainMenu[3].Function = gotoNextMenu;
	mainMenu[3].childrenMenu = flipEnableMenu;

	mainMenu[4].Function = gotoJoystickCalibUI;
	mainMenu[4].childrenMenu = NULL;
	
	mainMenu[5].Function = gotoMatchMiniFlyUI;
	mainMenu[5].childrenMenu = NULL;
	
	mainMenu[6].Function = gotoNextMenu;
	mainMenu[6].childrenMenu = languageMenu;
	
	mainMenu[7].Function = gotoResetUI;
	mainMenu[7].childrenMenu = NULL;
	
	mainMenu[8].Function = exitMenu;
	mainMenu[8].childrenMenu = NULL;
}
