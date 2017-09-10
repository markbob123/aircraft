#ifndef __SENSORS_TYPES_H
#define __SENSORS_TYPES_H
#include "sys.h"

/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 * ALIENTEK MiniFly
 * sensor�������Ͷ���	
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2017/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
 * All rights reserved
********************************************************************************/

typedef struct 
{
	s16 x;
	s16 y;
	s16 z;	
} Axis3i16;

typedef struct 
{
	int x;
	int y;
	int z;
} Axis3i32;

typedef struct {
	int64_t x;
	int64_t y;
	int64_t z;
} Axis3i64;

typedef struct 
{
	float x;
	float y;
	float z;
} Axis3f;
 
#endif /* __SENSORS_TYPES_H */
