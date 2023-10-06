/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V02                                                  */
/*  Date     : 5 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/*             V02 : Adding Timers Driver instead of SysTick        */
/********************************************************************/
#ifndef REMOTE_CONFIG_H
#define REMOTE_CONFIG_H


/*********************************************/
/*
 * FOR BREAK THE WHILE LOOP IN LED MATREX
 * - ENABLE
 * - DISABLE
 */
/*********************************************/
#define LEDMTX_WHILE_BREAK          ENABLE
/*********************************************/

/*
	Options :
	- SYSTICK_TIMER
	- TIMERS_1_4
*/
#define TIMER_TYPE        TIMERS_1_4
/*
	Options :
		TIMER1  = 0
		TIMER2  = 1
		TIMER3  = 2
		TIMER4  = 3
*/

#if TIMER_TYPE == TIMERS_1_4
	#define TIMER_NUMBER     TIMER2
#endif

/*
	Options : 
		0 : 15 
*/
#define   REMOTE_EXTI_LINE     8

/*
	Options : 
		GPIOA
		GPIOB
		GPIOC
*/
#define   REMOTE_EXTI_PORT     GPIOA

/* Setting up ISR number for NVIC and handler of the isr */
#if   REMOTE_EXTI_LINE == 0
	#define   REMOTE_NVIC_NUMBER    EXTI0_IRQ

#elif REMOTE_EXTI_LINE == 1
	#define   REMOTE_NVIC_NUMBER    EXTI1_IRQ

#elif REMOTE_EXTI_LINE == 2
	#define   REMOTE_NVIC_NUMBER    EXTI2_IRQ

#elif REMOTE_EXTI_LINE == 3
	#define   REMOTE_NVIC_NUMBER    EXTI3_IRQ

#elif REMOTE_EXTI_LINE == 4
	#define   REMOTE_NVIC_NUMBER    EXTI4_IRQ

#elif (REMOTE_EXTI_LINE  > 4) && (REMOTE_EXTI_LINE  < 10)
	#define   REMOTE_NVIC_NUMBER    EXTI9_5_IRQ

#elif (REMOTE_EXTI_LINE  > 9) && (REMOTE_EXTI_LINE  < 16)
	#define   REMOTE_NVIC_NUMBER    EXTI15_10_IRQ

#else
	#error (" Configuration error ")
#endif


#endif
