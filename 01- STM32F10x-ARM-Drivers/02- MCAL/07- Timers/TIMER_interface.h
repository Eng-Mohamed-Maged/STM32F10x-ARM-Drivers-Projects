/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V02                                                        */
/* Date        : 5 October 2023                                             */
/* Logs        : V01 : Initial Creation                                     */
/*               V02 : Adding [Function to get Elapsed Time ]               */
/*                     Adding [Function to Stop/Start Timer ]               */
/****************************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


/**** Timer channels ****/
typedef enum {
	TIM1,
	TIM2,
	TIM3,
	TIM4,
	MAX_TIMERS
}TIMER_channels_t;

typedef enum {
	TIMER_S  ,
	TIMER_MS ,
	TIMER_US
}TIME_UNIT_t;


/***********************************************************/
 /* Function Name  : TIMER_voidInit 
  * Function Type  : Initialization 
  * Parameters     : void 
  * Return         : void
  * Description    :
  * Pre-conditions : RCC must be enabled for used timers
					if interrupt is enabled you must enable 
					the correspending interrupt from NVIC
  */				
/************************************************************/
void TIMER_voidInit (void);

/***********************************************************/
 /* Function Name  : TIMER_voidSetBusyWait 
  * Function Type  : Delay function  
  * Parameters     : Timer channel   /  Time in s/ms/us 
  * Return         : void
  * Description    :
  * Pre-conditions : Timer's interrupt must be disabled 
  */				
/************************************************************/
void TIMER_voidSetBusyWait (TIMER_channels_t copy_channel ,u32 copy_u32Time, TIME_UNIT_t copy_TimeUnit);


/***********************************************************/
 /* Function Name  : TIMER_voidSetPeriodic 
  * Function Type  :   
  * Parameters     : Timer channel   /  Time in s/ms/us  /  void function 
  * Return         : void
  * Description    :
  * Pre-conditions :  
  */				
/************************************************************/
void TIMER_voidSetPeriodic (TIMER_channels_t copy_channel ,u32 copy_u32Time ,TIME_UNIT_t copy_TimeUnit , void (*func)(void));
/***********************************************************/
 /* Function Name  : TIMER_voidDisableOverFlowInterrupt 
  * Function Type  :   
  * Parameters     : Timer channel  
  * Return         : void
  * Description    :
  * Pre-conditions :  
  */				
/************************************************************/
void TIMER_voidDisableOverFlowInterrupt(TIMER_channels_t copy_channel );


/***********************************************************/
 /* Function Name  : TIMER_u32GetElapsedTime
  * Function Type  : Getting Elapsed Time
  * Parameters     : Timer channel  - Time Unit
  * Return         : u32
  * Description    :
  * Pre-conditions :
  */
/************************************************************/
u32 TIMER_u32GetElapsedTime(TIMER_channels_t copy_channel,TIME_UNIT_t copy_TimeUnit);


/***********************************************************/
 /* Function Name  : TIMER_voidStart
  * Function Type  : Start the timer for UP_COUNTER
  * Parameters     : Timer channel
  * Return         : void
  * Description    :
  * Pre-conditions :
  */
/************************************************************/
void TIMER_voidStart(TIMER_channels_t copy_channel);



/***********************************************************/
 /* Function Name  : TIMER_voidStop
  * Function Type  : Stop the timer for UP_COUNTER
  * Parameters     : Timer channel
  * Return         : void
  * Description    :
  * Pre-conditions :
  */
/************************************************************/
void TIMER_voidStop(TIMER_channels_t copy_channel);


#endif
