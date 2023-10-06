/*
 * main.c
 *
 *  Created on: Aug 13, 2020
 *      Author: mosad
 */

/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL includes */
#include  "RCC_interface.h"
#include  "GPIO_interface.h"

/* HAL includes */
#include "REMOTE_interface.h"
#include "LEDMTX_interface.h"
/**** Prototypes ******/

void voidTakeRemoteAction(void);
void voidTakeAction(void);


/**************************************************************************/
/************************** Global variables ******************************/
/*************************** REMOTE SECTION *******************************/
// pin configuration
REMOTE_buttons_t global_pressedButton ;
/*************************** LED MTX SECTION ******************************/
//u8 LED_HEART[] = {255, 227, 193, 129, 3, 129, 193, 227, 255};
u8 LED_MAN_A[] = {215, 85, 125, 85, 215, 0, 192, 192};
u8 LED_MAN_B[] = {215, 85, 125, 85, 87, 64, 24, 24};
u8 LED_HELLO[] = {255, 211, 165, 201, 201, 165, 211, 255, 0, 0, 0, 0, 0, 28, 62, 126, 252, 126, 62, 28, 0, 0, 126, 8, 8, 126, 0, 126, 82, 82, 0, 126, 64, 64, 0, 126, 64, 64, 0, 126, 66, 66, 126, 0, 28, 62, 126, 252, 126, 62, 28, 0, 0, 0, 0, 255, 211, 165, 201, 201, 165, 211, 255, 0};

/* Calculate the array size */
u8 Array_Length_A = sizeof(LED_MAN_A) / sizeof(LED_MAN_A[0]);
u8 Array_Length_B = sizeof(LED_MAN_B) / sizeof(LED_MAN_B[0]);
u8 HELLO_Length   = sizeof(LED_HELLO) / sizeof(LED_HELLO[0]);

u8 global_LEDMTX_DELAY = 70 ;
u8 u8LED_MATRIX_ON_OFF_STATE = 1 ;
/**************************************************************************/
typedef enum
{
	NONE                    ,
	TURN_ON_RED_LED         ,
	TURN_OFF_RED_LED 	    ,
	TURN_ON_GREEN_LED 	    ,
	TURN_OFF_GREEN_LED 	    ,
	TURN_ON_BLUE_LED        ,
	TURN_OFF_BLUE_LED 	    ,
	TURN_ON_OFF_LED_MATRIX  ,
	SPEED_UP_LED_MATRIX     ,
	SLOW_DOWN_LED_MATRIX    ,
	BALL_UP_DOWN
}STATE_t;

STATE_t STATE_tGlobalState =   NONE ;

/**************************************************************************/

void main(void){

	/* Initialize the RCC to HSE */
	RCC_voidInitSysClock();
	/* Enable the clock for all ports */
	RCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOA);
	RCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOB);
	RCC_voidEnableClock(RCC_APB2 , RCC_APB2_AFIO);

	/* Enable the clock for Timer2 for IR-REMOTE */
	RCC_voidEnableClock(RCC_APB1,RCC_APB1_Timer2);
//	RCC_voidEnableClock(RCC_APB1,RCC_APB1_Timer3);

/**************************************************************************/
	/* RGB LED MODE and Value */
	/* Configure GPIOA_PIN9 as output for [RED] LED */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN9,OUTPUT_SPEED_2MHZ_PP);
	/* Set the default Pin value as low */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN9,GPIO_LOW);

	/* Configure GPIOA_PIN10 as output for [GREEN] LED */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN10,OUTPUT_SPEED_2MHZ_PP);
	/* Set the default Pin value as low */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN10,GPIO_LOW);

	/* Configure GPIOA_PIN11 as output for [BLUE] LED */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN11,OUTPUT_SPEED_2MHZ_PP);
	/* Set the default Pin value as low */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN11,GPIO_LOW);
/*******************************************************************************/
/**************************** IR REMOTE SECTION ********************************/
	/* Remote Initialization */
	REMOTE_voidInit();
/*******************************************************************************/
/***************************** LED MTX SECTION *********************************/
	/* SysTick Initialization */
	MSTK_voidInit();
	/* LED Matrix Initialization */
	HLEDMTX_voidInit();
/*******************************************************************************/

	while(1)
	{
		voidTakeRemoteAction();
		voidTakeAction();
		STATE_tGlobalState = NONE ;
	}
	
}








void voidTakeRemoteAction(void)
{
	global_pressedButton = REMOTE_getButton();
	if(global_pressedButton < REMOTE_NO_DATA)
	{
		switch(global_pressedButton)
		{
			case REMOTE_ONE        : STATE_tGlobalState = TURN_ON_RED_LED    	 ;break;
			case REMOTE_TWO        : STATE_tGlobalState = TURN_ON_GREEN_LED  	 ;break;
			case REMOTE_THREE      : STATE_tGlobalState = TURN_ON_BLUE_LED   	 ;break;
			case REMOTE_FOUR       : STATE_tGlobalState = TURN_OFF_RED_LED   	 ;break;
			case REMOTE_FIVE       : STATE_tGlobalState = TURN_OFF_GREEN_LED     ;break;
   		    case REMOTE_SIX        : STATE_tGlobalState = TURN_OFF_BLUE_LED      ;break;
			case REMOTE_POWER      : STATE_tGlobalState = TURN_ON_OFF_LED_MATRIX ;break;
			case REMOTE_VOL_DOWN   : STATE_tGlobalState = SLOW_DOWN_LED_MATRIX   ;break;
			case REMOTE_VOL_UP     : STATE_tGlobalState = SPEED_UP_LED_MATRIX    ;break;
			case REMOTE_EQ         : STATE_tGlobalState = BALL_UP_DOWN           ;break;
			default                : STATE_tGlobalState = NONE                   ;break;
		}
	}
}


void voidTakeAction(void)
{
	switch(STATE_tGlobalState)
	{
		case TURN_ON_RED_LED :
			/* TURN ON the [RED] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN9,GPIO_HIGH);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
			break ;

		case TURN_OFF_RED_LED :
			/* TURN OFF the [RED] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN9,GPIO_LOW);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
	    	break;

		case TURN_ON_GREEN_LED :
			/* TURN ON the [GREEN] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN10,GPIO_HIGH);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
	    	break;

		case TURN_OFF_GREEN_LED :
			/* TURN OFF the [GREEN] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN10,GPIO_LOW);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
	    	break;

		case TURN_ON_BLUE_LED :
			/* TURN ON the [BLUE] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN11,GPIO_HIGH);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
	    	break;

		case TURN_OFF_BLUE_LED :
			/* TURN OFF the [BLUE] LED */
			MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN11,GPIO_LOW);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
	    	break;

		case TURN_ON_OFF_LED_MATRIX :
			u8LED_MATRIX_ON_OFF_STATE = 1 ;
			global_LEDMTX_DELAY = 70 ;
			HLEDMTX_voidShiftDisplay(LED_HELLO,HELLO_Length,global_LEDMTX_DELAY);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
			break;

		case SPEED_UP_LED_MATRIX :
			global_LEDMTX_DELAY -= 30 ;
			u8LED_MATRIX_ON_OFF_STATE = 1 ;
			HLEDMTX_voidShiftDisplay(LED_HELLO,HELLO_Length,global_LEDMTX_DELAY);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
			break;

		case SLOW_DOWN_LED_MATRIX :
			global_LEDMTX_DELAY += 30 ;
			u8LED_MATRIX_ON_OFF_STATE = 1 ;
			HLEDMTX_voidShiftDisplay(LED_HELLO,HELLO_Length,global_LEDMTX_DELAY);
			/* TO TAKE NEW ACTION */
			STATE_tGlobalState = NONE ;
			break;

		case BALL_UP_DOWN :
			u8LED_MATRIX_ON_OFF_STATE  = 1 ;
			HLEDMTX_voidShiftDisplay(LED_MAN_A,Array_Length_A,500);
			HLEDMTX_voidShiftDisplay(LED_MAN_B,Array_Length_B,500);

			break;
		default :	STATE_tGlobalState = NONE ; break;

	}
}
