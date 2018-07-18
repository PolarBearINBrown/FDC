#include "key.h"

void Key_Initial(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

int Get_Key(void)
{
	if(K_U)
	{
		delay_ms(10);
		if(K_U)
		{
			while(K_U)
			{
				delay_ms(50);
			}
			return Up;
		}
	}
	else if(K_D)
	{
		delay_ms(10);
		if(K_D)
		{
			while(K_D)
			{
				delay_ms(50);
			}
			return Down;
		}
	}
	else if(K_L)
	{
		delay_ms(10);
		if(K_L)
		{
			while(K_L)
			{
				delay_ms(50);
			}
			return Left;
		}
	}
	else if(K_R)
	{
		delay_ms(10);
		if(K_R)
		{
			while(K_R)
			{
				delay_ms(50);
			}
			return Right;
		}
	}
	else if(K_O)
	{
		delay_ms(10);
		if(K_O)
		{
			while(K_O)
			{
				delay_ms(50);
			}
			return Ok;
		}
	}
	return 0;
}
