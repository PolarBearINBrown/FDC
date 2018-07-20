#include "pretreat.h"

#define N 4

int Level[8];
int Read[8];
int Ave[8];
float Weight[8];

int Cal[8][10];

void Pretreat_Initial(void)
{
	for(int i=0;i<N;i++)
	{
		Level[i]=Read[i]=Ave[i]=0;
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
	for(int i=0;i<N;i++)
	{
		Min=min(Min,Level[i]);
	}
	for(int i=0;i<N;i++)
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
		delay_ms(10);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<9;j++)
		{
			for(int k=j;k<10;k++)
			{
				if(Cal[i][j]>Cal[i][k])
				{
					int Tmp=Cal[i][j];
					Cal[i][j]=Cal[i][k];
					Cal[i][k]=Tmp;
				}
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		Ave[i]=Cal[i][7]*Weight[i];
	}
}
