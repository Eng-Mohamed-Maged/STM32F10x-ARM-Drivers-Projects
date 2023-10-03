/*****************************************************/
/* Author      : Mohamed Maged                       */
/* Version     : V01                                 */
/* Date        : 3 October 2023                      */
/* Logs        : V01 : Initial Creation              */
/*****************************************************/
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
	TIME_S  ,
	TIME_MS ,
	TIME_US
}TIME_UNIT_t;


/***********************************************************/
 /* Function Name  : TIMER_voidInit 
  * Function Type  : Initialization 
  * Parameters     : void 
  * Return         : void
  * Discription    : 
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
  * Discription    : 
  * Pre-conditions : Timer's interrupt must be disabled 
  */				
/************************************************************/
void TIMER_voidSetBusyWait (TIMER_channels_t copy_channel , TIME_UNIT_t copy_TimeUnit);


/***********************************************************/
 /* Function Name  : TIMER_voidSetPeriodic 
  * Function Type  :   
  * Parameters     : Timer channel   /  Time in s/ms/us  /  void function 
  * Return         : void
  * Discription    : 
  * Pre-conditions :  
  */				
/************************************************************/
void TIMER_voidSetPeriodic (TIMER_channels_t copy_channel , TIME_UNIT_t copy_TimeUnit , void (*func)(void));

/***********************************************************/
 /* Function Name  : TIMER_voidDisableOverFlowInterrupt 
  * Function Type  :   
  * Parameters     : Timer channel  
  * Return         : void
  * Discription    : 
  * Pre-conditions :  
  */				
/************************************************************/
void TIMER_voidDisableOverFlowInterrupt(TIMER_channels_t copy_channel );



#endif
