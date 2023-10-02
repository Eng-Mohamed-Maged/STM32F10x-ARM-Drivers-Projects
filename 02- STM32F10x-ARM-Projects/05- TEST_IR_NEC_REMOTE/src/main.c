/**************************************************************************/
/*  Author   : Mohamed Maged                                              */
/*  Version  : V01                                                        */
/*  Date     : 2 October 2023                                             */
/*  Logs     : V01 : Initial Creation                                     */
/**************************************************************************/
/**************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************************************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "REMOTE_interface.h"
/**************************************************************************/
/* Global Variables */
REMOTE_buttons_t REMOTE_BUTTON_PRESSED = REMOTE_NO_DATA ;
/**************************************************************************/
void voidTakeRemoteAction(void);
/**************************************************************************/

int main()
{

/**************************************************************************/
	/* RCC Initialization */
	RCC_voidInitSysClock();
	/* Enable AFIO clock on APB2 Bus  */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_AFIO);
	/* Enable AFIO clock on GPIOA Bus */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOA);
/**************************************************************************/
	/* RGB LED MODE and Value */
	/* Configure GPIOA_PIN1 as output for [RED] LED */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN1,OUTPUT_SPEED_2MHZ_PP);
	/* Set the default Pin value as low */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN1,GPIO_LOW);

	/* Configure GPIOA_PIN2 as output for [GREEN] LED */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN2,OUTPUT_SPEED_2MHZ_PP);
	/* Set the default Pin value as low */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN2,GPIO_LOW);

	/* Configure GPIOA_PIN3 as output for [BLUE] LED */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN3,OUTPUT_SPEED_2MHZ_PP);
	/* Set the default Pin value as low */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN3,GPIO_LOW);
/**************************************************************************/
	/*
	 @ REMOTE Initialization includes :
	   1) NVIC Initialization
	   2) EXTI Initialization
	   3) Set EXTI PIN as Input floating for IR Reciever [EXTI0 => A0]
	   4) Using [EXTI0_IRQHandler] for REMOTE_HANDLER CallBack function
  	   5) Setting EXTI Mode for IR Reciever => FALLING_EDGE mode
       6) Enable EXTI Interrupt
       7) Configure the AFIO for EXTI mapping
       8) Systick Initialization
       9) Enable EXTI from NVIC
	 */
	REMOTE_voidInit();
/**************************************************************************/

	while(1)
	{
		voidTakeRemoteAction();
	}
	return 0;
}



/**************************************************************************/
void voidTakeRemoteAction(void)
{
REMOTE_BUTTON_PRESSED = REMOTE_getButton();
if(REMOTE_BUTTON_PRESSED < REMOTE_NO_DATA)
{
	switch(REMOTE_BUTTON_PRESSED)
	{
	   case REMOTE_ONE:
			/* TURN ON the [RED] LED */
		   MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN1,GPIO_HIGH);
		   break;

	   case REMOTE_TWO:
			/* TURN ON the [GREEN] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN2,GPIO_HIGH);
		    break;

	   case REMOTE_THREE:
		   /* TURN ON the [BLUE] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN3,GPIO_HIGH);
		    break;

	   case REMOTE_FOUR:
		   /* TURN OFF the [RED] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN1,GPIO_LOW);
		    break;

	   case REMOTE_FIVE:
		   /* TURN OFF the [GREEN] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN2,GPIO_LOW);
		    break;

	   case REMOTE_SIX:
		   /* TURN OFF the [BLUE] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN3,GPIO_LOW);
		    break;

	   default : break;
	}
}
}
