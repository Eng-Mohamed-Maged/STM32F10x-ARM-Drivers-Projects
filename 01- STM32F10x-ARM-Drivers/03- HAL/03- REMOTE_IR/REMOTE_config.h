/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V01                                                  */
/*  Date     : 1 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#ifndef REMOTE_CONFIG_H
#define REMOTE_CONFIG_H


/*
	Choose Between [EXTI0 : EXTI15]
	Options : 
		0 : 15 
*/
#define   REMOTE_EXTI_LINE     0  


/*
	Choose the port for EXTI which connected to IR Reciever
	Options : 
		GPIOA
		GPIOB
		GPIOC
*/
#define   REMOTE_EXTI_PORT     GPIOA


#endif