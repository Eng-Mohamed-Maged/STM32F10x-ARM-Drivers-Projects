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
#include   "REMOTE_interface.h"

/**** Prototypes ******/

void voidTakeRemoteAction(void);



/**** Global variables ****/
// pin configuration
REMOTE_buttons_t global_pressedButton ;

void main(void){

	/* Initialize the RCC to HSE */
	RCC_voidInitSysClock();
	/* Enable the clock for all ports */
	RCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOA);
	RCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOB);
	RCC_voidEnableClock(RCC_APB2 , RCC_APB2_AFIO);

	/* Enable the clock for Timer1 */
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
	/**************************************************************************/


	REMOTE_voidInit();

	while(1)
	{

		voidTakeRemoteAction();
	}
	
}
void voidTakeRemoteAction(void)
{
global_pressedButton = REMOTE_getButton();
if(global_pressedButton < REMOTE_NO_DATA)
{
	switch(global_pressedButton)
	{
	   case REMOTE_ONE:
			/* TURN ON the [RED] LED */
		   MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN9,GPIO_HIGH);
		   break;

	   case REMOTE_TWO:
			/* TURN ON the [GREEN] LED */
		   MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN10,GPIO_HIGH);
		    break;

	   case REMOTE_THREE:
		   /* TURN ON the [BLUE] LED */
		   MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN11,GPIO_HIGH);
		    break;

	   case REMOTE_FOUR:
		   /* TURN OFF the [RED] LED */
		   MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN9,GPIO_LOW);
		    break;

	   case REMOTE_FIVE:
		   /* TURN OFF the [GREEN] LED */
		   MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN10,GPIO_LOW);
		    break;

	   case REMOTE_SIX:
		   /* TURN OFF the [BLUE] LED */
		   MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN11,GPIO_LOW);
		    break;

	   default : break;
	}
}
}


/*


 * initialize the leds pins

void voidInitializeLeds(void)
{
	 initialize port
	GPIO_voidSetPinMode(PORTA , 8 , GPIO_INPUT_FLOATING);
	GPIO_voidSetPinMode(PORTA , 9, GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(PORTA , 10, GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(PORTA , 11, GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(PORTA , 12, GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(PORTB , 12, GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(PORTB , 13, GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(PORTB , 14, GPIO_OUTPUT_10MHZ_PP);
	GPIO_voidSetPinMode(PORTB , 15, GPIO_OUTPUT_10MHZ_PP);
}


 * This function to observe the receiver in case some data came and notify the system
 * of the current state of the system

void voidCheckRemote(void)
{
	global_pressedButton = REMOTE_getButton();
	if(global_pressedButton < REMOTE_NO_DATA){
		switch (global_pressedButton){
			case REMOTE_POWER :
				state = STOP ;
				break;
			case REMOTE_ONE :
				state = PING_PONG;
				break;
			case REMOTE_TWO :
				state = IN_OUT ;
				break;
			case REMOTE_THREE:
				state = FLASHING ;
				break;
			default :
				break;
		}
	}
}


 * Take action based on the date came from receiver

void voidTakeAction(void)
{
	switch (state){
		case STOP :
			for(u8 i = 0 ; i < 16 ; i+=2){
				GPIO_voidsetPinValue(led_arr[i] , led_arr[i + 1] , LOW);
			}
			break;
		case PING_PONG : ping_pong();  break ;
		case IN_OUT    : in_out();     break ;
		case FLASHING  : flashing();   break;
	}
}


void ping_pong(void){
	for(u8 i = 0 ; i < 16 ; i+=2){
		GPIO_voidsetPinValue(led_arr[i] , led_arr[i+1] , HIGH);
		delay_ms(200);
		GPIO_voidsetPinValue(led_arr[i] , led_arr[i+1] , LOW);
	}
	for(u8 i = 12 ; i > 0 ; i-=2){
			GPIO_voidsetPinValue(led_arr[i] , led_arr[i+1] , HIGH);
			delay_ms(200);
			GPIO_voidsetPinValue(led_arr[i] , led_arr[i+1] , LOW);
	}

}

void in_out(void){
	u8 midle1 = 6 ;
	u8 midle2 = 8 ;
	for(u8 i = 0 ; i < 4 ; i++){
		GPIO_voidsetPinValue(led_arr[midle1] , led_arr[midle1 + 1] , HIGH);
		GPIO_voidsetPinValue(led_arr[midle2] , led_arr[midle2 + 1] , HIGH);
		midle1 -= 2 ;
		midle2 += 2 ;
		delay_ms(200);
	}
	midle1 = 0 ;
	midle2 = 14 ;
	for(u8 i = 0 ; i < 4 ; i++){
		GPIO_voidsetPinValue(led_arr[midle1] , led_arr[midle1 + 1] , LOW);
		GPIO_voidsetPinValue(led_arr[midle2] , led_arr[midle2 + 1] , LOW);
		midle1 += 2 ;
		midle2 -= 2 ;
		delay_ms(200);
	}
}

void flashing (void){
	for(u8 i = 0 ; i < 16 ; i+=2){
		GPIO_voidsetPinValue(led_arr[i] , led_arr[i + 1] , HIGH);
	}
	delay_ms(500);
	for(u8 i = 0 ; i < 16 ; i+=2){
		GPIO_voidsetPinValue(led_arr[i] , led_arr[i + 1] , LOW);
	}
	delay_ms(500);
}



*/


