/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 23 September  2023                                            */
/*   Logs      : V01 : Testing [GPIO-RCC] Drivers                              */
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

void main (void)
{
	/* Initialize system clock */
	RCC_voidInitSysClock();
	/* Enable GPIOA Peripheral */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOA);
	/* Enable GPIOB Peripheral */
//	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOB);
	/* Enable GPIOC Peripheral */
//	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOC);

	/* Configure Port Mode for GPIO_PORT_A */
		MGPIO_voidSetPortDirection(GPIOA,OUTPUT_PORT_SPEED_50MHZ_PP);

	while(1)
	{
		/*  Configure Port Value for GPIO_PORT_A as [HIGH] */
		MGPIO_voidSetPortValue(GPIOA,GPIO_PORT_HIGH);

		/* NON-professional Delay before implementing [Systick Driver] */
		for(u16 i=0 ; i<1000 ; i++)
		{
			for(u16 y=0 ; y <500 ; y++)
			{

			}
		}

		/*  Configure Port Value for GPIO_PORT_A as [HIGH] */
		MGPIO_voidSetPortValue(GPIOA,GPIO_PORT_LOW);


		/* NON-professional Delay before implementing [Systick Driver] */
		for(u16 i=0 ; i<1000 ; i++)
		{
			for(u16 y=0 ; y <500 ; y++)
			{

			}
		}
	}
}

