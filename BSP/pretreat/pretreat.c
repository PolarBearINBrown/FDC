#include "pretreat.h"

int Level0,Level1,Level2,Level3,Level4,Level5,Level6,Level7;
int Read0,Read1,Read2,Read3,Read4,Read5,Read6,Read7;

void Pretreat_Initial(void)
{
	Level0=0;
	Level1=0;
	Level2=0;
	Level3=0;
	Level4=0;
	Level5=0;
	Level6=0;
	Level7=0;
	Read0=0;
	Read1=0;
	Read2=0;
	Read3=0;
	Read4=0;
	Read5=0;
	Read6=0;
	Read7=0;
}

void Get_Level(void)
{
	Level0=max(FDC_GetCH(0),Level0);
	ShowNum(5,3,Level0);
	Level1=max(FDC_GetCH(1),Level1);
	ShowNum(6,3,Level1);
	Level2=max(FDC_GetCH(2),Level2);
	ShowNum(7,3,Level2);
	Level3=max(FDC_GetCH(3),Level3);
	ShowNum(8,3,Level3);
	Level4=max(FDC_GetCH(4),Level4);
	ShowNum(9,3,Level4);
	Level5=max(FDC_GetCH(5),Level5);
	ShowNum(10,3,Level5);
	Level6=max(FDC_GetCH(6),Level6);
	ShowNum(11,3,Level6);
	Level7=max(FDC_GetCH(7),Level7);
	ShowNum(12,3,Level7);
}

void Get_Read(void)
{
	Read0=FDC_GetCH(0)>Level0>>1;
	Read1=FDC_GetCH(1)>Level1>>1;
	Read2=FDC_GetCH(2)>Level2>>1;
	Read3=FDC_GetCH(3)>Level3>>1;
	Read4=FDC_GetCH(4)>Level4>>1;
	Read5=FDC_GetCH(5)>Level5>>1;
	Read6=FDC_GetCH(6)>Level6>>1;
	Read7=FDC_GetCH(7)>Level7>>1;
}
