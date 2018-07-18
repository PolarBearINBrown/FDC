#include "display.h"

void Set_P_Win_Initial(int Loc)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"P = ");
	ShowNum(1,5,Proportion);
	ShowString(2,3,"x1");
	ShowString(3,3,"x10");
	ShowString(4,3,"x100");
	ShowString(5,3,"x1000");
	ShowString(6,3,"x10000");
	ShowString(2+Loc,23,"<-");
}

void Set_P_Win(void)
{
	int Loc=0;
	int Len=5;
	int Tmp=1;
	while(1)
	{
		if(Tmp)
		{
			Set_P_Win_Initial(Loc);
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
				Proportion-=1;
			}
			else if(Loc==1)
			{
				Proportion-=10;
			}
			else if(Loc==2)
			{
				Proportion-=100;
			}
			else if(Loc==3)
			{
				Proportion-=1000;
			}
			else if(Loc==4)
			{
				Proportion-=10000;
			}
		}
		else if(Tmp==Right)
		{
			if(Loc==0)
			{
				Proportion+=1;
			}
			else if(Loc==1)
			{
				Proportion+=10;
			}
			else if(Loc==2)
			{
				Proportion+=100;
			}
			else if(Loc==3)
			{
				Proportion+=1000;
			}
			else if(Loc==4)
			{
				Proportion+=10000;
			}
		}
		else if(Tmp==Ok)
		{
			LCD_Clear(WHITE);
			break;
		}
	}
}

void Set_I_Win_Initial(int Loc)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"I = ");
	ShowNum(1,5,Integral);
	ShowString(2,3,"x1");
	ShowString(3,3,"x10");
	ShowString(4,3,"x100");
	ShowString(5,3,"x1000");
	ShowString(6,3,"x10000");
	ShowString(2+Loc,23,"<-");
}

void Set_I_Win(void)
{
	int Loc=0;
	int Len=5;
	int Tmp=1;
	while(1)
	{
		if(Tmp)
		{
			Set_I_Win_Initial(Loc);
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
				Integral-=1;
			}
			else if(Loc==1)
			{
				Integral-=10;
			}
			else if(Loc==2)
			{
				Integral-=100;
			}
			else if(Loc==3)
			{
				Integral-=1000;
			}
			else if(Loc==4)
			{
				Integral-=10000;
			}
		}
		else if(Tmp==Right)
		{
			if(Loc==0)
			{
				Integral+=1;
			}
			else if(Loc==1)
			{
				Integral+=10;
			}
			else if(Loc==2)
			{
				Integral+=100;
			}
			else if(Loc==3)
			{
				Integral+=1000;
			}
			else if(Loc==4)
			{
				Integral+=10000;
			}
		}
		else if(Tmp==Ok)
		{
			LCD_Clear(WHITE);
			break;
		}
	}
}

void Set_D_Win_Initial(int Loc)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"D = ");
	ShowNum(1,5,Derivative);
	ShowString(2,3,"x1");
	ShowString(3,3,"x10");
	ShowString(4,3,"x100");
	ShowString(5,3,"x1000");
	ShowString(6,3,"x10000");
	ShowString(2+Loc,23,"<-");
}

void Set_D_Win(void)
{
	int Loc=0;
	int Len=5;
	int Tmp=1;
	while(1)
	{
		if(Tmp)
		{
			Set_D_Win_Initial(Loc);
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
				Derivative-=1;
			}
			else if(Loc==1)
			{
				Derivative-=10;
			}
			else if(Loc==2)
			{
				Derivative-=100;
			}
			else if(Loc==3)
			{
				Derivative-=1000;
			}
			else if(Loc==4)
			{
				Derivative-=10000;
			}
		}
		else if(Tmp==Right)
		{
			if(Loc==0)
			{
				Derivative+=1;
			}
			else if(Loc==1)
			{
				Derivative+=10;
			}
			else if(Loc==2)
			{
				Derivative+=100;
			}
			else if(Loc==3)
			{
				Derivative+=1000;
			}
			else if(Loc==4)
			{
				Derivative+=10000;
			}
		}
		else if(Tmp==Ok)
		{
			LCD_Clear(WHITE);
			break;
		}
	}
}

void Set_L_Win_Initial(int Loc)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"L = ");
	ShowNum(1,5,Limit);
	ShowString(2,3,"x1");
	ShowString(3,3,"x10");
	ShowString(4,3,"x100");
	ShowString(5,3,"x1000");
	ShowString(6,3,"x10000");
	ShowString(2+Loc,23,"<-");
}

void Set_L_Win(void)
{
	int Loc=0;
	int Len=5;
	int Tmp=1;
	while(1)
	{
		if(Tmp)
		{
			Set_L_Win_Initial(Loc);
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
				Limit-=1;
			}
			else if(Loc==1)
			{
				Limit-=10;
			}
			else if(Loc==2)
			{
				Limit-=100;
			}
			else if(Loc==3)
			{
				Limit-=1000;
			}
			else if(Loc==4)
			{
				Limit-=10000;
			}
		}
		else if(Tmp==Right)
		{
			if(Loc==0)
			{
				Limit+=1;
			}
			else if(Loc==1)
			{
				Limit+=10;
			}
			else if(Loc==2)
			{
				Limit+=100;
			}
			else if(Loc==3)
			{
				Limit+=1000;
			}
			else if(Loc==4)
			{
				Limit+=10000;
			}
		}
		else if(Tmp==Ok)
		{
			LCD_Clear(WHITE);
			break;
		}
	}
}

void Set_PID_Win_Initial(int Loc)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"Set PID Windows");
	ShowString(2,3,"Set Proportion");
	ShowString(3,3,"Set Integral");
	ShowString(4,3,"Set Derivative");
	ShowString(5,3,"Set Limit");
	ShowString(6,3,"OK!");
	ShowString(2+Loc,23,"<-");
}

void Set_PID_Win(void)
{
	int Loc=0;
	int Len=5;
	int Tmp=1;
	while(1)
	{
		if(Tmp)
		{
			Set_PID_Win_Initial(Loc);
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
		else if(Tmp==Ok)
		{
			if(Loc==0)
			{
				Set_P_Win();
			}
			else if(Loc==1)
			{
				Set_I_Win();
			}
			else if(Loc==2)
			{
				Set_D_Win();
			}
			else if(Loc==3)
			{
				Set_L_Win();
			}
			else if(Loc==4)
			{
				LCD_Clear(WHITE);
				break;
			}
		}
	}
}

void Get_PID_Win(void)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"Get PID Windows");
	ShowString(2,3,"P = ");
	ShowNum(2,8,Proportion);
	ShowString(3,3,"I = ");
	ShowNum(3,8,Integral);
	ShowString(4,3,"I = ");
	ShowNum(4,8,Derivative);
	while(1)
	{
		if(Get_Key()==Ok)
		{
			break;
		}
	}
}

void Main_Win_Initial(int Loc)
{
	LCD_Clear(WHITE);
	ShowString(1,1,"Main Window");
	ShowString(2,3,"Get PID");
	ShowString(3,3,"Set PID");
	ShowString(4,3,"Set Mode");
	ShowNum(4,15,Mode);
	ShowString(5,3,"Start");
	ShowString(2+Loc,23,"<-");
}

void Main_Win(void)
{
	int Loc=0;
	int Len=4;
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
			if(Loc==2)
			{
				Mode=max(0,Mode-1);
			}
		}
		else if(Tmp==Right)
		{
			if(Loc==2)
			{
				Mode=min(Mode_Size,Mode+1);
			}
		}
		else if(Tmp==Ok)
		{
			if(Loc==0)
			{
				Get_PID_Win();
			}
			else if(Loc==1)
			{
				Set_PID_Win();
			}
			else if(Loc==3)
			{
				LCD_Clear(WHITE);
				break;
			}
		}
	}
}
