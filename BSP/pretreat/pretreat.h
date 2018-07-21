#ifndef _PRETREAT_H_
#define _PRETREAT_H_

#include "FDC2X14.h"
#include "headers.h"
#include "lcd.h"
#include "stdlib.h"

extern int Ave[8];
extern int Level[8];
extern float Queue[8][3];

extern void Pretreat_Initial(void);
extern void Get_Level(void);
extern void Get_Read(void);
extern void Get_Weight(void);
extern void Get_Error(void);
extern void Get_Error_Quick(void);

extern int Get_AverageCH(void);
extern int Get_ClearAverageCH(void);

#endif
