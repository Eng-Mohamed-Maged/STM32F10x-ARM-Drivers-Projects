/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V01  												*/
/*	Date	 : 19 September 2020                                    */
/********************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


typedef struct
{
	volatile u32 SR   ;
	volatile u32 DR   ;
	volatile u32 BRR  ;
	volatile u32 CR1  ;
	volatile u32 CR2  ;
	volatile u32 CR3  ;
	volatile u32 GTPR ;
}UART_t;


/*  Base Address  */
#define UART1     ((volatile UART_t*) 0x40013800 )   



/*******************************************************/
#define UART_BAUD_RATE_9600_8MHZ		0x341
#define UART_BAUD_RATE_115200_8MHZ      0x45
/*******************************************************/
/*******************************************************/
/*************         USART_CR1            ************/
/*******************************************************/
#define UART_DISABLE                    0x00000000
#define UART_ENABLE						0x00002000
/*******************************************************/
#define UART_8_DATA_BITS 				0x00000000
#define UART_9_DATA_BITS				0x00001000
/*******************************************************/
#define UART_IDLE_LINE 					0x00000000
#define UART_ADDRESS_MARK				0x00000800
/*******************************************************/
#define UART_PARITY_DISABLE				0x00000000
#define UART_PARITY_ENABLE  		  	0x00000400
/*******************************************************/
#define UART_EVEN_PARITY      			0x00000000
#define UART_ODD_PARITY					0x00000200
/*******************************************************/
#define UART_PE_INTERRUPT_DISABLE 		0x00000000
#define UART_PE_INTERRUPT_ENABLE  		0x00000100
/*******************************************************/
#define UART_TXE_INTERRUPT_DISABLE 		0x00000000
#define UART_TXE_INTERRUPT_ENABLE  		0x00000080
/*******************************************************/
#define UART_TCIE_INTERRUPT_DISABLE 	0x00000000
#define UART_TCIE_INTERRUPT_ENABLE  	0x00000040
/*******************************************************/
#define UART_RXNE_INTERRUPT_DISABLE 	0x00000000
#define UART_RXNE_INTERRUPT_ENABLE  	0x00000020
/*******************************************************/
#define UART_IDLE_INTERRUPT_DISABLE 	0x00000000
#define UART_IDLE_INTERRUPT_ENABLE 		0x00000010
/*******************************************************/
#define UART_TX_DISABLE 				0x00000000
#define UART_TX_ENABLE 					0x00000008
/*******************************************************/
#define UART_RX_DISABLE   				0x00000000
#define UART_RX_ENABLE 					0x00000004
/*******************************************************/
#define UART_RX_WAKEUP_ACTIVE   		0x00000000
#define UART_RX_WAKEUP_MUTE 			0x00000002
/*******************************************************/
#define UART_NO_BREAK_TRANSMITTED   	0x00000000
#define UART_SEND_BREAK					0x00000001
/*******************************************************/
/*************         USART_CR2            ************/
/*******************************************************/

#endif