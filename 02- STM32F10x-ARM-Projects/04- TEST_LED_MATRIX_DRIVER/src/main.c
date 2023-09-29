/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V01  												*/
/*	Date	 : 31 Aug 2020                                          */
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMTX_interface.h"

/* ESLAM   MAgED */
//u8 LED_DataArray[] = {0, 0, 126, 82, 82, 82, 0, 0, 0, 94, 82, 82, 114, 0, 0, 0, 0, 0, 126, 64, 64, 64, 0, 0, 0, 124, 18, 18, 18, 124, 0, 0, 126, 2, 4, 8, 4, 2, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 28, 62, 126, 252, 126, 62, 28, 0, 126, 2, 4, 4, 2, 126, 0, 0, 0, 124, 18, 18, 124, 0, 0, 0, 0, 110, 74, 126, 0, 0, 0, 0, 0, 126, 90, 90, 90, 0, 0, 0, 0, 126, 66, 66, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/* ❤ Hello ❤ Nada */
u8 LED_DataArray[] = {0, 28, 62, 126, 252, 126, 62, 28, 0, 0, 126, 8, 8, 126, 0, 126, 82, 82, 0, 126, 64, 64, 0, 126, 64, 64, 0, 126, 66, 66, 126, 0, 28, 62, 126, 252, 126, 62, 28, 0, 0, 126, 4, 24, 32, 126, 0, 124, 18, 18, 124, 0, 126, 66, 60, 0, 124, 18, 18, 124,0,0};
/* Heart */
//u8 LED_DataArray[] = {0, 28, 62, 126, 252, 126, 62, 28};
/* Man */
//u8 LED_DataArray[] = {8, 16, 215, 125, 125, 215, 16, 8};

void main (void)
{
	/* Calculate the array size */
	u8 Array_Length = sizeof(LED_DataArray) / sizeof(LED_DataArray[0]);
	/* RCC Initialization */
	RCC_voidInitSysClock();
	/* Enable GPIOA - GPIOB */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOA);
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOB);

	/* SysTick Init */
	MSTK_voidInit();

	/* LED Matrix Init */
	HLEDMTX_voidInit();


	while(1)
	{
		/* Display Data on LED Matrix with [Shift_Delay = 7] */
		HLEDMTX_voidShiftDisplay(LED_DataArray,Array_Length,7);

	}

}
