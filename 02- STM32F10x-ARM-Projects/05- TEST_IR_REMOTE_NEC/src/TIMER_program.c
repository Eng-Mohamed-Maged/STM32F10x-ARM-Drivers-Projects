/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V02                                                        */
/* Date        : 5 October 2023                                             */
/* Logs        : V01 : Initial Creation                                     */
/*               V02 : Adding [Function to get Elapsed Time ]               */
/*                     Adding [Function to Stop/Start Timer ]               */
/****************************************************************************/

/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* module includes */
#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

/*  Global variables  */
extern const TIMER_config_t configTable[TIMER_NUMBER];
void (* callBackFunc[TIMER_NUMBER])(void);

void TIMER_voidInit (void)
{
	for (TIMER_channels_t i = 0 ; i < MAX_TIMERS ; i++)
	{
		/* Will only configure the time if enabled otherwise the registers 
		   will remain at the reset value */
		if (configTable[i].u8Enable)
		{
			/* Disable timer */
			CLR_BIT (TIMER[i]->CR1, 0 );
			
			/* choose mode */
			switch (configTable[i].u8Mode)
			{
				case UP_COUNTER     :
					CLR_BIT (TIMER[i]->CR1, 4 );
					break ;
				case DOWN_COUNTER   :
					SET_BIT (TIMER[i]->CR1 , 4 );
					break ;
				default : 
					break;
			}
			
			/* Enable / disable interrupt for update  */
			/* Rest of interrups will be implemented later */
			if (configTable[i].u8InterruptEnable){
				SET_BIT (TIMER[i]->DIER , 0 );

			}
			else {
				CLR_BIT (TIMER[i]->DIER , 0 );
			}


			/* Enable Auto-reload */
			if(configTable[i].u8AutoReload_REGISTER)
			{
				SET_BIT(TIMER[i]->CR1 , 7 );
			}
			else
			{
				CLR_BIT(TIMER[i]->CR1 , 7 );

			}


			/* Configure Prescaler */
			TIMER[i]->PSC =  (configTable[i].u16Prescaler - 1 ) ;

			/* Configure Preload register to Maximum value */
			TIMER[i]->ARR = 0xFFFF ;


			/* Start timer */
			SET_BIT (TIMER[i]->CR1, 0 );
		}
	}
} 

/****************** Timer basic functions **********************/

void TIMER_voidSetBusyWait (TIMER_channels_t copy_channel ,u32 copy_u32Time, TIME_UNIT_t copy_TimeUnit)
{
	/* Stop timer */
	CLR_BIT (TIMER[copy_channel]->CR1, 0 );
	
	/* Clear Interrupt flag */
	CLR_BIT (TIMER[copy_channel]->SR , 0);
	
	u16 loacl_u16Hold = 0 ;
	
	/* Configure interval */
	switch(copy_TimeUnit)
	{
		case TIMER_S :
			loacl_u16Hold =  (configTable[copy_channel].u32ClkSource) * copy_u32Time ;
		break;
		
		case TIMER_MS :
			loacl_u16Hold =  (configTable[copy_channel].u32ClkSource / 1000 ) * copy_u32Time ;
		break;

		case TIMER_US :
			loacl_u16Hold =  (configTable[copy_channel].u32ClkSource / 1000000 ) * copy_u32Time ;
		break;

		default : break;
	}

	loacl_u16Hold =  loacl_u16Hold / configTable[copy_channel].u16Prescaler;
	TIMER[copy_channel]->ARR = loacl_u16Hold ;
	TIMER[copy_channel]->CNT = 0x0000 ;

	/* Start timer */
	SET_BIT (TIMER[copy_channel]->CR1, 0 );
	
	/* Wait for flag */
	while (!(GET_BIT (TIMER[copy_channel]->SR, 0)));
	
	/* Stop timer */
	CLR_BIT (TIMER[copy_channel]->CR1, 0 );
} 


void TIMER_voidSetPeriodic (TIMER_channels_t copy_channel ,u32 copy_u32Time ,TIME_UNIT_t copy_TimeUnit , void (*func)(void))
{

	/* Stop timer */
	CLR_BIT (TIMER[copy_channel]->CR1, 0 );
	
	u16 loacl_u16Hold = 0 ;

	/* Configure interval */
	switch(copy_TimeUnit)
	{
		case TIMER_S :
			loacl_u16Hold =  (configTable[copy_channel].u32ClkSource) * copy_u32Time ;
		break;
		
		case TIMER_MS :
			loacl_u16Hold =  (configTable[copy_channel].u32ClkSource / 1000 ) * copy_u32Time ;
		break;

		case TIMER_US :
			loacl_u16Hold =  (configTable[copy_channel].u32ClkSource / 1000000 ) * copy_u32Time ;
		break;

		default : break;
	}
	
	loacl_u16Hold =  loacl_u16Hold / configTable[copy_channel].u16Prescaler;
	TIMER[copy_channel]->ARR = loacl_u16Hold ;


	/* Set call back function */
	callBackFunc[copy_channel] = func ;
	
	/* Start timer */
	SET_BIT (TIMER[copy_channel]->CR1, 0 );
	
	/* Enable interrupt */
	SET_BIT (TIMER[copy_channel]->DIER, 0 );
}


void TIMER_voidDisableOverFlowInterrupt(TIMER_channels_t copy_channel )
{
	/* Disable interrupt */
	CLR_BIT(TIMER[copy_channel]->DIER, 0 );
}

u32 TIMER_u32GetElapsedTime(TIMER_channels_t copy_channel,TIME_UNIT_t copy_TimeUnit)
{
	volatile u16 Local_u16ValueTimer = TIMER[copy_channel]->CNT ;
	volatile u32 Local_u32ElapsedTime = 0 ;

	switch(copy_TimeUnit)
	{
		case TIMER_S :
			Local_u32ElapsedTime = Local_u16ValueTimer / (configTable[copy_channel].u32ClkSource / configTable[copy_channel].u16Prescaler ) ;
		break;

		case TIMER_MS :
			Local_u32ElapsedTime = Local_u16ValueTimer / ((configTable[copy_channel].u32ClkSource / configTable[copy_channel].u16Prescaler )/ 1000) ;
		break;

		case TIMER_US :
			Local_u32ElapsedTime = Local_u16ValueTimer / ((configTable[copy_channel].u32ClkSource / configTable[copy_channel].u16Prescaler )/ 1000000) ;
		break;

		default : break;
	}

	return Local_u32ElapsedTime;
}

void TIMER_voidStart(TIMER_channels_t copy_channel)
{
	/* Clear Counter */
	TIMER[copy_channel]->CNT  =  0x0000 ;

	/* Reset Preload Value to maximum value 0xFFFF */
	TIMER[copy_channel]->ARR  =  0xFFFF ;

	/* Start timer */
	SET_BIT (TIMER[copy_channel]->CR1, 0 );
}


void TIMER_voidStop(TIMER_channels_t copy_channel)
{
	/* Start timer */
	CLR_BIT (TIMER[copy_channel]->CR1, 0 );

	/* Clear Counter */
	TIMER[copy_channel]->CNT  =  0x0000 ;

	/* Reset Preload Value to maximum value 0xFFFF */
	TIMER[copy_channel]->ARR  =  0xFFFF ;
}


/************** ISR handlers ******************/

void TIM2_IRQHandler (void){
	/* Clear flag */
	CLR_BIT (TIMER[1]->SR , 0);
	callBackFunc[1]();
}
void TIM3_IRQHandler (void){
	/* Clear flag */
	CLR_BIT (TIMER[2]->SR , 0);
	callBackFunc[2]();
}
void TIM4_IRQHandler (void){
	/* Clear flag */
	CLR_BIT (TIMER[3]->SR , 0);
	callBackFunc[3]();
}
