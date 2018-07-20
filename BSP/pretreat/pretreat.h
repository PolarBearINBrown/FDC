#ifndef _PRETREAT_H_
#define _PRETREAT_H_

#include "FDC2X14.h"
#include "headers.h"
#include "lcd.h"

extern int Level[8];
extern int Read[8];
extern int Ave[8];

extern void Pretreat_Initial(void);
extern void Get_Level(void);
extern void Get_Read(void);
extern void Get_AverageCH(void);
extern void Get_Weight(void);

#endif
