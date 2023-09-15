/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 15 September 2023                                             */
/*******************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "NVIC_interface.h"
#include  "NVIC_private.h"
#include  "NVIC_config.h"



void MNVIC_voidInit(void)
{
	/* NOTE : USING SCB peripheral inside NVIC isn't CORRECT  */
    #define	 SCB_AIRCR   *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;
}

void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx , u8 Copy_u8Priority)
{
	/* Number of peripheral is 59 */
	if(Copy_u8PeripheralIdx <60)
	{
		NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority ;
	}
	else
	{
		/* Return Error */
	}

}


void MNVIC_voidEnableInterrupt (u8 Copy_u8InterruptNum)
{
	/* From peripheral 0 to 31 */
	if(Copy_u8InterruptNum <=31)
	{
		/* Not optimized */
	//  SET_BIT(NVIC_ISER0,Copy_u8InterruptNum);
		/* Modification */
		NVIC_ISER0 = ( 1 << Copy_u8InterruptNum);
	}
	/* From peripheral 32 to 59 */
	else if(Copy_u8InterruptNum <=59)
	{
		/* To start from 0 */
		Copy_u8InterruptNum -= 32 ;
		/* Not optimized */
	//  SET_BIT(NVIC_ISER1,Copy_u8InterruptNum);
		/* Modification */
	    NVIC_ISER1 = ( 1 << Copy_u8InterruptNum);
	}
	else
	{
		/* Return Error */
	}
	
}

void MNVIC_voidDisableInterrupt (u8 Copy_u8InterruptNum)
{
	/* From peripheral 0 to 31 */
	if(Copy_u8InterruptNum <=31)
	{
		/* Not optimized */
	//  SET_BIT(NVIC_ICER0,Copy_u8InterruptNum);
		/* Modification */
		NVIC_ICER0 = ( 1 << Copy_u8InterruptNum);
	}
	/* From peripheral 32 to 59 */
	else if(Copy_u8InterruptNum <=59)
	{
		/* To start from 0 */
		Copy_u8InterruptNum -= 32 ;
		/* Not optimized */
	//  SET_BIT(NVIC_ICER1,Copy_u8InterruptNum);
		/* Modification */
	    NVIC_ICER1 = ( 1 << Copy_u8InterruptNum);
	}
	else
	{
		/* Return Error */
	}
	
}

void MNVIC_voidSetPendingFlag (u8 Copy_u8InterruptNum)
{
	/* From peripheral 0 to 31 */
	if(Copy_u8InterruptNum <=31)
	{
		/* Not optimized */
	//  SET_BIT(NVIC_ISPR0,Copy_u8InterruptNum);
		/* Modification */
		NVIC_ISPR0 = ( 1 << Copy_u8InterruptNum);
	}
	/* From peripheral 32 to 59 */
	else if(Copy_u8InterruptNum <=59)
	{
		/* To start from 0 */
		Copy_u8InterruptNum -= 32 ;
		/* Not optimized */
	//  SET_BIT(NVIC_ISPR1,Copy_u8InterruptNum);
		/* Modification */
	    NVIC_ISPR1 = ( 1 << Copy_u8InterruptNum);
	}
	else
	{
		/* Return Error */
	}
	
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8InterruptNum)
{
	/* From peripheral 0 to 31 */
	if(Copy_u8InterruptNum <=31)
	{
		/* Not optimized */
	//  SET_BIT(NVIC_ICPR0,Copy_u8InterruptNum);
		/* Modification */
		NVIC_ICPR0 = ( 1 << Copy_u8InterruptNum);
	}
	/* From peripheral 32 to 59 */
	else if(Copy_u8InterruptNum <=59)
	{
		/* To start from 0 */
		Copy_u8InterruptNum -= 32 ;
		/* Not optimized */
	//  SET_BIT(NVIC_ICPR1,Copy_u8InterruptNum);
		/* Modification */
	    NVIC_ICPR1 = ( 1 << Copy_u8InterruptNum);
	}
	else
	{
		/* Return Error */
	}
	
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8InterruptNum)
{
	u8 Local_u8Result;
	/* From peripheral 0 to 31 */
	if(Copy_u8InterruptNum <=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8InterruptNum);
	}
	/* From peripheral 32 to 59 */
	else if(Copy_u8InterruptNum <=59)
	{
		/* To start from 0 */
		Copy_u8InterruptNum -= 32 ;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8InterruptNum);
	}
	else
	{
		/* Return Error */
	}
	
	return Local_u8Result ;
}
