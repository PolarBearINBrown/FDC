#ifndef _HEADERS_H_
#define _HEADERS_H_

#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "stm32f10x_rcc.h"

extern int Mode;
extern int Mode_Size;

extern int  min(int a,int b);
extern int  max(int a,int b);
extern int  abs(int a);

/***************************

一些备注：
B10 B11 用于FDC的通讯
C6 C7 C8 C9 用于电机调速
A8 G2 G3 G4 G5 G6 G7 G8 用于控制电机方向
E2 E3 E4 E5 E6 用于接收按键
D 用于LCD
D13 D14 板子自带LED（和LCD冲突）

***************************/
#endif
