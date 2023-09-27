/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 18 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void  MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI_LINES_t Copy_Line ,MAFIO_PORTS_t Copy_PortMap)
{
/*	
//              NOT OPTIMIZED                 //
	u8 Local_u8RegIndex = 0 ;
	// From EXTI0 : EXTI3  //
	if (Copy_Line <= MAFIO_EXTI3)
	{
		Local_u8RegIndex = 0 ;
	}
	// From EXTI4 : EXTI7  //
	else if (Copy_Line <= MAFIO_EXTI7)
	{
		Local_u8RegIndex = 1 ;
		Copy_Line = Copy_Line - 4 ;     // To Count from 0 //
	}
	// From EXTI8 : EXTI11  //
	else if (Copy_Line <= MAFIO_EXTI11)
	{
		Local_u8RegIndex = 2 ;
		Copy_Line = Copy_Line - 8 ;    // To Count from 0 //
	}
	// From EXTI12 : EXTI15  //
	else if (Copy_Line <= MAFIO_EXTI15)
	{
		Local_u8RegIndex = 3 ;
		Copy_Line = Copy_Line - 12 ;    // To Count from 0 //
	}
	else
	{
		// Return Error //
	}
//              NOT OPTIMIZED                 //
*/


//              # OPTIMIZED  #               //

	// Get the register index //
	u8 Local_u8RegIndex = Copy_Line / 4 ;
	// Get the line index //
	u8 Local_u8LineIndex = Copy_Line % 4 ;

//              # OPTIMIZED  #               //

	/* Clear the four bits first */
	AFIO -> EXTICR[Local_u8RegIndex] &= ~ (0b1111 << (Local_u8LineIndex * 4)) ;
	/* Write into the four bits */
	AFIO -> EXTICR[Local_u8RegIndex] |=   (Copy_PortMap << (Local_u8LineIndex * 4)) ;

}
