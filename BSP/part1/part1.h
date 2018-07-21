#ifndef _PART1_H_
#define _PART1_H_

#include "headers.h"
#include "lcd.h"
#include "pretreat.h"
#include "key.h"

extern int Stone,Scissors,Cloth;

extern void Part1_Start(void);
extern void Judge_Gesture(void);
extern void Get_Cloth(void);
extern void Get_Scissors(void);
extern void Get_Stone(void);
extern void Get_Base(void);

#endif
