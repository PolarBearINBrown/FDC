#include "headers.h"
#include "myiic.h"
#include "myiic2.h"
#include "FDC2X14.h"
#include "pretreat.h"
#include "display.h"

int min(int a,int b)
{
	return a>b? b:a;
}

int max(int a,int b)
{
	return a>b? a:b;
}

int abs(int a)
{
	if(a<0)
	{
		return -a;
	}
	else
	{
		return a;
	}
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
	IIC2_Init();
	FDC2X14_Init();
	LCD_Init();
	Key_Initial();
	
}

int main()
{
	System_Initial();
	POINT_COLOR=BLACK;
	int Tmp=0;
	while(1)
	{
		Main_Win();
		while(1)
		{
			Tmp=Get_Key();
			if(Tmp)
			{
				Get_Error();
			}
			Get_Read();
			ShowNum(1,3,Read0);
			ShowNum(2,3,Read1);
			ShowNum(3,3,Read2);
			ShowNum(4,3,Read3);
			ShowNum(5,3,Read4);
			ShowNum(6,3,Read5);
			ShowNum(7,3,Read6);
			ShowNum(8,3,Read7);
		}
	}
}
