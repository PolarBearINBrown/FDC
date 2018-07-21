#include "pretreat.h"

#define N 8

int Level[8];
int Read[8];
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
		Level[i]=Read[i]=Ave[i]=Queue[i][0]=Queue[i][1]=Queue[i][2]=0;
		Weight[i]=1;
	}
}

void Get_Level(void)
{
	Get_AverageCH();
	for(int i=0;i<N;i++)
	{
		Level[i]=max(Ave[i],Level[i]);
		ShowNum(5+i,3,Level[i]);
	}
}

void Get_Weight(void)
{
	int Min=INT32_MAX;
	for(int i=2;i<N;i++)
	{
		Min=min(Min,Level[i]);
	}
	for(int i=1;i<N;i++)
	{
		Weight[i]=(float)Min/Level[i];
	}
}

void Get_AverageCH(void)
{
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
	}
}
