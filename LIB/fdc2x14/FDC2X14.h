#ifndef __FDC2X14_H
#define __FDC2X14_H

#include "sys.h"								  

extern int Error[8];

extern void FDC2X14_Init(void);
extern int FDC_ClearCH(u8 index);
extern int FDC_GetCH(u8 index);
//extern void Get_Error(void);

#endif	   
















