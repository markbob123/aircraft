#ifndef __MENUL2_ITEM_H
#define __MENUL2_ITEM_H
#include <stdint.h>
#include "gui_menu.h"

/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 * ALIENTEK MiniFly_Remotor
 * �����˵���������		
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2017/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
 * All rights reserved
********************************************************************************/

extern MenuItem_Typedef  controlmodeMenu[];
extern MenuItem_Typedef  flymodeMenu[];
extern MenuItem_Typedef  flyspeedMenu[];
extern MenuItem_Typedef  flipEnableMenu[];
extern MenuItem_Typedef  languageMenu[];

void flymodeMenuInit(void);
void controlmodeMenuInit(void);
void languageMenuInit(void);
void flySpeedMenuInit(void);
void flipEnableMenuInit(void);

#endif /*__MENUL2_ITEM_H*/

