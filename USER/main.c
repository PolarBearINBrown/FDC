#include "headers.h"
#include "led.h"
#include "myiic.h"
#include "FDC2X14.h"
#include "pretreat.h"
#include "pid.h"
#include "motor.h"
#include "display.h"

int min(int a,int b)
{
	return a>b? b:a;
}

int max(int a,int b)
{
	return a>b? a:b;
}

int Mode;
int Mode_Size;

void System_Initial(void)
{
	Mode=0;
	Mode_Size=5;
	delay_init();
	uart_init(115200);
	IIC_Init();
	FDC2X14_Init();
	LED_Initial();
	PID_Initial();
	Motor_Initial();
	LCD_Init();
	Key_Initial();
}

int main()
{
	System_Initial();
	POINT_COLOR=BLACK;
	Main_Win();
	ShowString(1,1,"Key=0");
	while(1)
	{
		int Tmp=Get_Key();
		if(Tmp)
		{
			ShowNum(1,5,Tmp);
		}
	}
}
