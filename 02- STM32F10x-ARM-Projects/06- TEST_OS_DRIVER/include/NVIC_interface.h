/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V04                                                           */
/*   Date      : 25 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all NVIC Driver to make it more professional     */
/*               V03 : Update MNVIC_voidSetPriority function                   */
/*               V04 : Group and Sub as enum                                   */
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

typedef enum {
    MNVIC_GROUP_16_SUB_0 = 0x05FA0300,       //0 bit for sub & 4 bit For group   << 0
    MNVIC_GROUP_8_SUB_2  = 0x05FA0400,       //1 bit for sub & 3 bit For group   << 1
    MNVIC_GROUP_4_SUB_4  = 0x05FA0500,       //2 bit for sub & 2 bit For group   << 2
    MNVIC_GROUP_2_SUB_8  = 0x05FA0600,	     //3 bit for sub & 1 bit For group   << 3
    MNVIC_GROUP_0_SUB_16 = 0x05FA0700		 //4 bit for sub & 0 bit For group   << 4
}MNVIC_GROUP_SUB_t;


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
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
          Copy_u8GroupPriority(u8) -> Decimal number
		  Copy_u8SubPriority(u8)   -> Decimal number
		  Copy_u8Group(u32) :
				// Group priority options //
				#define     MNVIC_GROUP_16_SUB_0        0x05FA0300 //0 bit for sub & 4 bit For group   << 0
				#define     MNVIC_GROUP_8_SUB_2         0x05FA0400 //1 bit for sub & 3 bit For group   << 1
				#define     MNVIC_GROUP_4_SUB_4         0x05FA0500 //2 bit for sub & 2 bit For group   << 2
				#define     MNVIC_GROUP_2_SUB_8         0x05FA0600 //3 bit for sub & 1 bit For group   << 3
				#define     MNVIC_GROUP_0_SUB_16        0x05FA0700 //4 bit for sub & 0 bit For group   << 4

NOTE::
	Each priority field holds a priority value, 0-255. The lower the value,
	the greater the priority of the corresponding interrupt. The processor
	implements only bits[7:4] of each field
	** That is why i shift (copy_u8Priority << 4) by 4 **
*/
void MNVIC_voidSetPriority (NVIC_IRQn_t Copy_IRQn, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority , MNVIC_GROUP_SUB_t Copy_u8Group );
//-------------------------------------------------------------------------------------

#endif
