#include "headers.h"
#include "led.h"
#include "myiic.h"
#include "FDC2X14.h"
#include "pretreat.h"
#include "pid.h"
#include "motor.h"
#include "lcd.h"
#include "key.h"

void System_Initial(void)
{
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
	ShowString(1,1,"Key=");
	while(1)
	{
		ShowNum(1,5,Get_Key());
	}
}
