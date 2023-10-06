/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V03                                                           */
/*   Date      : 2 October 2023                                                */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Updating the driver to be more professional             */
/*               V03 : Errors Fixed                                            */
/*******************************************************************************/
/* Library includes */
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

/* Module includes */
#include  "STK_interface.h"
#include  "STK_private.h"
#include  "STK_config.h"

/* Global Section */
u32 global_u32SystickClk       = 0 ;

/* CallBack Function for SysTick  */
void (*MSTK_CallBack) () ;

/* Mode of interval [Single - Periodic] */
u8 MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;


/*###########################################################################################################*/
/*-----------------------------------------------------------------------------------------------------------*/
/*
  - MSTK_voidInit             : Initialize the SysTick by Choosing the clock source
  - Inputs                    : NONE
  - Outputs                   : NONE
*/
/*-----------------------------------------------------------------------------------------------------------*/
void MSTK_voidInit(void) 
{
	#if 	STK_CLOCK_SOURCE == STK_AHB
		/* Set BIT 0 for AHP CLK  */
		SET_BIT((STK -> CTRL) , MSTK_CTRL_CLKSOURCE);
		/* Systick CLK = AHP_CLK = 8 MHZ means that [1 tick =  0.125 us ] */
		global_u32SystickClk = STK_AHP_CLK ;
		
	#elif 	STK_CLOCK_SOURCE == STK_AHB_BY_8
		/* Clear BIT 0 for AHP/8  CLK  */
		CLR_BIT((STK -> CTRL) , MSTK_CTRL_CLKSOURCE);
		/* Systick CLK = STK_AHB_BY_8 = 8/8 = 1 MHZ means that [1 tick =  1 us ] */
		global_u32SystickClk = STK_AHP_CLK / 8 ;
		
	#else 
		#error (" Configuration error")
	#endif 
}

/*-----------------------------------------------------------------------------------------------------------*/

/*###########################################################################################################*/


/*************************************************************************************************************/
/*
 - MSTK_voidSetBusyWait          : Hold the processor for amount of time in ms or us or seconds
 - Inputs          	             : Copy_u32Time  => Time   
					               Copy_timeUnit => Time Unit in [ms or us or seconds]
 - Outputs                       : NONE
*/
/*************************************************************************************************************/
void   MSTK_voidSetBusyWait (u32 Copy_u32Time , STK_TIME_t Copy_timeUnit)
{
	u32 Local_u32Load = 0 ;
	
	/* For Long Time */
	u32 Local_u32RemainingTime = 0;
	
	/* To clear the current value */
	STK->VAL = 0 ;
	
	/* Calculate and load the load value */
	switch(Copy_timeUnit)
	{
		/*----------------------------------------------------------------------------------*/
		case TIME_S :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk) ;
				/* Check if the target time bigger than [MSTK_MAXIMUM_VALUE = 0x00FFFFFF] */
				if(Local_u32Load > MSTK_MAXIMUM_VALUE)
				{
					STK->LOAD = MSTK_MAXIMUM_VALUE ;
					Local_u32RemainingTime = ((Local_u32Load - MSTK_MAXIMUM_VALUE)/global_u32SystickClk) ;
				}
				else
				{
					STK->LOAD = Local_u32Load ;
				}
				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_MS :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk / 1000) ;
				/* Check if the target time bigger than [MSTK_MAXIMUM_VALUE = 0x00FFFFFF] */
				if(Local_u32Load > MSTK_MAXIMUM_VALUE)
				{
					STK->LOAD = MSTK_MAXIMUM_VALUE ;
					Local_u32RemainingTime = ((Local_u32Load - MSTK_MAXIMUM_VALUE)/(global_u32SystickClk / 1000 )) ;
				}
				else
				{
					STK->LOAD = Local_u32Load ;
				}
				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_US :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk / 1000000) ;
				/* Check if the target time bigger than [MSTK_MAXIMUM_VALUE = 0x00FFFFFF] */
				if(Local_u32Load > MSTK_MAXIMUM_VALUE)
				{
					STK->LOAD = MSTK_MAXIMUM_VALUE ;
					Local_u32RemainingTime = ((Local_u32Load - MSTK_MAXIMUM_VALUE)/(global_u32SystickClk/1000000)) ;
				}
				else
				{
					STK->LOAD = Local_u32Load ;
				}
				break;
		/*----------------------------------------------------------------------------------*/		
		default : 
				break;
		/*----------------------------------------------------------------------------------*/			
	}
	/* Start timer */
	SET_BIT((STK->CTRL) , MSTK_CTRL_ENABLE);
	
	/* Wait until the Counter flag to be 1 */
	while( !(GET_BIT(STK->CTRL,MSTK_CTRL_COUNTFLAG)));

	/* Count the remaining time */
	if(Local_u32RemainingTime != 0)
	{
		MSTK_voidSetBusyWait(Local_u32RemainingTime,Copy_timeUnit);
	}
	
	/* Stop timer */
	CLR_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
}
/*************************************************************************************************************/

/*###########################################################################################################*/

/*-----------------------------------------------------------------------------------------------------------*/
/*
 - MSTK_voidSetIntervalSingle    : Set a Single time in ms or us using ISR
 - Inputs                        : Copy_u32Time  => Time 
					               Copy_timeUnit => Time Unit in [ms or us or seconds]
								   Copy_ptr      => Pointer to function
 - Outputs                       : NONE
*/
/*-----------------------------------------------------------------------------------------------------------*/
void   MSTK_voidSetIntervalSingle (u32 Copy_u32Time ,STK_TIME_t Copy_timeUnit ,void (*Copy_ptr) (void))
{
	u32 Local_u32Load = 0 ;
	
	/* Stop timer */
	CLR_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
	
	/* To clear the current value */
	STK->VAL = 0 ;
	
	/* Calculate and load the load value */
	switch(Copy_timeUnit)
	{
		/*----------------------------------------------------------------------------------*/
		case TIME_S :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk) ;
				STK->LOAD = Local_u32Load ;
				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_MS :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk / 1000) ;
				STK->LOAD = Local_u32Load ;
				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_US :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk / 1000000) ;
				STK->LOAD = Local_u32Load ;
				break;
		/*----------------------------------------------------------------------------------*/		
		default : 
				break;
		/*----------------------------------------------------------------------------------*/			
	}
	
	if(Copy_ptr != NULL)
	{
		/* Save CallBack */
		MSTK_CallBack = Copy_ptr;
	}
	else{}
	
	/* Start timer */
	SET_BIT((STK->CTRL) , MSTK_CTRL_ENABLE);	
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Enable timer Interrupt */
	SET_BIT((STK->CTRL) , MSTK_CTRL_TICKINT);
	
}
/*-----------------------------------------------------------------------------------------------------------*/

/*###########################################################################################################*/

/*************************************************************************************************************/
/*
 - MSTK_voidSetIntervalPeriodic : Set a periodic time in ms or us using ISR
 - Inputs                       : Copy_u32Time  => Time 
					              Copy_timeUnit => Time Unit in [ms or us]
								  Copy_ptr      => Pointer to function
 - Outputs                      : NONE
*/
/*************************************************************************************************************/
void   MSTK_voidSetIntervalPeriodic(u32 Copy_u32Time ,STK_TIME_t Copy_timeUnit , void (*Copy_ptr) (void))
{
	u32 Local_u32Load = 0 ;
	
	/* To clear the current value */
	STK->VAL = 0 ;
	
	/* Calculate and load the load value */
	switch(Copy_timeUnit)
	{
		/*----------------------------------------------------------------------------------*/
		case TIME_S :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk) ;
				STK->LOAD = Local_u32Load ;
				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_MS :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk / 1000) ;
				STK->LOAD = Local_u32Load ;
				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_US :
				/* Calculate Numbers of Ticks */
				Local_u32Load = Copy_u32Time * (global_u32SystickClk / 1000000) ;
				STK->LOAD = Local_u32Load ;
				break;
		/*----------------------------------------------------------------------------------*/		
		default : 
				break;
		/*----------------------------------------------------------------------------------*/			
	}
	

	if(Copy_ptr != NULL)
	{
		/* Save CallBack */
		MSTK_CallBack = Copy_ptr;
	}
	else{}
	
	/* Start timer */
	SET_BIT(STK->CTRL , MSTK_CTRL_ENABLE);	
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	
	/* Enable timer Interrupt */
	SET_BIT(STK->CTRL , MSTK_CTRL_TICKINT);
		
}
/*************************************************************************************************************/

/*###########################################################################################################*/

/*-----------------------------------------------------------------------------------------------------------*/
/*
 - MSTK_voidStopIntervalPeriodic : Stop Interval Periodic Timer and disable the interrupt
 - Inputs                        : NONE
 - Outputs                       : NONE
*/
/*-----------------------------------------------------------------------------------------------------------*/
void  MSTK_voidStopIntervalPeriodic (void)
{
	/* Stop timer */
	CLR_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
	
	/* Disable timer Interrupt */
	CLR_BIT(STK->CTRL , MSTK_CTRL_TICKINT);
}
/*-----------------------------------------------------------------------------------------------------------*/

/*###########################################################################################################*/

/*-----------------------------------------------------------------------------------------------------------*/
/*
 - MSTK_voidResumeTimer 		: Resume Interval Periodic Timer and enable the interrupt
 - Inputs                       : NONE
 - Outputs                      : NONE
*/
/*-----------------------------------------------------------------------------------------------------------*/
void   MSTK_voidResumeIntervalPeriodic (void) 
{
	/* Enable timer */
	SET_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
	
	/* Enable timer Interrupt */
	SET_BIT(STK->CTRL , MSTK_CTRL_TICKINT);	
}
/*-----------------------------------------------------------------------------------------------------------*/

/*###########################################################################################################*/

/*************************************************************************************************************/
/*
 - MSTK_u32GetElapsedTime 		: Return the Elapsed time in [ms or us]
 - Inputs                       : Copy_timeUnit => Time Unit in [ms or us]
 - Outputs                      : u32 => The Elapsed time
*/
/*************************************************************************************************************/
u32 MSTK_u32GetElapsedTime (STK_TIME_t Copy_timeUnit) 
{
	u32 Local_u32Value = STK->LOAD - STK->VAL ;
	u32 Local_u32ElapsedTime = 0 ;

	switch(Copy_timeUnit)
	{
		/*----------------------------------------------------------------------------------*/
		case TIME_S :
				/* Calculate Numbers of Ticks */
				Local_u32ElapsedTime = (Local_u32Value/global_u32SystickClk) ;

				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_MS :
				/* Calculate Numbers of Ticks */
				Local_u32ElapsedTime = (Local_u32Value / (global_u32SystickClk/1000) ) ;

				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_US :
				/* Calculate Numbers of Ticks */
				Local_u32ElapsedTime = Local_u32Value / (global_u32SystickClk / 1000000) ;
				break;
		/*----------------------------------------------------------------------------------*/		
		default : 
				break;
		/*----------------------------------------------------------------------------------*/			
	}
	return Local_u32ElapsedTime;
}
/*************************************************************************************************************/

/*###########################################################################################################*/

/*-----------------------------------------------------------------------------------------------------------*/
/*
 - MSTK_u32GetRemainingTime 	: Return the Remaining time in [ms or us]
 - Inputs                       : Copy_timeUnit => Time Unit in [ms or us]
 - Outputs                      : u32 => The Elapsed time
*/
/*-----------------------------------------------------------------------------------------------------------*/
u32  MSTK_u32GetRemainingTime (STK_TIME_t Copy_timeUnit) 
{
	u32 Local_u32RemainingTime = 0 ;
	u32 Local_u32Value = STK->VAL ;
	switch(Copy_timeUnit)
	{
		/*----------------------------------------------------------------------------------*/
		case TIME_S :
				/* Calculate Numbers of Ticks */
				Local_u32RemainingTime = (Local_u32Value/global_u32SystickClk) ;

				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_MS :
				/* Calculate Numbers of Ticks */
				Local_u32RemainingTime = (Local_u32Value /(global_u32SystickClk/1000)) ;

				break;
		/*----------------------------------------------------------------------------------*/		
		case TIME_US :
				/* Calculate Numbers of Ticks */
				Local_u32RemainingTime = (Local_u32Value /( global_u32SystickClk / 1000000)) ;
				break;
		/*----------------------------------------------------------------------------------*/		
		default : 
				break;
		/*----------------------------------------------------------------------------------*/			
	}
	return Local_u32RemainingTime;
}

void MSTK_voidStart(void)
{
	/* Zero the Val Register */
	STK->VAL = 0 ;

	/* Load value with max value */
	STK->LOAD = 0xFFFFFF;

	/* Enable timer */
	SET_BIT(STK->CTRL , MSTK_CTRL_ENABLE);

}


/*-----------------------------------------------------------------------------------------------------------*/
/*###########################################################################################################*/
/*###########################################################################################################*/
/*###########################################################################################################*/
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void SysTick_Handler (void)
{
	volatile u8 Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{	
		/* Stop timer */
		CLR_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
	
		/* Disable timer Interrupt */
		CLR_BIT(STK->CTRL , MSTK_CTRL_TICKINT);
	}

	/* Callback notification */
	MSTK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,MSTK_CTRL_COUNTFLAG);

}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/



