/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 12 September 2023                                             */
/*******************************************************************************/
#ifndef	RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define RCC_AHB             0
#define RCC_APB1            1
#define RCC_APB2            2

/***********  AHB ************/
#define RCC_AHB_DMA1        0
#define RCC_AHB_DMA2        1
#define RCC_AHB_SRAM        2
#define RCC_AHB_FLITF       4
#define RCC_AHB_CRCE        6
#define RCC_AHB_FSMC        8
#define RCC_AHB_SDIO        10
/****************************/

/**********  APB2 ************/
#define RCC_APB2_AFIO       0
#define RCC_APB2_GPIOA      2
#define RCC_APB2_GPIOB      3
#define RCC_APB2_GPIOC      4
#define RCC_APB2_GPIOD      5
#define RCC_APB2_GPIOE      6
#define RCC_APB2_GPIOF      7
#define RCC_APB2_GPIOG      8
#define RCC_APB2_ADC1		9
#define RCC_APB2_ADC2		10
#define RCC_APB2_Timer1		11
#define RCC_APB2_SPI1		12
#define RCC_APB2_Timer8		13
#define RCC_APB2_USART1		14
#define RCC_APB2_ADC3		15
#define RCC_APB2_Timer9		19
#define RCC_APB2_Timer10	20
#define RCC_APB2_Timer11	21
/****************************/

/**********  APB1 ************/
#define RCC_APB1_Timer2     0
#define RCC_APB1_Timer3     1
#define RCC_APB1_Timer4     2
#define RCC_APB1_Timer5     3
#define RCC_APB1_Timer6     4
#define RCC_APB1_Timer7     5
#define RCC_APB1_Timer12    6
#define RCC_APB1_Timer13    7
#define RCC_APB1_Timer14    8
#define RCC_APB1_WWDG       11
#define RCC_APB1_SPI2		14
#define RCC_APB1_SPI3		15
#define RCC_APB1_USART2		17
#define RCC_APB1_USART3		18
#define RCC_APB1_UART4		19
#define RCC_APB1_UART5		20
#define RCC_APB1_I2C1		21
#define RCC_APB1_I2C2		22
#define RCC_APB1_USB		23
#define RCC_APB1_CAN		25
#define RCC_APB1_BKP		27
#define RCC_APB1_PWR		28
#define RCC_APB1_DAC		29
/****************************/




void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId  , u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId  , u8 Copy_u8PerId);

#endif
