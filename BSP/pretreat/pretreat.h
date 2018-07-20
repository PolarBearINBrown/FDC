#ifndef _PRETREAT_H_
#define _PRETREAT_H_

#include "FDC2X14.h"
#include "headers.h"
#include "lcd.h"

extern int Level0,Level1,Level2,Level3,Level4,Level5,Level6,Level7;
extern int Read0,Read1,Read2,Read3,Read4,Read5,Read6,Read7;

extern void Pretreat_Initial(void);
extern void Get_Level(void);
extern void Get_Read(void);

#endif
