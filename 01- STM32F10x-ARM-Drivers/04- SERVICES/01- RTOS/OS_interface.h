/*******************************************************************************/
/* Author    : Mohamed Maged                                                   */
/* Version   : V01                                                             */
/* Date      : 8 October 2023         	                                       */
/* Logs      : V01 : Initial Creation                                          */
/*******************************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

/*******************************************************************************/
/* - Pre conditions :                                                          */
/* - 	1 - Dont use STK driver in other module                                */
/* - 	2 - STK drivers files must be included in the project                  */
/* - 	3 - Number of tasks must be configured  ( OS_NUMBER_OF_TASKS )         */
/* - 	4 - Clock must be selected right in STK driver to ensure right time    */
/* - 	5 - OS_voidStart must be called before while                           */
/* - 	6 - OS_voidDispatcher must be called in the while                      */
/* - 	7 - Global interrupt must be active                                    */
/*******************************************************************************/

/* Task States */
typedef enum
{
	OS_TASK_READY ,
	OS_TASK_SUSPEND
}OS_TASK_STATES_t


/*******************************************************************************/
/* - Initialize OS and start the Scheduler                                     */
/*******************************************************************************/
void OS_voidStartScheduler(void);


/*******************************************************************************/
/* - Stop the Scheduler                                                        */
/*******************************************************************************/
void OS_voidStopScheduler(void);



/*******************************************************************************/
/* - Resume the Scheduler                                                      */
/*******************************************************************************/
void OS_voidResumeScheduler(void);


/*******************************************************************************/
/* - Start the Dispatcher to call the right task                               */
/*******************************************************************************/
void OS_voidDispatcher(void);


/*******************************************************************************/
/* - To Create new task  										               */
/*******************************************************************************/
void OS_voidCreateTask(u8 Copy_u8ID,u16 copy_u16delay,u16 copy_u16period,void(*copy_voidFunc)(void));


/*******************************************************************************/
/* - To put the task in Suspend state 										   */
/*******************************************************************************/
void OS_voidSuspendTask(u8 Copy_u8ID);


/*******************************************************************************/
/* - To put the task in Ready state 										   */
/*******************************************************************************/
void OS_voidResumeTask(u8 Copy_u8ID);

/*******************************************************************************/
/* - To delete the task in Suspend state 									   */
/*******************************************************************************/
void OS_voidDeleteTask(u8 Copy_u8ID);


#endif
