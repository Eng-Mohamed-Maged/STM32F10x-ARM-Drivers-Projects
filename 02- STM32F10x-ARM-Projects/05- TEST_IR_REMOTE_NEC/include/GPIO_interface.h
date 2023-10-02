/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V03                                                           */
/*   Date      : 23 September  2023                                            */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Adding [GPIO_PORT_HIGH - GPIO_PORT_LOW]                 */
/*               V03 : Modifications on [MGPIO_voidSetPortValue] function      */
/*******************************************************************************/
#ifndef	GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*****************************************************/				               
#define   GPIOA                           0
#define   GPIOB                           1
#define   GPIOC                           2
/****************************************************/	  		               
#define   GPIO_PIN0                       0
#define   GPIO_PIN1                       1
#define   GPIO_PIN2                       2
#define   GPIO_PIN3                       3
#define   GPIO_PIN4                       4
#define   GPIO_PIN5                       5
#define   GPIO_PIN6                       6
#define   GPIO_PIN7                       7
#define   GPIO_PIN8                       8
#define   GPIO_PIN9                       9
#define   GPIO_PIN10                      10
#define   GPIO_PIN11                      11
#define   GPIO_PIN12                      12
#define   GPIO_PIN13                      13
#define   GPIO_PIN14                      14
#define   GPIO_PIN15                      15
/***************************************************/	 			               
#define   GPIO_LOW 		                  0
#define   GPIO_HIGH 		              1
#define   GPIO_PORT_HIGH                  0x0000FFFF
#define   GPIO_PORT_LOW                   0x00000000
/*******************   -OUTPUT-  *******************/
/*  For 10 Mhz Speed  */                  
#define   OUTPUT_SPEED_10MHZ_PP           0b0001
#define   OUTPUT_SPEED_10MHZ_OD           0b0101
#define   OUTPUT_SPEED_10MHZ_AF_PP        0b1001
#define   OUTPUT_SPEED_10MHZ_AF_OD        0b1101
/*  For 2 Mhz Speed  */                   
#define   OUTPUT_SPEED_2MHZ_PP            0b0010
#define   OUTPUT_SPEED_2MHZ_OD            0b0110
#define   OUTPUT_SPEED_2MHZ_AF_PP         0b1010
#define   OUTPUT_SPEED_2MHZ_AF_OD         0b1110
/*  For 50 Mhz Speed  */				    						  
#define   OUTPUT_SPEED_50MHZ_PP           0b0011
#define   OUTPUT_SPEED_50MHZ_OD           0b0111
#define   OUTPUT_SPEED_50MHZ_AF_PP        0b1011
#define   OUTPUT_SPEED_50MHZ_AF_OD        0b1111
/********************  -INPUT-  *********************/
#define   INPUT_ANALOG                    0b0000
#define   INPUT_FLOATING                  0b0100
#define   INPUT_PULLUP_PULLDOWN           0b1000
/****************************************************/
/***************   -OUTPUT PORT-  *******************/
/****************************************************/
/*  For 10 Mhz Speed For PORT */  
#define   OUTPUT_PORT_SPEED_10MHZ_PP      0x11111111
#define   OUTPUT_PORT_SPEED_10MHZ_OD      0x55555555
#define   OUTPUT_PORT_SPEED_10MHZ_AF_PP   0x99999999
#define   OUTPUT_PORT_SPEED_10MHZ_AF_OD   0xDDDDDDDD
/*  For 2 Mhz Speed For PORT */  
#define   OUTPUT_PORT_SPEED_2MHZ_PP       0x22222222
#define   OUTPUT_PORT_SPEED_2MHZ_OD       0x66666666
#define   OUTPUT_PORT_SPEED_2MHZ_AF_PP    0xAAAAAAAA
#define   OUTPUT_PORT_SPEED_2MHZ_AF_OD    0xEEEEEEEE
/*  For 50 Mhz Speed For PORT */  
#define   OUTPUT_PORT_SPEED_50MHZ_PP      0x33333333
#define   OUTPUT_PORT_SPEED_50MHZ_OD      0x77777777
#define   OUTPUT_PORT_SPEED_50MHZ_AF_PP   0xBBBBBBBB
#define   OUTPUT_PORT_SPEED_50MHZ_AF_OD   0xFFFFFFFF
/****************************************************/
/******************  -INPUT PORT-  ******************/
/****************************************************/
#define   INPUT_PORT_ANALOG               0x00000000 
#define   INPUT_PORT_FLOATING             0b44444444
#define   INPUT_PORT_PULLUP_PULLDOWN      0b88888888

	       
void MGPIO_voidSetPinDirection(u8 Copy_u8Port  , u8 Copy_u8Pin ,u8 Copy_u8Mode );
void MGPIO_voidSetPinValue(u8 Copy_u8Port  , u8 Copy_u8Pin ,u8 Copy_u8Value );
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port  , u8 Copy_u8Pin);
void MGPIO_voidSetPortDirection(u8 Copy_u8Port ,u32 Copy_u32Mode );
void MGPIO_voidSetPortValue(u8 Copy_u8Port ,u32 Copy_u32Value );
void MGPIO_voidSetOrResetPinValue_BSRR_BRR(u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Value );

#endif
