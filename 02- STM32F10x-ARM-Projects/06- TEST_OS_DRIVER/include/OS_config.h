/*******************************************************************************/
/* Author    : Mohamed Maged                                                   */
/* Version   : V01                                                             */
/* Date      : 8 October 2023         	                                       */
/* Logs      : V01 : Initial Creation                                          */
/*******************************************************************************/

#ifndef OS_CONFIG_H
#define OS_CONFIG_H


/*******************************************************************************/
/* - Number of tasks                                                           */
/* - Each Task reserve 10 Bytes in RAM for its TCB [Task Control Block]        */
/*******************************************************************************/
#define  OS_NUMBER_OF_TASKS         3


/*******************************************************************************/
/* - Set Tick time for RTOS												       */
/* - Set Tick time [Unit] for RTOS                                             */
/*******************************************************************************/

/*
 *	Set Tick time for RTOS		
*/
#define  OS_TICK_TIME		        1000
/*------------------------------------------------------------------------------*/
/*
 *  Options :
 * 			   TIME_S
 * 			   TIME_MS
 * 			   TIME_US
*/
#define  OS_TICK_UNIT               TIME_MS
/*------------------------------------------------------------------------------*/
#define  OS_TICK_TIME_UNIT          OS_TICK_TIME,OS_TICK_UNIT
/*******************************************************************************/


#endif