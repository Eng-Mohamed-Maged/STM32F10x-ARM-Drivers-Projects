/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 16 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all NVIC Driver to make it more professional     */
/*******************************************************************************/
#ifndef NVIC_INTERFACE_H
#define	NVIC_INTERFACE_H

/* enum for all external interrupt 0:59 */
typedef enum {
	WWDG_IRQ    = 0       ,
	PVD_IRQ               ,
	TAMPER_IRQ            ,
	RTC_IRQ               ,
	FLASH_IRQ             ,
	RCC_IRQ               ,
	EXTI0_IRQ             ,
	EXTI1_IRQ             ,
	EXTI2_IRQ             ,
	EXTI3_IRQ             ,
	EXTI4_IRQ             ,
	DMA1_Channel1_IRQ     ,
	DMA1_Channel2_IRQ     ,
	DMA1_Channel3_IRQ     ,
	DMA1_Channel4_IRQ     ,
	DMA1_Channel5_IRQ     ,
	DMA1_Channel6_IRQ     ,
	DMA1_Channel7_IRQ     ,
	ADC1_2_IRQ            ,
	USB_HP_CAN_IRQ        ,
	USB_LP_CAN_IRQ        ,
	CAN_RX1_IRQ           ,
	CAN_SCE_IRQ           ,
	EXTI9_5_IRQ           ,
	TIM1_BRK_IRQ          ,
	TIM1_UP_IRQ           ,
	TIM1_TRG_COM_IRQ      ,
	TIM1_CC_IRQ           ,
	TIM2_IRQ              ,
	TIM3_IRQ              ,
	TIM4_IRQ              ,
	I2C1_EV_IRQ           ,
	I2C1_ER_IRQ           ,
	I2C2_EV_IRQ           ,
	I2C2_ER_IRQ           ,
	SPI1_IRQ              ,
	SPI2_IRQ              ,
	USART1_IRQ            ,
	USART2_IRQ            ,
	USART3_IRQ            ,
	EXTI15_10_IRQ         ,
	RTCAlarm_IRQ          ,
	USBWakeup_IRQ         ,
	TIM8_BRK_IRQ          ,
	TIM8_UP_IRQ           ,
	TIM8_TRG_COM_IRQ      ,
	TIM8_CC_IRQ           ,
	ADC3_IRQ              ,
	FSMC_IRQ              ,
	SDIO_IRQ              ,
	TIM5_IRQ              ,
	SPI3_IRQ              ,
	UART4_IRQ             ,
	UART5_IRQ             ,
	TIM6_IRQ              ,
	TIM7_IRQ              ,
	DMA2_Channel1_IRQ     ,
	DMA2_Channel2_IRQ     ,
	DMA2_Channel3_IRQ     ,
	DMA2_Channel4_IRQ               
}NVIC_IRQn_t;
//-------------------------------------------------------------------------------------
/*
 MNVIC_voidInit - > Initialize the periority system (determine the number of group priorities and sub priorties) 
*/
void MNVIC_voidInit(void) ;
//-------------------------------------------------------------------------------------

/* 
  * MNVIC_voidEnableInterrupt - > Enable a specific external interrupt   
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/
void MNVIC_voidEnableInterrupt       (NVIC_IRQn_t Copy_IRQn);
//-------------------------------------------------------------------------------------

/* 
  * MNVIC_voidDisableInterrupt - > Disable a specific external interrupt   
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/
void MNVIC_voidDisableInterrupt      (NVIC_IRQn_t Copy_IRQn);
//-------------------------------------------------------------------------------------

/* 
  * MNVIC_voidSetPendingFlag - > set pending flag for a specific external interrupt   
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/

void MNVIC_voidSetPendingFlag        (NVIC_IRQn_t Copy_IRQn);
//-------------------------------------------------------------------------------------

/* 
  * MNVIC_voidClearPendingFlag - > Clear pending flag for a specific external interrupt   
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/

void MNVIC_voidClearPendingFlag      (NVIC_IRQn_t Copy_IRQn);
//-------------------------------------------------------------------------------------

/* 
  * MNVIC_u8GetPendingFlag - > Get the pending flag state    
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
  * o/p : (u8) 0 or 1
*/

u8 MNVIC_u8GetPendingFlag            (NVIC_IRQn_t Copy_IRQn);
//-------------------------------------------------------------------------------------

/* 
  * MNVIC_u8GetActiveFlag - > Get the Active flag state    
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
  * o/p : (u8) 0 or 1
*/


u8   MNVIC_u8GetActiveFlag           (NVIC_IRQn_t Copy_IRQn);
//-------------------------------------------------------------------------------------

/* 
  * MNVIC_voidSetPriority - > Set periority for a specific external interrupt   
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59  /  Interrupt periority (u8) 0:15
*/

void MNVIC_voidSetPriority           (NVIC_IRQn_t Copy_IRQn, u8 Copy_u8Priority);
//-------------------------------------------------------------------------------------

#endif
