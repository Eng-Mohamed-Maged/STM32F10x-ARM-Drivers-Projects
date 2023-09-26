/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 26 September 2023                                             */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "STK_interface.h"
#include  "STK_private.h"
#include  "STK_config.h"

/* Global Section */
static void (*MSTK_CallBack) (void) ;
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	u32 Temp = 0;
	Temp |= (STK_CLOCK_SOURCE        << 2);
	SysTick -> STK_CTRL = Temp ;
}

void  MSTK_voidSetBusyWait (u32 Copy_u32Ticks )
{
	if(Copy_u32Ticks <= 0x00FFFFFF )
	{
		/* Configure STK_LOAD         */
		SysTick -> STK_LOAD = Copy_u32Ticks ;

		/* Start Timer */
		SET_BIT((SysTick -> STK_CTRL) , 0 );

		/* Wait until CTRL flag to be 1 */
		while( (GET_BIT(SysTick->STK_CTRL,16)) == 0);

		/* Stop Timer */
		CLR_BIT(SysTick->STK_CTRL, 0);
		SysTick ->STK_LOAD = 0;
		SysTick ->STK_VAL = 0;
	}
	else
	{
		u32 Copy_RemainigTicks = Copy_u32Ticks - 0x00FFFFFF ;

		/* Configure STK_LOAD         */
		SysTick -> STK_LOAD = 0x00FFFFFF ;	

		/* Start Timer */
		SET_BIT((SysTick -> STK_CTRL) , 0 );

		/* Wait until CTRL flag to be 1 */
		while( (GET_BIT(SysTick->STK_CTRL,16)) == 0);

		/* Stop Timer */
		SysTick ->STK_LOAD = 0;
		SysTick ->STK_VAL = 0;

		/*********** Remaining *************/
		MSTK_voidSetBusyWait (Copy_RemainigTicks) ;
		
	}
	
}

void   MSTK_voidSetIntervalSingle  (u32 Copy_u32Ticks , void (*Copy_ptr) (void))
{

	    /* Load ticks to load register */
	    SysTick -> STK_LOAD = Copy_u32Ticks;

		/* Start Timer */
		SET_BIT(SysTick -> STK_CTRL, 0);

		/* Save CallBack */
		MSTK_CallBack = Copy_ptr;

		/* Set Mode to Single */
		MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;

		/* Enable STK Interrupt */
		SET_BIT(SysTick -> STK_CTRL, 1);


}


void   MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr) (void))
{
	/* Load ticks to load register */
	SysTick -> STK_LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(SysTick -> STK_CTRL, 0);

	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(SysTick -> STK_CTRL, 1);

}

void   MSTK_voidStopInterval (void)
{
	/* Disable Interrupt  */
	CLR_BIT((SysTick -> STK_CTRL) , 1 );

	/* Stop Timer */
	CLR_BIT(SysTick->STK_CTRL, 0);
	SysTick ->STK_LOAD = 0;
	SysTick ->STK_VAL = 0;

}


u32    MSTK_u32GetElapsedTime  (void) 
{
	u32 Local_u32ElapsedTime ;
	Local_u32ElapsedTime = (SysTick -> STK_LOAD) - (SysTick -> STK_VAL) ;
	return Local_u32ElapsedTime ;
}



u32    MSTK_u32GetRemainingTime (void) 
{
	u32 Local_u32RemainingTime ;
	Local_u32RemainingTime = (SysTick -> STK_VAL) ;
	return Local_u32RemainingTime ;
}


void SysTick_Handler (void)
{
	u8 Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(SysTick -> STK_CTRL, 1);

		/* Stop Timer */
		CLR_BIT(SysTick -> STK_CTRL, 0);
		SysTick -> STK_LOAD = 0;
		SysTick -> STK_VAL  = 0;
	}

	/* Callback notification */
	MSTK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(SysTick -> STK_CTRL,16);

}




