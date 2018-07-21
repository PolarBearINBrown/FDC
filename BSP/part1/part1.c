#include "part1.h"

int Stone,Scissors,Cloth;

void Get_Base(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Clear the platform.");
	ShowString(3,3,"Press OK when done");
	while(1)
	{
		int Tmp=Get_Key();
		if(Tmp==Ok)
		{
			break;
		}
		delay_ms(10);
	}
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Please wait...");
	Get_Error();
	for(int i=0;i<9;i++)
	{
		Get_AverageCH();
	}
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Put the hand open on the");
	ShowString(3,1,"platform.");
	ShowString(4,3,"Press OK when the value");
	ShowString(5,1,"is stable.");
	while(1)
	{
		Get_Level();
		int Tmp=Get_Key();
		if(Tmp==Ok)
		{
			Get_Weight();
			break;
		}
	}
}

void Get_Stone(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Put the hand as a stone");
	ShowString(3,1,"on the platform.");
	while(1)
	{
		Get_AverageCH();
		if(Ave[0]>Level[0]>>1)
		{
			break;
		}
	}
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Please wait...");
	delay_ms(1000);
	for(int i=0;i<20;i++)
	{
		Get_AverageCH();
	}
	Stone=Get_AverageCH();
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Leave hand.");
	ShowNum(3,3,Stone);
	while(1)
	{
		Get_AverageCH();
		if(Ave[0]<Level[0]>>1)
		{
			break;
		}
	}
}

void Get_Scissors(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Put the hand as a scissors");
	ShowString(3,1,"on the platform.");
	while(1)
	{
		Get_AverageCH();
		if(Ave[0]>Level[0]>>1)
		{
			break;
		}
	}
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Please wait...");
	delay_ms(1000);
	for(int i=0;i<20;i++)
	{
		Get_AverageCH();
	}
	Scissors=Get_AverageCH();
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Leave hand.");
	ShowNum(3,3,Scissors);
	while(1)
	{
		Get_AverageCH();
		if(Ave[0]<Level[0]>>1)
		{
			break;
		}
	}
}

void Get_Cloth(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Put the hand as a cloth");
	ShowString(3,1,"on the platform.");
	while(1)
	{
		Get_AverageCH();
		if(Ave[0]>Level[0]>>1)
		{
			break;
		}
	}
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Please wait...");
	delay_ms(1000);
	for(int i=0;i<20;i++)
	{
		Get_AverageCH();
	}
	Cloth=Get_AverageCH();
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Leave hand.");
	ShowNum(3,3,Cloth);
	while(1)
	{
		Get_AverageCH();
		if(Ave[0]<Level[0]>>1)
		{
			break;
		}
	}
}

void P1_Main_Win(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Press OK when ready to");
	ShowString(3,1,"check.");
	while(1)
	{
		int Tmp=Get_Key();
		if(Tmp==Ok)
		{
			break;
		}
		delay_ms(10);
	}
	Get_Base();

	Get_Stone();
	
	Get_Scissors();
	
	Get_Cloth();
}

void Judge_Gesture(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Gesture is:");
	while(1)
	{
		int Value=Get_AverageCH();
		int Tmp=Get_Key();
		if(Tmp)
		{
			ShowString(3,3,"Key!!");
			Get_Error_Quick();
		}
		if(Ave[0]>Level[0]>>1)
		{
			
			Value=Get_AverageCH();
			if(Value>(Cloth+Scissors)>>1)
			{
				ShowString(3,10,"Cloth   ");
			}
			else if(Value>(Scissors+Stone)>>1)
			{
				ShowString(3,10,"Scissors");
			}
			else
			{
				ShowString(3,10,"Stone   ");
			}
		}
		else
		{
			ShowString(3,10,"             ");
		}
	}
}

void P1_Judge_Win(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"---------Mode_1---------");
	ShowString(2,3,"Press OK when ready to");
	ShowString(3,1,"test.");
	while(1)
	{
		int Tmp=Get_Key();
		if(Tmp==Ok)
		{
			break;
		}
		delay_ms(10);
	}
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<3;j++)
		{
			Queue[i][j]=0;
		}
		Ave[i]=0;
	}
	Judge_Gesture();
}

void Part1_Start(void)
{
	P1_Main_Win();
	P1_Judge_Win();
}
