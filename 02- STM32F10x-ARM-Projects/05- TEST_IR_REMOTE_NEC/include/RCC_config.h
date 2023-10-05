/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 12 September 2023                                             */
/*******************************************************************************/
#ifndef	RCC_CONFIG_H
#define RCC_CONFIG_H
/*********************************************/	
/*Choose:
			RCC_HSI
			RCC_HSE_RC
			RCC_HSE_CRYSTAL                           */
#define  RCC_ClOCK_TYPE                  RCC_HSI
/*********************************************/                                                                        
/*Choose:
			0 -> 31                                   */
#define  RCC_TRIMMING_BITS               16  
/*Choose:
			ENABLE
			DISABLE                                   */
#define  RCC_CLOCK_SECURITY_SYSTEM_BIT   DISABLE
/*********************************************/     
/*Choose:
			RCC_NO_CLOCK_MCO
			RCC_SYSTEM_CLOCK_MCO
			RCC_HSI_CLOCK_MCO
			RCC_HSE_CLOCK_MCO
			RCC_PLL_DIV_BY_2_CLOCK_MCO	           	  */                                                                   
#define  RCC_MCO                         RCC_NO_CLOCK_MCO     
/*********************************************/  
/*Choose:
			ENABLE
			DISABLE                                   */                                                                      
#define  RCC_PLL                         DISABLE
#if (RCC_PLL == ENABLE)
    /*Choose:
			    RCC_HSI_DIV_BY_2_SRC
			    RCC_HSE_NOT_DIV_SRC                   */                                                                                                                   
	#define  RCC_PLL_SRC                 RCC_HSE_NOT_DIV_SRC
	/*Choose:
			    RCC_HSE_NOT_DIV_XTPRE
			    RCC_HSE_DIV_BY_2_XTPRE                */
	#define  RCC_PLL_XTPRE               RCC_HSE_NOT_DIV_XTPRE
	/*Choose:
			    RCC_PLL_MUL_2
 	 	 	 	RCC_PLL_MUL_3
 	 	 	 	RCC_PLL_MUL_4
				RCC_PLL_MUL_5
			 	RCC_PLL_MUL_6
				RCC_PLL_MUL_7
				RCC_PLL_MUL_8
			 	RCC_PLL_MUL_9
				RCC_PLL_MUL_10
			 	RCC_PLL_MUL_11
				RCC_PLL_MUL_12
			 	RCC_PLL_MUL_13
				RCC_PLL_MUL_14
				RCC_PLL_MUL_15
				RCC_PLL_MUL_16
												      */
	#define  RCC_PLL_MUL                 RCC_PLL_MUL_4
#elif (RCC_PLL == DISABLE)
#else
	#error("You Chose Wrong choice")
#endif

#endif
