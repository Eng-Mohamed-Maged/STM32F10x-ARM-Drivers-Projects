/*******************************************************************************/
/* Author    : Mohamed Maged                                                   */
/* Version   : V01                                                             */
/* Date      : 8 October 2023         	                                       */
/* Logs      : V01 : Initial Creation                                          */
/*******************************************************************************/
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
/*******************************************************************************/
#include  "RCC_interface.h"
#include  "GPIO_interface.h"
#include  "STK_interface.h"
#include  "NVIC_interface.h"
#include  "AFIO_interface.h"
#include  "EXTI_interface.h"
#include  "OS_interface.h"
/*******************************************************************************/
void Task_1_GREEN(void);
void Task_2_YELLOW(void);
void Task_3_RED(void);
/*******************************************************************************/
void Mohamed (void)
{
	/*Suspend Task-1, ID = 0 */
	OS_voidSuspendTask(0);

}
/*******************************************************************************/

void Maged (void)
{
	/*Resume Task-1, ID = 0 */
	OS_voidResumeTask(0);
}
/*******************************************************************************/
void Khalil (void)
{
	/*Delete Task-1, ID = 0 */
	OS_voidDeleteTask(0);
}
/*******************************************************************************/

void main(void)
{
	/* Initialization */
	RCC_voidInitSysClock();

	/*Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOA);
	/*RCC AFIO							*/
	RCC_voidEnableClock(RCC_APB2 ,RCC_APB2_AFIO);

	/* CallBack for EXTI0  */
	MEXTI_voidSetCallBack(Mohamed,MEXTI_LINE0);
	/* CallBack for EXTI1  */
	MEXTI_voidSetCallBack(Maged  ,MEXTI_LINE1);
	/* CallBack for EXTI2  */
	MEXTI_voidSetCallBack(Khalil ,MEXTI_LINE2);

	/* NVIC  */
	MNVIC_voidInit();

	/* GPIO Deceleration */
	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN5 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN6 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN7 , OUTPUT_SPEED_2MHZ_PP);

	/* INPUT Switches */
	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN0 , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinValue(GPIOA , GPIO_PIN0 , GPIO_HIGH);

	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN1 , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinValue(GPIOA , GPIO_PIN1 , GPIO_HIGH);

	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN2 , INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetPinValue(GPIOA , GPIO_PIN2 , GPIO_HIGH);

	/* Set AFIO for EXTI0 -> A0 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI0,MAFIO_PORT_A) ;
	/* Set AFIO for EXTI1 -> A1 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI1,MAFIO_PORT_A) ;
	/* Set AFIO for EXTI3 -> A3 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI2,MAFIO_PORT_A) ;


	MEXTI_voidSetSignalLatch(MEXTI_LINE0 , MEXTI_ON_CHANGE);
	MEXTI_voidSetSignalLatch(MEXTI_LINE1 , MEXTI_ON_CHANGE);
	MEXTI_voidSetSignalLatch(MEXTI_LINE2 , MEXTI_ON_CHANGE);

	/* Enable EXTI0 From [EXTI] Driver */
	MEXTI_voidEnableEXTI(MEXTI_LINE0);

	/* Enable EXTI1 From [EXTI] Driver */
	MEXTI_voidEnableEXTI(MEXTI_LINE1);

	/* Enable EXTI2 From [EXTI] Driver */
	MEXTI_voidEnableEXTI(MEXTI_LINE2);


	/* Enable EXTI0 */
	MNVIC_voidEnableInterrupt(EXTI0_IRQ);
	/* Enable EXTI1 */
	MNVIC_voidEnableInterrupt(EXTI1_IRQ);
	/* Enable EXTI2 */
	MNVIC_voidEnableInterrupt(EXTI2_IRQ);

	/* Create Task */
	// TaskID = 0 , TaskFirstDelay = 0 , TaskPeriodicity = 1000 , TaskHandler = Task_1 //
	OS_voidCreateTask(0,1000,Task_1_GREEN,0);

	// TaskID = 1 , TaskFirstDelay = 1 , TaskPeriodicity = 2000 , TaskHandler = Task_2 //
	OS_voidCreateTask(0,2000,Task_2_YELLOW,1);

	// TaskID = 2 , TaskFirstDelay = 2 , TaskPeriodicity = 4000 , TaskHandler = Task_3 //
	OS_voidCreateTask(0,4000,Task_3_RED,2);


	/* Start the Scheduler  */
	OS_voidStartScheduler();

	while(1)
	{

	}
}

void Task_1_GREEN(void)
{
	static u8 Local_u8Pin0 = 0 ;
	TOG_BIT(Local_u8Pin0 , 0) ;
	MGPIO_voidSetPinValue(GPIOA , GPIO_PIN5 , Local_u8Pin0);

}

void Task_2_YELLOW(void)
{
	static u8 Local_u8Pin1 = 0 ;
	TOG_BIT(Local_u8Pin1 , 0) ;
	MGPIO_voidSetPinValue(GPIOA , GPIO_PIN6 , Local_u8Pin1);


}

void Task_3_RED(void)
{
	static u8 Local_u8Pin2 = 0 ;
	TOG_BIT(Local_u8Pin2 , 0) ;
	MGPIO_voidSetPinValue(GPIOA , GPIO_PIN7 , Local_u8Pin2);
}
