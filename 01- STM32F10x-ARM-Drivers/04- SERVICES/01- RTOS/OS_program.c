/*******************************************************************************/
/* Author    : Mohamed Maged                                                   */
/* Version   : V01                                                             */
/* Date      : 8 October 2023         	                                       */
/* Logs      : V01 : Initial Creation                                          */
/*******************************************************************************/

/* Library Includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Includes */
#include "STK_interface.h"

/* MODULE Includes */
#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"

/* Array of Tasks  (Array of Structure) */
OS_TASK_t Global_Tasks[OS_NUMBER_OF_TASKS] = {NULL} ;



/*******************************************************************************/
/* - Initialize OS and start the Scheduler                                     */
/*******************************************************************************/
void OS_voidStartScheduler(void)
{
	/* Initialize Systick Timer */
	MSTK_voidInit();
	
	/* Setup the scheduler Tick Time */
	MSTK_voidSetIntervalPeriodic(OS_TICK_TIME_UNIT,voidScheduler);
}


/*******************************************************************************/
/* - Stop the Scheduler                                                        */
/*******************************************************************************/
void OS_voidStopScheduler(void)
{
	MSTK_voidStopIntervalPeriodic();
}



/*******************************************************************************/
/* - Resume the Scheduler                                                      */
/*******************************************************************************/
void OS_voidResumeScheduler(void)
{
	MSTK_voidResumeIntervalPeriodic();
}


/*******************************************************************************/
/* - Start the Dispatcher to call the right task                               */
/*******************************************************************************/
void OS_voidDispatcher(void)
{
	/* Check on all the tasks and execute any task with RunFlag above zero*/
	for (u8 i = 0; i < OS_NUMBER_OF_TASKS ; i++)
	{
		if ( (Global_Tasks[i].Fptr != NULL ) && (Global_Tasks[i].RunFlag > 0) )
		{
			Global_Tasks[i].Fptr();
			Global_Tasks[i].RunFlag -= 1 ;
			
		}
		else
		{

		}
	}
	/* To save the power between ticks when there is no tasks ready yet */
	/* put the processor into a low power state - providing an automatic power saving */
	voidGoToSleep();
}


/*******************************************************************************/
/* - To Create new task  										               */
/*******************************************************************************/
void OS_voidCreateTask(u8 Copy_u8ID,u16 Copy_u16delay,u16 Copy_u16period,void(*Copy_voidFptr)(void))
{
	/* assign task parameters to the right array index */
	if (Copy_u8ID < OS_NUMBER_OF_TASKS)
	{
		Global_Tasks[Copy_u8ID].FirstDelay       = copy_u16delay    ;
		Global_Tasks[Copy_u8ID].Priodicity 		 = Copy_u16period   ;
		Global_Tasks[Copy_u8ID].Fptr   		     = Copy_voidFptr    ;
		Global_Tasks[Copy_u8ID].Task_state       = OS_TASK_READY    ;
		Global_Tasks[Copy_u8ID].RunFlag          = 0                ;
	}
	else 
	{
		
	}
}


/*******************************************************************************/
/* - To put the task in Suspend state 										   */
/*******************************************************************************/
void OS_voidSuspendTask(u8 Copy_u8ID)
{
	if (Global_Tasks[Copy_u8ID].Fptr != NULL)
	{
		Global_Tasks[Copy_u8ID].Task_state  = OS_TASK_SUSPEND    ;
	}
	else
	{
		
	}
}


/*******************************************************************************/
/* - To put the task in Ready state 										   */
/*******************************************************************************/
void OS_voidResumeTask(u8 Copy_u8ID)
{
	if (Global_Tasks[Copy_u8ID].Fptr != NULL)
	{
		Global_Tasks[Copy_u8ID].Task_state  = OS_TASK_READY    ;
	}
	else
	{
		
	}
}

/*******************************************************************************/
/* - To delete the task in Suspend state 									   */
/*******************************************************************************/
void OS_voidDeleteTask(u8 Copy_u8ID)
{
	if (Global_Tasks[Copy_u8ID].Fptr != NULL)
	{
		Global_Tasks[Copy_u8ID].FirstDelay       = 0    			;
		Global_Tasks[Copy_u8ID].Priodicity 		 = 0   				;
		Global_Tasks[Copy_u8ID].Fptr   		     = NULL    			;
		Global_Tasks[Copy_u8ID].RunFlag          = 0                ;
	}
	else 
	{

	}
}





/*******************************************************************************/
/****************************** Private Fptrtions ******************************/
static void voidScheduler(void)
{
/***************************  Co-operative scheduling  *************************/
	for (u8 i = 0; i < OS_NUMBER_OF_TASKS ; i++)
	{
		if ( (Global_Tasks[i].Fptr != NULL) && (Global_Tasks[i].Task_state == OS_TASK_READY) )
		{			
			/* Time of the task has come */
			if ( Global_Tasks[i].FirstDelay == 0)
			{
				/* Dispatcher will check this flag in the while */
				Global_Tasks[i].RunFlag++;
				
				/* Only if the task periodic will updated the FirstDelay */
				if (Global_Tasks[i].Priodicity)
				{
					Global_Tasks[i].FirstDelay = Global_Tasks[i].Priodicity - OS_TICK_TIME ;
				}
			}
			else
			{
				Global_Tasks[i].FirstDelay -= OS_TICK_TIME ;
			}
		}
		else
		{
			/* Should not be here */
		}
	}
}

/*******************************************************************************/
/* - This makes the idle hook Fptrtion an ideal place to put the processor     */
/* - into a low power state - providing an automatic power saving whenever     */
/* - there is no processing to be performed. 								   */					
/*******************************************************************************/
static void voidGoToSleep(void)
{
	__asm ("WFI");
}
