#include "headers.h"
#include "myiic.h"
#include "myiic2.h"
#include "FDC2X14.h"
#include "pretreat.h"
#include "display.h"
#include "DataScope_DP.h"

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
	uart_init(128000);
	IIC_Init();
	IIC2_Init();
	FDC2X14_Init();
	LCD_Init();
	Key_Initial();
	Pretreat_Initial();
}

void DataScope(void)
{
	int Sum=0;
  for(int i=1;i<8;i++)
	{
		DataScope_Get_Channel_Data(Ave[i],i+1);
		Sum+=Ave[i];
	}
	DataScope_Get_Channel_Data(Sum,1);
	int Send_Count = DataScope_Data_Generate(8);
	for(int i=0;i<Send_Count;i++) 
	{
		while((USART1->SR&0X40)==0);  
		USART1->DR = DataScope_OutPut_Buffer[i]; 
	}
}

int main()
{
	System_Initial();
	int Tmp=1;
	while(1)
	{
		Main_Win();
		Get_Error();
		while(1)
		{
			if(Tmp==Ok)
			{
				Pretreat_Initial();
				break;
			}
			else if(Tmp)
			{
				Get_Error();
			}
			Tmp=Get_Key();
			Get_AverageCH();
			DataScope();
		}
	}
}
