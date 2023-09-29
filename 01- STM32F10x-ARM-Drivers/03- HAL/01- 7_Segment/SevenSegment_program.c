/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 29 Srptember 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
#include "SevenSegment_config.h"


void  SevenSegment_voidDisplay(u8 Copy_u8SevenSegmenNum ,u16 Copy_u16Value )
{
	switch(Copy_u8SevenSegmenNum)
	{
		case CONNECTED_PORT_FIRST_SEGMENT :
		{
				#if FIRST_SEVEN_SEGMENT_TYPE == COMMEN_CATHOD
					MGPIO_voidSetPortDirection(CONNECTED_PORT_FIRST_SEGMENT ,OUTPUT_PORT_SPEED_10MHZ_PP ) ;
					MGPIO_voidSetPortValue(CONNECTED_PORT_FIRST_SEGMENT,Copy_u16Value);
				#elif FIRST_SEVEN_SEGMENT_TYPE == COMMEN_ANODE
					Copy_u16Value ^= 0x1111;
					MGPIO_voidSetPortDirection(CONNECTED_PORT_FIRST_SEGMENT ,OUTPUT_PORT_SPEED_10MHZ_PP ) ;
					MGPIO_voidSetPortValue(CONNECTED_PORT_FIRST_SEGMENT,Copy_u16Value);
				#else	#error ("You chose wrong Type")
				#endif
		}break;
		case CONNECTED_PORT_SECOND_SEGMENT :
		{
				#if SECOND_SEVEN_SEGMENT_TYPE == COMMEN_CATHOD
					MGPIO_voidSetPortDirection(CONNECTED_PORT_SECOND_SEGMENT ,OUTPUT_PORT_SPEED_10MHZ_PP ) ;
					MGPIO_voidSetPortValue(CONNECTED_PORT_SECOND_SEGMENT,Copy_u16Value);
				#elif SECOND_SEVEN_SEGMENT_TYPE == COMMEN_ANODE
					Copy_u16Value ^= 0x1111;
					MGPIO_voidSetPortDirection(CONNECTED_PORT_SECOND_SEGMENT ,OUTPUT_PORT_SPEED_10MHZ_PP ) ;
					MGPIO_voidSetPortValue(CONNECTED_PORT_SECOND_SEGMENT,Copy_u16Value);
				#else	#error ("You chose wrong Type")
				#endif	
		}break;
		default: break;		
	}
}