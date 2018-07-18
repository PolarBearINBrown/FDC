#ifndef _KEY_H_
#define _KEY_H_

#include "headers.h"

#define K_U GPIOE->IDR&GPIO_IDR_IDR2
#define K_D GPIOE->IDR&GPIO_IDR_IDR6
#define K_L GPIOE->IDR&GPIO_IDR_IDR3
#define K_R GPIOE->IDR&GPIO_IDR_IDR5
#define K_O GPIOE->IDR&GPIO_IDR_IDR4

#define Up    1
#define Down  2
#define Left  3
#define Right 4
#define Ok    5

extern void Key_Initial(void);
extern int Get_Key(void);

#endif
