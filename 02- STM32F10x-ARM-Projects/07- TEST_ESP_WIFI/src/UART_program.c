/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V02 													*/
/*	Date	 : 29 September 2020                                    */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void MUSART1_voidInit(void)
{
	/* Baud rate */
	UART1 -> BRR = UART_BAUD_RATE ;
	/*
		1- Enable RX
		2- Enable TX
		3- Enable UART   
		4- 8 Bits       */
	UART1 -> CR1 = (UART_EN | UART_WORD_LENGTH | UART_WAKE_UP | UART_PARITY_EN | UART_PARITY_SELECTION | UART_PE_INTERRUPT | UART_TXE_INTERRUPT | UART_TCIE_INTERRUPT | UART_RXNE_INTERRUPT | UART_IDLE_INTERRUPT | UART_TX_EN | UART_RX_EN | UART_RX_WAKEUP | UART_BREAK_SEND ) ;

	/* Clear Status Registers */
	UART1 -> SR = 0 ;

}

void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0')
	{
		UART1 -> DR = arr[i];
		/* Wait till transmission complete */
		/* while (((UART1 -> SR) & 0x40) == 0 ) ;  */
		while(GET_BIT( UART1 -> SR , 6) == 0);
		i++;
	}



}



u8   MUSART1_u8Receive(void)
{
	u16 TimeOut = 0 ;
	u8 Loc_u8ReceivedData = 0 ;
	while(GET_BIT( UART1 -> SR , 5) == 0)
	{
		TimeOut++ ;
		if(TimeOut == 2100)
		{
			break;
		}
	}
	if (Loc_u8ReceivedData == 0)
	{
		/* Masking */
		Loc_u8ReceivedData = 0xFF & (UART1 -> DR) ;
	}
	return(Loc_u8ReceivedData) ;

}
