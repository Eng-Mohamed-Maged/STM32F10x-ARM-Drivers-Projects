/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V01                                                  */
/*  Date     : 15 October 2023                                      */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#ifndef _AUDIO_INTERFACE_H
#define _AUDIO_INTERFACE_H




/********************************************************************/
/*  Function     : AUDIO_voidInit                                   */
/*  Inputs       : NONE                                             */
/*  Outputs      : NONE                                             */
/*  Description  : Initialization of Audio DAC                      */
/********************************************************************/
void AUDIO_voidInit (void);
  








/********************************************************************/
/*  Function     : AUDIO_voidSetSongDAC                             */
/*  Inputs       : Copy_u8Arr      => Array of chars for song       */
/*                 Copy_u16SongLen =>  song length                  */
/*  Outputs      : NONE                                             */
/*  Description  : Set Audio DAC song                               */
/********************************************************************/
void AUDIO_voidSetSongDAC (u8 * Copy_u8Arr , u16 Copy_u16SongLen);














#endif
