/*****************************************************/
 /* Author      : mosad                              */
 /* Version     : v01                                */
 /* date        : 31/8/2020                          */
/*****************************************************/
#ifndef REMOTE_CONFIG_H
#define REMOTE_CONFIG_H



/*
	Options : 
		0 : 15 
*/
#define   REMOTE_EXTI_LINE     0

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
