/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V01  												*/
/*	Date	 : 19 September 2020                                    */
/********************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/******************************************************************************/
/* Write Port and pin in pairs -> port,pin */

/******************************************************************************/


/******************************************************************************/
/* Options : 
				UART_BAUD_RATE_9600_8MHZ
				UART_BAUD_RATE_115200_8MHZ
									*/

#define   UART_BAUD_RATE     	   UART_BAUD_RATE_115200_8MHZ

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_DISABLE
				UART_ENABLE
									*/
	
#define   UART_EN              		  UART_ENABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_8_DATA_BITS
				UART_9_DATA_BITS
									*/

#define   UART_WORD_LENGTH      	  UART_8_DATA_BITS

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_IDLE_LINE
				UART_ADDRESS_MARK
									*/

#define   UART_WAKE_UP            	  UART_IDLE_LINE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_PARITY_DISABLE
				UART_PARITY_ENABLE
									*/

#define   UART_PARITY_EN     		   UART_PARITY_DISABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_EVEN_PARITY
				UART_ODD_PARITY
									*/

#define   UART_PARITY_SELECTION        UART_EVEN_PARITY

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_PE_INTERRUPT_DISABLE
				UART_PE_INTERRUPT_ENABLE
									*/

#define   UART_PE_INTERRUPT     	  UART_PE_INTERRUPT_DISABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_TXE_INTERRUPT_DISABLE
				UART_TXE_INTERRUPT_ENABLE
									*/

#define   UART_TXE_INTERRUPT     	  UART_TXE_INTERRUPT_ENABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_TCIE_INTERRUPT_DISABLE
				UART_TCIE_INTERRUPT_ENABLE
									*/

#define   UART_TCIE_INTERRUPT     	  UART_TCIE_INTERRUPT_DISABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_RXNE_INTERRUPT_DISABLE
				UART_RXNE_INTERRUPT_ENABLE
									*/

#define   UART_RXNE_INTERRUPT     	  UART_RXNE_INTERRUPT_DISABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_IDLE_INTERRUPT_DISABLE
				UART_IDLE_INTERRUPT_ENABLE
									*/

#define   UART_IDLE_INTERRUPT     	  UART_IDLE_INTERRUPT_DISABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_TX_DISABLE
				UART_TX_ENABLE
									*/

#define   UART_TX_EN     	 		  UART_TX_ENABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_RX_DISABLE
				UART_RX_ENABLE
									*/

#define   UART_RX_EN     	 		  UART_RX_ENABLE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_RX_WAKEUP_ACTIVE
				UART_RX_WAKEUP_MUTE
									*/

#define   UART_RX_WAKEUP     	 	 UART_RX_WAKEUP_MUTE

/******************************************************************************/

/******************************************************************************/
/* Options : 
				UART_NO_BREAK_TRANSMITTED
				UART_SEND_BREAK
									*/

#define   UART_BREAK_SEND     	 	 UART_NO_BREAK_TRANSMITTED

/******************************************************************************/

#endif
