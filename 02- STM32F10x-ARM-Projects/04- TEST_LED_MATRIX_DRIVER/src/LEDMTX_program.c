/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V01  												*/
/*	Date	 : 29 September 2023                                    */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMTX_interface.h"
#include "LEDMTX_private.h"
#include "LEDMTX_config.h"


void HLEDMTX_voidInit (void)
{
	
	/* Initialize Rows */
	MGPIO_voidSetPinDirection (LEDMTX_ROW0_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_ROW1_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_ROW2_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_ROW3_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_ROW4_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_ROW5_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_ROW6_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_ROW7_PIN , LEDMTX_PINS_SPEED) ;

	/* Initialize Columns */
	MGPIO_voidSetPinDirection (LEDMTX_COL0_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_COL1_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_COL2_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_COL3_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_COL4_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_COL5_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_COL6_PIN , LEDMTX_PINS_SPEED) ;
	MGPIO_voidSetPinDirection (LEDMTX_COL7_PIN , LEDMTX_PINS_SPEED) ;
}


void HLEDMTX_voidShiftDisplay (u8 * Copy_u8Data,u8 Copy_u8DataLength,u8 Copy_u8ShiftDelay)
{
	u8 i = 0 ;

	while(1)
	{
	   for(u8 j = 0 ; j <= Copy_u8ShiftDelay ; j++)
	   {
	     // Enable column 0 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[0+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL0_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);

	     // Enable column 1 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[1+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL1_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);

	     // Enable column 2 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[2+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL2_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);

	     // Enable column 3 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[3+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL3_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);

	     // Enable column 4 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[4+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL4_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);

	     // Enable column 5 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[5+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL5_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);

	     // Enable column 6 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[6+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL6_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);

	     // Enable column 7 //
	     // Disable all columns //
	     DisableAllCols();
	     SetRowValues(Copy_u8Data[7+i]);
	     MGPIO_voidSetPinValue (LEDMTX_COL7_PIN , GPIO_LOW) ;
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
	     MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);
	   }
	  i=i+1;
	  if(i > Copy_u8DataLength-8)
	  {
		  i = 0 ;
	  }
	}
}









void DisableAllCols (void)
{
	MGPIO_voidSetPinValue (LEDMTX_COL0_PIN , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (LEDMTX_COL1_PIN , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (LEDMTX_COL2_PIN , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (LEDMTX_COL3_PIN , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (LEDMTX_COL4_PIN , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (LEDMTX_COL5_PIN , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (LEDMTX_COL6_PIN , GPIO_HIGH) ;
	MGPIO_voidSetPinValue (LEDMTX_COL7_PIN , GPIO_HIGH) ;
}

void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 0);
	MGPIO_voidSetPinValue (LEDMTX_ROW0_PIN , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 1);
	MGPIO_voidSetPinValue (LEDMTX_ROW1_PIN , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 2);
	MGPIO_voidSetPinValue (LEDMTX_ROW2_PIN , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 3);
	MGPIO_voidSetPinValue (LEDMTX_ROW3_PIN , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 4);
	MGPIO_voidSetPinValue (LEDMTX_ROW4_PIN , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 5);
	MGPIO_voidSetPinValue (LEDMTX_ROW5_PIN , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 6);
	MGPIO_voidSetPinValue (LEDMTX_ROW6_PIN , Local_u8Bit) ;

	Local_u8Bit = GET_BIT(Copy_u8Value , 7);
	MGPIO_voidSetPinValue (LEDMTX_ROW7_PIN , Local_u8Bit) ;

}
