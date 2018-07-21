#include "pretreat.h"

#define N 8

int Level[8];
int Ave[8];
float Weight[8];

int Cal[8][10];
float Queue[8][3];

int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

void Pretreat_Initial(void)
{
	for(int i=0;i<N;i++)
	{
		Level[i]=Ave[i]=Queue[i][0]=Queue[i][1]=Queue[i][2]=0;
		Weight[i]=1;
	}
}

void Get_Level(void)
{
	Get_AverageCH();
	int Sum=0;
	for(int i=0;i<N;i++)
	{
		Level[i]=max(Ave[i],Level[i]);
		//ShowNum(7+i,3,Level[i]);
		Sum+=Level[i];
	}
	ShowNum(6,3,Sum);
}

void Get_Weight(void)
{
	int Min=INT32_MAX;
	for(int i=1;i<N;i++)
	{
		Min=min(Min,Level[i]);
	}
	for(int i=1;i<N;i++)
	{
		Weight[i]=(float)Min/Level[i];
	}
}

int Get_AverageCH(void)
{
	int Sum=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<N;j++)
		{
			Cal[j][i]=FDC_GetCH(j);
		}
		delay_ms(5);
	}
	for(int i=0;i<N;i++)
	{
		qsort(Cal[i],10,4,cmp);
	}
	for(int i=0;i<N;i++)
	{
		Queue[i][0]=Queue[i][1];
		Queue[i][1]=Queue[i][2];
		Queue[i][2]=((float)Cal[i][7]+Cal[i][6]+Cal[i][5])/3;
		Ave[i]=(Queue[i][0]+Queue[i][1]+Queue[i][2])*Weight[i]/3;
		ShowNum(7+i,3,Ave[i]);
		Sum+=Ave[i];
	}
	//ShowNum(10,3,Sum);
	return Sum-Ave[0];
}

int Get_ClearAverageCH(void)
{
	int Sum=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<N;j++)
		{
			Cal[j][i]=FDC_ClearCH(j);
		}
		delay_ms(5);
	}
	for(int i=0;i<N;i++)
	{
		qsort(Cal[i],10,4,cmp);
	}
	for(int i=0;i<N;i++)
	{
		Queue[i][0]=Queue[i][1];
		Queue[i][1]=Queue[i][2];
		Queue[i][2]=((float)Cal[i][7]+Cal[i][6]+Cal[i][5])/3;
		Ave[i]=(Queue[i][0]+Queue[i][1]+Queue[i][2])*Weight[i]/3;
		Sum+=Ave[i];
	}
	return Sum;
}

void Get_Error_Quick(void)
{
	for(int i=0;i<N;i++)
	{
		Error[i]=FDC_ClearCH(i);
	}
}

void Get_Error(void)
{
	for(int i=0;i<10;i++)
	{
		Get_ClearAverageCH();
	}
	for(int i=0;i<N;i++)
	{
		Error[i]=Ave[i];
	}
}
