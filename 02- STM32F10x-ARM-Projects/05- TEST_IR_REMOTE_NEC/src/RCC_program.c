/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 12 September 2023                                             */
/*******************************************************************************/

#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include   "RCC_interface.h"
#include   "RCC_private.h"
#include   "RCC_config.h"


void RCC_voidInitSysClock(void)
{

		#if RCC_ClOCK_TYPE == RCC_HSI
			u32 Temp ;
			// Enable HSION - Default trimming = 16 - Disable HSE & HSEBYP & PLL 
			Temp = 0x00000081 ;
			// Clear Trimming Bits (BIT 3 ->  BIT 7)
			Temp &= ~(0x31 << 3);
			// Set Trimming Bits   (BIT 3 ->  BIT 7)
			Temp |= (RCC_TRIMMING_BITS << 3);
			// Enable HSION - Default trimming = 16 - Disable HSE & HSEBYP & PLL + TRIMMING_Bits Addition
			RCC_CR = Temp ;
			#if RCC_PLL == ENABLE
				u32 Temp2 ;
				Temp2 = 0x00000000;
				Temp2 |= (RCC_PLL_SW    << 0);      
				Temp2 |= (RCC_PLL_SRC   << 16);
				Temp2 |= (RCC_PLL_XTPRE << 17);
				Temp2 |= (RCC_PLL_MUL   << 18);
				Temp2 |= (RCC_MCO       << 24);
				RCC_CFGR = Temp2 ;
				// Enable PLL
				Temp |= (RCC_PLL << 24);
				RCC_CR = Temp ;
			#elif RCC_PLL == DISABLE 
				u32 Temp2 ;
				Temp2 = 0x00000000;
				Temp2 |= (RCC_HSI_SW    << 0);
				Temp2 |= (RCC_MCO       << 24);
				RCC_CFGR = Temp2 ;
			#else
				#error("You Chose Wrong choice")
			#endif
			
		#elif RCC_ClOCK_TYPE == RCC_HSE_RC
			u32 Temp ;
			// Enable HSE & HSEBYP - Default trimming = 16 - Disable HSION & PLL  
			Temp = 0x00050080 ;
			// Clear CSS Bit (BIT 18)
			Temp &= ~(0x1 << 18);
			// Set CSS Bit   (BIT 18)
			Temp |= (RCC_CLOCK_SECURITY_SYSTEM_BIT << 18);
			// Enable HSE & HSEBYP - Default trimming = 16 - Disable HSION & PLL + CLOCK_SECURITY_SYSTEM_BIT
			RCC_CR = Temp ;
			#if RCC_PLL == ENABLE
				u32 Temp2 ;
				Temp2 = 0x00000000;
				Temp2 |= (RCC_PLL_SW    << 0);      
				Temp2 |= (RCC_PLL_SRC   << 16);
				Temp2 |= (RCC_PLL_XTPRE << 17);
				Temp2 |= (RCC_PLL_MUL << 18);
				RCC_CFGR = Temp2 ;
				// Enable PLL
				Temp |= (RCC_PLL << 24);
				RCC_CR = Temp ;
			#elif RCC_PLL == DISABLE 
				u32 Temp2 ;
				Temp2 = 0x00000000;
				Temp2 |= (RCC_HSE_SW    << 0);
				Temp2 |= (RCC_MCO       << 24);
				RCC_CFGR = Temp2 ;
			#else
				#error("You Chose Wrong choice")
			#endif

		#elif RCC_ClOCK_TYPE == RCC_HSE_CRYSTAL
			u32 Temp ;
			// Enable HSE  - Default trimming = 16 - Disable HSION & HSEBYP & PLL  
			Temp = 0x00010080 ;
			// Clear CSS Bit (BIT 18)
			Temp &= ~(0x1 << 18);
			// Set CSS Bit   (BIT 18)
			Temp |= (RCC_CLOCK_SECURITY_SYSTEM_BIT << 18);
			// Enable HSE & HSEBYP - Default trimming = 16 - Disable HSION & PLL + CLOCK_SECURITY_SYSTEM_BIT
			RCC_CR = Temp ;
			#if RCC_PLL == ENABLE
				u32 Temp2 ;
				Temp2 = 0x00000000;
				Temp2 |= (RCC_PLL_SW    << 0);      
				Temp2 |= (RCC_PLL_SRC   << 16);
				Temp2 |= (RCC_PLL_XTPRE << 17);
				Temp2 |= (RCC_PLL_MUL << 18);
				RCC_CFGR = Temp2 ;
				// Enable PLL
				Temp |= (RCC_PLL << 24);
				RCC_CR = Temp ;
			#elif RCC_PLL == DISABLE
			    u32 Temp2 ;
				Temp2 = 0x00000000;
				Temp2 |= (RCC_HSE_SW    << 0);
				Temp2 |= (RCC_MCO       << 24);
				RCC_CFGR = Temp2 ;
			#else
				#error("You Chose Wrong choice")
			#endif
			
			
		#else
			#error("You Chose Wrong Clock")
		#endif
	
}



void RCC_voidEnableClock(u8 Copy_u8BusId  , u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR ,Copy_u8PerId);  break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
			
		}
	}
	else
	{
		/*  Return Error */
	}
	
	
}

void RCC_voidDisableClock(u8 Copy_u8BusId  , u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR ,Copy_u8PerId);  break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
			
		}
	}
	else
	{
		/*  Return Error */
	}
	
	
}

