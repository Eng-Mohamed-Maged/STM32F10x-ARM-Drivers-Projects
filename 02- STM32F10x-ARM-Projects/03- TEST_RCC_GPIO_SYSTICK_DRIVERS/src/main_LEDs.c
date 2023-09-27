/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 27 September 2023                                             */
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

u8 LED_STATUS = 0;
u32 Time_in_mSeconds = 1000 ;
void mohamed_leds (void)
{
	if(LED_STATUS == 0)
	{
		/* Turn On the Green LED */
		MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN2,GPIO_HIGH);
	}
	else
	{
		/* Turn Off the Green LED */
		MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN2,GPIO_LOW);
	}
	LED_STATUS ^= 1;
}

/***********************************************/
void voidCallBack_EXTI0(void)
{
	/* Increase the delay of LED Blinking */
	Time_in_mSeconds = Time_in_mSeconds + 100;
	/* Stop Interval Periodic */
	MSTK_voidStopIntervalPeriodic();
	/* Set Interval Periodic Timer With the new time */
	MSTK_voidSetIntervalPeriodic(Time_in_mSeconds,TIME_MS,mohamed_leds);

}
/***********************************************/
void voidCallBack_EXTI1(void)
{
	/* Decrease the delay of LED Blinking */
	Time_in_mSeconds = Time_in_mSeconds - 100;
	/* Stop Interval Periodic */
	MSTK_voidStopIntervalPeriodic();
	/* Set Interval Periodic Timer With the new time */
	MSTK_voidSetIntervalPeriodic(Time_in_mSeconds,TIME_MS,mohamed_leds);

}
/***********************************************/


int main()
{
	/* Initialize the Clock */
	RCC_voidInitSysClock();

	/* Enable Clock of GPIOA */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOA);

	/* Enable Clock of GPIOB */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOB);

	/* Enable Clock of AFIO for EXTI */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_AFIO);

	/* Initialize the NVIC	 */
	MNVIC_voidInit();

	/* Initialize EXTI */
	MEXTI_voidInit();

	/* Initialize Systick Timer */
	MSTK_voidInit();

	//--------------------- INPUT PINS ---------------------------//
	/* Configure GPIOA Pin 0 as Input PULLUP PULLDOWN */
	MGPIO_voidSetPinDirection(GPIOB,GPIO_PIN0,INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOB,GPIO_PIN0,GPIO_HIGH);

	/* Configure GPIOA Pin 1 as Input PULLUP PULLDOWN */
	MGPIO_voidSetPinDirection(GPIOB,GPIO_PIN1,INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOB,GPIO_PIN1,GPIO_HIGH);

	/************ Configure AFIO for [EXTI0 - EXTI1] ***************/
	/* EXTI0 from GPIOB  Pin B0 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI0,MAFIO_PORT_B);

	/* EXTI1 from GPIOB  Pin B1 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI1,MAFIO_PORT_B);

	//--------------------- OUTPUT PINS ---------------------------//
	/* Configure GPIOA Pin 2 as Output Push Pull 2Mhz  */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN2,OUTPUT_SPEED_2MHZ_PP);
	/* Turn On the Green LED */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN2,GPIO_HIGH);

	//---------- Set Signal Event for [EXTI0-EXTI1]  --------------//
	/* Set Signal Latch For EXTI0 */
	MEXTI_voidSetSignalLatch(MEXTI_LINE0,MEXTI_RISING_EDGE);

	/* Set Signal Latch For EXTI1 */
	MEXTI_voidSetSignalLatch(MEXTI_LINE1,MEXTI_RISING_EDGE);

	/* Enable EXTI 0 */
	MEXTI_voidEnableEXTI(MEXTI_LINE0);
	/* Enable EXTI 1 */
	MEXTI_voidEnableEXTI(MEXTI_LINE1);

	/* Set CallBack Function for EXTI0 */
	MEXTI_voidSetCallBack(voidCallBack_EXTI0,MEXTI_LINE0);

	/* Set CallBack Function for EXTI1 */
	MEXTI_voidSetCallBack(voidCallBack_EXTI1,MEXTI_LINE1);

	/* Set Priority for EXTI0 [2 Groups - 8 Sub ]  */
	MNVIC_voidSetPriority(EXTI0_IRQ,0,0,MNVIC_GROUP_0_SUB_16);
	MNVIC_voidSetPriority(EXTI1_IRQ,0,0,MNVIC_GROUP_0_SUB_16);

	/* Enable EXTI0 Interrupt */
	MNVIC_voidEnableInterrupt(EXTI0_IRQ);

	/* Enable EXTI1 Interrupt */
	MNVIC_voidEnableInterrupt(EXTI1_IRQ);

	/* Call the function [mohamed_leds] */
	MSTK_voidSetIntervalPeriodic(Time_in_mSeconds,TIME_MS,mohamed_leds);

	while(1)
	{

	}
	return 0;
}
