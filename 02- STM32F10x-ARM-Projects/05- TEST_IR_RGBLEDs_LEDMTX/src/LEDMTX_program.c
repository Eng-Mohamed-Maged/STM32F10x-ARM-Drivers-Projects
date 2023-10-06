/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V02  												*/
/*	Date	 : 6 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/*             V02 : Update the whole Driver                        */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*************************************************************************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*************************************************************************/
#include "LEDMTX_interface.h"
#include "LEDMTX_private.h"
#include  "LEDMTX_config.h"
/*************************************************************************/
#if LEDMTX_WHILE_BREAK == ENABLE
extern u8 u8LED_MATRIX_ON_OFF_STATE;
#endif
/*************************************************************************/
/* Two Arrays for row and coloumns */
/* Number of rows or columns is multiple by 2 for holding [PORT],[PIN] */
u8 LEDMRX_globalRows[(LEDMTX_ROW_NUMBER * 2 )] =
{LEDMTX_ROW0_PIN,LEDMTX_ROW1_PIN,LEDMTX_ROW2_PIN,LEDMTX_ROW3_PIN,LEDMTX_ROW4_PIN,LEDMTX_ROW5_PIN,LEDMTX_ROW6_PIN,LEDMTX_ROW7_PIN};
/*************************************************************************/
u8 LEDMRX_globalColoumns[(LEDMTX_COLOUMNS_NUMBER*2)] =
{LEDMTX_COL0_PIN,LEDMTX_COL1_PIN,LEDMTX_COL2_PIN,LEDMTX_COL3_PIN,LEDMTX_COL4_PIN,LEDMTX_COL5_PIN,LEDMTX_COL6_PIN,LEDMTX_COL7_PIN};
/*************************************************************************/
/********************************************************************/
/* Function Name :  HLEDMTX_voidInit                                */
/* Inputs        :  NONE                                            */
/* Outputs       :  NONE                                            */
/* Descreiption  :  Intialization of Pins [Rows - Columns]          */
/********************************************************************/
void HLEDMTX_voidInit (void)
{
	/* Initialize Rows */
	for(u8 i = 0 ; i < (LEDMTX_ROW_NUMBER * 2) ; i += 2 )
	{
		MGPIO_voidSetPinDirection (LEDMRX_globalRows[i],LEDMRX_globalRows[i+1],LEDMTX_PINS_SPEED) ;
	}
		
	/* Initialize Columns */
	for(u8 i = 0 ; i < (LEDMTX_COLOUMNS_NUMBER * 2) ; i += 2 )
	{
		MGPIO_voidSetPinDirection (LEDMRX_globalColoumns[i],LEDMRX_globalColoumns[i+1],LEDMTX_PINS_SPEED) ;
		MGPIO_voidSetOrResetPinValue_BSRR_BRR(LEDMRX_globalColoumns[i],LEDMRX_globalColoumns[i+1],!(LEDMTX_COLOUMN_VOLTAGE));
	}

}
/*************************************************************************/
/********************************************************************/
/* Function Name :  HLEDMTX_voidDisplay                             */
/* Inputs        :  LED MATRIX [DATA]                               */
/* Outputs       :  NONE                                            */
/* Descreiption  :  Display a static figure                         */
/********************************************************************/
void HLEDMTX_voidDisplay (u8 *copy_u8Data)
{
	for(u8 i = 0 ; i < (LEDMTX_COLOUMNS_NUMBER * 2) ; i += 2 )
	{
		/* Activate a coloumn */
		MGPIO_voidSetOrResetPinValue_BSRR_BRR(LEDMRX_globalColoumns[i],LEDMRX_globalColoumns[i+1],LEDMTX_COLOUMN_VOLTAGE);
		/* Write to the rows */
		SetRowValues(copy_u8Data[(i/2)]);
	     // Set Delay 2.5ms as we want 50 Frame so 8*50=400 > 1/400 = 2.5ms //
		MSTK_voidSetBusyWait(LED_MTX_DELAY_IN_US,TIME_US);
		/* Deactivate a coloumn */
		MGPIO_voidSetOrResetPinValue_BSRR_BRR(LEDMRX_globalColoumns[i],LEDMRX_globalColoumns[i+1],!(LEDMTX_COLOUMN_VOLTAGE));
	}										  
}
/*************************************************************************/
/********************************************************************/
/* Function Name :  HLEDMTX_voidShiftDisplay                        */
/* Inputs        :  LED MATRIX [DATA] - DATA Length - Delay         */
/* Outputs       :  NONE                                            */
/* Descreiption  :  Display a dynamic figure with shifting          */
/********************************************************************/
void HLEDMTX_voidShiftDisplay (u8 * Copy_u8Data,u8 Copy_u8DataLength,u16 Copy_u16ShiftDelay)
{
	/* To aliasing avoidance */
	Copy_u8DataLength = Copy_u8DataLength - 7 ;

	/* Calculate how much time to loop in while */
	Copy_u16ShiftDelay = Copy_u16ShiftDelay / 10;
	/* Hold the time to update it after every shift */
	u16 Local_u16Hold = Copy_u16ShiftDelay  ;
	
	/* Looping through the text */
#if LEDMTX_WHILE_BREAK == ENABLE
	while((Copy_u8DataLength--) )
#elif
	while(Copy_u8DataLength--)
#endif
	{
		/* making delay between shifts */
	#if LEDMTX_WHILE_BREAK == ENABLE
		while((Copy_u16ShiftDelay--) && (u8LED_MATRIX_ON_OFF_STATE == 1) )
	#elif
		while (Copy_u16ShiftDelay--)
	#endif
		{
			HLEDMTX_voidDisplay(Copy_u8Data);
		}
		Copy_u8Data++;
		Copy_u16ShiftDelay = Local_u16Hold;
	}
}
/*************************************************************************/
/*********************************************************************/
/* Function Name : SetRowValues                                      */
/* Inputs        : LED MATRIX [DATA]                                 */
/* Outputs       : NONE                                              */
/* Descreiption  : Set Rows Value corresponding to LED MATRIX [DATA] */
/*********************************************************************/
static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit ;
	for(u8 i = 0 ; i < (LEDMTX_ROW_NUMBER * 2) ; i += 2 )
	{
		Local_u8Bit = GET_BIT(Copy_u8Value , i/2);
		MGPIO_voidSetOrResetPinValue_BSRR_BRR(LEDMRX_globalRows[i],LEDMRX_globalRows[i+1],Local_u8Bit) ;
	}

}
/*************************************************************************/
