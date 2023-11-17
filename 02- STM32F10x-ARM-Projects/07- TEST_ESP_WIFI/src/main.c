/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V01  												*/
/*	Date	 : 17 November 2023                                     */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"

#include "ESP_interface.h"

void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOA);
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_USART1);

	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN0,OUTPUT_SPEED_2MHZ_PP);

	/* A9 = TX output 50 Mhz  Note : You must configure this pin as AFPP  */
	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN9 , OUTPUT_SPEED_50MHZ_AF_PP);
	/* A10 = RX input floating */
	MGPIO_voidSetPinDirection(GPIOA , GPIO_PIN10 , INPUT_FLOATING);

	MUSART1_voidInit();

	HESP_voidInit();

	HESP_voidWifiConnect("WEF8109B","kc131433");
//	HESP_voidWifiConnect("mimo","Mido1234567899");

	/* My website IP  USE INSPECT IN GOOGLE CHROME F11 -> NETWORK */
	HESP_voidWifiServerUrlTCP("185.176.43.112","80");
//	HESP_voidWifiServerUrlTCP("162.253.155.226","80");

	volatile u8 X ;

	while(1)
	{
		X = HESP_u8SendReceiveData(54,"http://mohamed-maged.myartsonline.com/status.txt");  // 48 -> Length of URL  + 6 -> Length of "GET " + "\r\n"

		if(X == '1')
		{
			MGPIO_voidSetPinValue(GPIOA,GPIO_PIN0,GPIO_HIGH);
		}
		else if( X == '0')
		{
			MGPIO_voidSetPinValue(GPIOA,GPIO_PIN0,GPIO_LOW);
		}
		/* My website IP  USE INSPECT IN GOOGLE CHROME F11 -> NETWORK */
		HESP_voidWifiServerUrlTCP("185.176.43.112","80");
//		HESP_voidWifiServerUrlTCP("162.253.155.226","80");
	}
}
