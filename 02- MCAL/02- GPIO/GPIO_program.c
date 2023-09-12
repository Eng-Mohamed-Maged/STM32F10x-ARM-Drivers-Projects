/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 12 September  2023                                            */
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetPinDirection(u8 Copy_u8Port  , u8 Copy_u8Pin ,u8 Copy_u8Mode )
{
	switch(Copy_u8Port)
	{
		case GPIOA:
		{
			/* For Pin0 to Pin7  */
			if(Copy_u8Pin <= 7 ) 
			{
			  /* Clear the 4 Bits for selected Pin */
			  GPIOA_CRL &= ~ (( 0b1111 )   << ( Copy_u8Pin * 4 ));
			  /* Set the 4 Bits for selected Pin   */
			  GPIOA_CRL |= (Copy_u8Mode) << ( Copy_u8Pin * 4 );
			}
			/* For Pin8 to Pin15 */
		    else if(Copy_u8Pin <=15 )
			{
			  /* To start from 0 */	
		      Copy_u8Pin = Copy_u8Pin - 8;
			  /* Clear the 4 Bits for selected Pin */
			  GPIOA_CRH &= ~  (( 0b1111 )    << ( Copy_u8Pin * 4 ));
			  /* Set the 4 Bits for selected Pin   */
			  GPIOA_CRH |= (Copy_u8Mode ) << ( Copy_u8Pin * 4 );
			}
		}break;


		case GPIOB:
		{
			/* For Pin0 to Pin7  */
			if(Copy_u8Pin <= 7 ) 
			{
			  /* Clear the 4 Bits for selected Pin */
			  GPIOB_CRL &= ~ (( 0b1111 )   << ( Copy_u8Pin * 4 ));
			  /* Set the 4 Bits for selected Pin   */
			  GPIOB_CRL |= (Copy_u8Mode) << ( Copy_u8Pin * 4 );
			}
			/* For Pin8 to Pin15 */
		    else if(Copy_u8Pin <=15 )
			{
			  /* To start from 0 */	
		      Copy_u8Pin = Copy_u8Pin - 8;
			  /* Clear the 4 Bits for selected Pin */
			  GPIOB_CRH &= ~  (( 0b1111 )    << ( Copy_u8Pin * 4 ));
			  /* Set the 4 Bits for selected Pin   */
			  GPIOB_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );
			}
		}break;
		case GPIOC:
		{
			/* For Pin0 to Pin7  */
			if(Copy_u8Pin <= 7 ) 
			{
			  /* Clear the 4 Bits for selected Pin */
			  GPIOC_CRL &= ~ (( 0b1111 )   << ( Copy_u8Pin * 4 ));
			  /* Set the 4 Bits for selected Pin   */
			  GPIOC_CRL |= (Copy_u8Mode) << ( Copy_u8Pin * 4 );
			}
			/* For Pin8 to Pin15 */
		    else if(Copy_u8Pin <=15 )
			{
			  /* To start from 0 */	
		      Copy_u8Pin = Copy_u8Pin - 8;
			  /* Clear the 4 Bits for selected Pin */
			  GPIOC_CRH &= ~  (( 0b1111 )    << ( Copy_u8Pin * 4 ));
			  /* Set the 4 Bits for selected Pin   */
			  GPIOC_CRH |= ( Copy_u8Mode ) << ( Copy_u8Pin * 4 );
			}
		}break;
		default : break;
	}
}
void MGPIO_voidSetPinValue(u8 Copy_u8Port  , u8 Copy_u8Pin ,u8 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
		case GPIOA:
		{
			/* If the value is High */
			if(Copy_u8Value == GPIO_HIGH )
			{
			  /* Set Pin */
			  SET_BIT( GPIOA_ODR , Copy_u8Pin);
			}
			/* If the value is Low */
		    else if(Copy_u8Value == GPIO_LOW )
			{
			  /* Clear Pin */
			  CLR_BIT( GPIOA_ODR , Copy_u8Pin);
			}
		}break;
	
		case GPIOB:
		{
			/* If the value is High */
			if(Copy_u8Value == GPIO_HIGH )
			{
			  /* Set Pin */
			  SET_BIT( GPIOB_ODR , Copy_u8Pin);
			}
			/* If the value is Low */
		    else if(Copy_u8Value == GPIO_LOW )
			{
			  /* Clear Pin */
			  CLR_BIT( GPIOB_ODR , Copy_u8Pin);
			}
		}break;
		case GPIOC:
		{
			/* If the value is High */
			if(Copy_u8Value == GPIO_HIGH )
			{
			  /* Set Pin */
			  SET_BIT( GPIOC_ODR , Copy_u8Pin);
			}
			/* If the value is Low */
		    else if(Copy_u8Value == GPIO_LOW )
			{
			  /* Clear Pin */
			  CLR_BIT( GPIOC_ODR , Copy_u8Pin);
			}
		}break;
		default : break;
	}
}
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port  , u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0 ;
	switch(Copy_u8Port)
	{
		case GPIOA:
		{
			/* Get the value of the selected pin */
			LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin ) ;
		}break;
	
		case GPIOB:
		{
			/* Get the value of the selected pin */
			LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin ) ;
		}break;
		case GPIOC:
		{
			/* Get the value of the selected pin */
			LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin ) ;
		}break;
	}
	return LOC_u8Result ;
}


void MGPIO_voidSetPortDirection(u8 Copy_u8Port ,u32 Copy_u32Mode )
{
	switch(Copy_u8Port)
	{
		case GPIOA:
		{
			  /* First Clear the 8 Low Pins               */
			  GPIOA_CRL &= 0x00000000 ;
			  /* Set the 16 Low Bits for selected PORT    */
			  GPIOA_CRL |= (( Copy_u32Mode ) << ( 0 ));
			  
			  /* First Clear the 8 High Pins              */
			  GPIOA_CRH &= 0x00000000 ;
			  /* Set the 16 High Bits for selected PORT   */
			  GPIOA_CRH |= (( Copy_u32Mode ) << ( 0 ));
		}break;


		case GPIOB:
		{
			  /* First Clear the 8 Low Pins               */
			  GPIOB_CRL &= 0x00000000 ;
			  /* Set the 16 Low Bits for selected PORT    */
			  GPIOB_CRL |= (( Copy_u32Mode ) << ( 0 ));
			  
			  /* First Clear the 8 High Pins              */
			  GPIOB_CRH &= 0x00000000 ; 
			  /* Set the 16 High Bits for selected PORT   */
			  GPIOB_CRH |= (( Copy_u32Mode ) << ( 0 ));
		}break;
		case GPIOC:
		{
			  /* First Clear the 8 Low Pins               */
			  GPIOC_CRL &= 0x00000000 ;
			  /* Set the 16 Low Bits for selected PORT    */
			  GPIOC_CRL |= (( Copy_u32Mode ) << ( 0 ));
			  
			  /* First Clear the 8 High Pins              */
			  GPIOC_CRH &= 0x00000000 ;
			  /* Set the 16 High Bits for selected PORT   */
			  GPIOC_CRH |= (( Copy_u32Mode ) << ( 0 ));
		}break;
		default : break;
	}
}

void MGPIO_voidSetPortValue(u8 Copy_u8Port ,u16 Copy_u16Value )
{
	switch(Copy_u8Port)
	{
		case GPIOA:
		{
			  /* Clear the 16 Bits */
			  GPIOA_ODR &= 0x0000;
			  /* Set the 16 Bits */
			  GPIOA_ODR |= ( Copy_u16Value ) << ( 0 );
		}break;


		case GPIOB:
		{
			  /* Clear the 16 Bits */
			  GPIOB_ODR &= 0x0000;
			  /* Set the 16 Bits */
			  GPIOB_ODR |= ( Copy_u16Value ) << ( 0 );
		}break;
		case GPIOC:
		{
			  /* Clear the 16 Bits */
			  GPIOB_ODR &= 0x0000;
			  /* Set the 16 Bits */
			  GPIOB_ODR |= ( Copy_u16Value ) << ( 0 );
		}break;
		default : break;
	}
}

void MGPIO_voidSetOrResetPinValue_BSRR_BRR(u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
		case GPIOA:
		{
			/* If the value is High */
			if(Copy_u8Value == GPIO_HIGH )
			{
			  /* Set Pin */
			  GPIOA_BSRR = (1 << Copy_u8Pin)    ;
			}
			/* If the value is Low */
		    else if(Copy_u8Value == GPIO_LOW )
			{
			  /* Reset Pin */
			        /* USING BSRR */
		//    GPIOA_BSRR = (1 << (Copy_u8Pin + 16))
					/* USING BRR */
			  GPIOA_BRR = (1 << (Copy_u8Pin))	 ;
			}
		}break;
	
		case GPIOB:
		{
			/* If the value is High */
			if(Copy_u8Value == GPIO_HIGH )
			{
			  /* Set Pin */
			  GPIOB_BSRR = (1 << Copy_u8Pin)   ;
			}
			/* If the value is Low */
		    else if(Copy_u8Value == GPIO_LOW )
			{
			  /* Reset Pin */
					/* USING BSRR */
		//	  GPIOB_BSRR = (1 << (Copy_u8Pin + 16))
					/* USING BRR */
			  GPIOB_BRR = (1 << (Copy_u8Pin))	 ;
			}
		}break;
		case GPIOC:
		{
			/* If the value is High */
			if(Copy_u8Value == GPIO_HIGH )
			{
			  /* Set Pin */
			  GPIOC_BSRR = (1 << Copy_u8Pin)   ;
			}
			/* If the value is Low */
		    else if(Copy_u8Value == GPIO_LOW )
			{
			  /* Reset Pin */
					/* USING BSRR */
		//	  GPIOC_BSRR = (1 << (Copy_u8Pin + 16))
					/* USING BRR */
			  GPIOC_BRR = (1 << (Copy_u8Pin))	;

			}
		}break;
		default : break;
	}
}



/*
void MGPIO_voidPinLock_LCKR(u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
		case GPIOA:
		{
			 If the value is High
			if(Copy_u8Value == GPIO_HIGH )
			{
			   Set Pin
			  GPIOA_BSRR = (1 << Copy_u8Pin)
			}
			 If the value is Low
		    else if(Copy_u8Value == GPIO_LOW )
			{
			   Reset Pin
			  GPIOA_BSRR = (1 << (Copy_u8Pin + 16))
			}
		}break;
	
		case GPIOB:
		{
			 If the value is High
			if(Copy_u8Value == GPIO_HIGH )
			{
			   Set Pin
			  GPIOB_BSRR = (1 << Copy_u8Pin)
			}
			 If the value is Low
		    else if(Copy_u8Value == GPIO_LOW )
			{
			   Reset Pin
			  GPIOB_BSRR = (1 << (Copy_u8Pin + 16))
			}
		}break;
		case GPIOC:
		{
			 If the value is High
			if(Copy_u8Value == GPIO_HIGH )
			{
			   Set Pin
			  GPIOC_BSRR = (1 << Copy_u8Pin)
			}
			 If the value is Low
		    else if(Copy_u8Value == GPIO_LOW )
			{
			   Reset Pin
			  GPIOC_BSRR = (1 << (Copy_u8Pin + 16))
			}
		}break;
		default : break;
	}
} */
