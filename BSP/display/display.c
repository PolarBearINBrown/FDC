#include "display.h"

void Check_Win(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"------Check Window------");
	ShowString(2,3,"Clear the platform");
	ShowString(3,3,"Press OK when done");
	while(1)
	{
		int Tmp=Get_Key();
		if(Tmp==Ok)
		{
			Get_Error();
			break;
		}
	}
	LCD_Clear(WHITE);
	ShowString(1,1,"------Check Window------");
	ShowString(2,3,"Put the hand open on the");
	ShowString(3,1,"platform.");
	ShowString(4,3,"Press OK when the value");
	ShowString(5,1,"is stable.");
	while(1)
	{
		int Tmp=Get_Key();
		if(Tmp==Ok)
		{
			Get_Weight();
			Get_Level();
			break;
		}
		Get_Level();
	}
	LCD_Clear(WHITE);
	ShowString(1,1,"------Check Window------");
	ShowString(2,3,"Checking Complete");
	ShowString(3,3,"Press OK to return to the");
	ShowString(4,1,"main menu.");
	while(1)
	{
		int Tmp=Get_Key();
		if(Tmp==Ok)
		{
			break;
		}
	}
}

void Main_Win_Initial(int Loc)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"------Main Window------");
	ShowString(2,3,"Set Mode");
	ShowNum(2,15,Mode);
	ShowString(3,3,"Start");
	ShowString(2+Loc,23,"<-");
}

void Main_Win(void)
{
	int Loc=0;
	int Len=2;
	int Tmp=1;
	while(1)
	{
		if(Tmp)
		{
			Main_Win_Initial(Loc);
		}
		Tmp=Get_Key();
		if(Tmp==Up)
		{
			Loc+=Len-1;
			Loc%=Len;
		}
		else if(Tmp==Down)
		{
			Loc++;
			Loc%=Len;
		}
		else if(Tmp==Left)
		{
			if(Loc==0)
			{
				Mode=max(0,Mode-1);
			}
		}
		else if(Tmp==Right)
		{
			if(Loc==0)
			{
				Mode=min(Mode_Size,Mode+1);
			}
		}
		else if(Tmp==Ok)
		{
			if(Loc==1)
			{
				LCD_Clear(WHITE);
				break;
			}
		}
	}
}
