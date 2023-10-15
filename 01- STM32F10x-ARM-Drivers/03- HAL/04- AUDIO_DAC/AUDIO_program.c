/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V01                                                  */
/*  Date     : 15 October 2023                                      */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/

/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/********************************************************************/
/* MCAL includes */
#include   "GPIO_interface.h"
/********************************************************************/
/* module includes */
#include "AUDIO_interface.h"
#include "AUDIO_config.h"
#include "AUDIO_private.h"
 /********************************************************************/
 u16 global_u16Index = 0 ;

 /********************************************************************/
 /* Array for  for holding [PORT],[PIN] */
u8 AUDIO_globalPortPins[16] = { AUDIO_DAC0_PIN    ,
	                            AUDIO_DAC1_PIN    ,
	                            AUDIO_DAC2_PIN    ,
	                            AUDIO_DAC3_PIN    ,
	                            AUDIO_DAC4_PIN    ,
	                            AUDIO_DAC5_PIN    ,
	                            AUDIO_DAC6_PIN    ,
	                            AUDIO_DAC7_PIN    };
	
/********************************************************************/

/********************************************************************/
/*  Function     : AUDIO_voidInit                                   */
/*  Inputs       : NONE                                             */
/*  Outputs      : NONE                                             */
/*  Description  : Initialization of Audio DAC                      */
/********************************************************************/
void AUDIO_voidInit (void)
{
	for (u8 i = 0 ; i < 16 ; i += 2)
	{
		MGPIO_voidSetPinDirection (AUDIO_globalPortPins[i],AUDIO_globalPortPins[i+1],AUDIO_DAC_PINS_SPEED) ;
	}
}





/********************************************************************/
/*  Function     : AUDIO_voidSetSongDAC                             */
/*  Inputs       : Copy_u8Arr      => Array of chars for song       */
/*                 Copy_u16SongLen =>  song length                  */
/*  Outputs      : NONE                                             */
/*  Description  : Set Audio DAC song                               */
/********************************************************************/
void AUDIO_voidSetSongDAC (u8 * Copy_u8Arr , u16 Copy_u16SongLen)
{
	MGPIO_voidSetPortValue(AUDIO_PORT,Copy_u8Arr[global_u16Index]);
	global_u16Index++;
	if(global_u16Index == Copy_u16SongLen)
	{
		global_u16Index = 0;
	}

}


