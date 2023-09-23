/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 12 September 2023                                             */
/*******************************************************************************/
#ifndef	RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Registers Definitions */

#define RCC_CR           *((volatile u32*)0x40021000)
#define RCC_CFGR         *((volatile u32*)0x40021004)
#define RCC_CIR          *((volatile u32*)0x40021008)
#define RCC_APB2RSTR     *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR     *((volatile u32*)0x40021010)
#define RCC_AHBENR       *((volatile u32*)0x40021014)
#define RCC_APB2ENR      *((volatile u32*)0x40021018)
#define RCC_APB1ENR      *((volatile u32*)0x4002101C)
#define RCC_BDCR         *((volatile u32*)0x40021020)
#define RCC_CSR          *((volatile u32*)0x40021024)

/*********************************************/
#define  RCC_HSI                         0
#define  RCC_HSE_RC                      1
#define  RCC_HSE_CRYSTAL                 2
/*********************************************/
#define  DISABLE                         0
#define  ENABLE                          1
/*********************************************/
#define  RCC_HSI_DIV_BY_2_SRC            0
#define  RCC_HSE_NOT_DIV_SRC             1
#define  RCC_HSE_NOT_DIV_XTPRE           0
#define  RCC_HSE_DIV_BY_2_XTPRE          1
/*********************************************/
#define  RCC_HSI_SW                      0                                                                                 
#define  RCC_HSE_SW                      1  
/*********************************************/                                                                        
#define  RCC_NO_CLOCK_MCO                0                                                                                 
#define  RCC_SYSTEM_CLOCK_MCO            4                                                                                 
#define  RCC_HSI_CLOCK_MCO               5                                                                                 
#define  RCC_HSE_CLOCK_MCO               6                                                                                 
#define  RCC_PLL_DIV_BY_2_CLOCK_MCO      7  
/*********************************************/
#if (RCC_PLL == ENABLE)
	#define  RCC_PLL_SW                  2
#endif
/*********************************************/
#define  RCC_PLL_MUL_2                   0
#define  RCC_PLL_MUL_3                   1
#define  RCC_PLL_MUL_4                   2
#define  RCC_PLL_MUL_5                   3
#define  RCC_PLL_MUL_6                   4
#define  RCC_PLL_MUL_7                   5
#define  RCC_PLL_MUL_8                   6
#define  RCC_PLL_MUL_9                   7
#define  RCC_PLL_MUL_10                  8
#define  RCC_PLL_MUL_11                  9
#define  RCC_PLL_MUL_12                  10
#define  RCC_PLL_MUL_13                  11
#define  RCC_PLL_MUL_14                  12
#define  RCC_PLL_MUL_15                  13
#define  RCC_PLL_MUL_16                  14



#endif
