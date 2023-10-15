/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V01                                                  */
/*  Date     : 15 October 2023                                      */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#ifndef _AUDIO_CONFIG_H
#define _AUDIO_CONFIG_H

 /* Choose GPIO PORT */
/* Options:
		GPIOA
		GPIOB
		GPIOC

*/
#define  AUDIO_PORT        GPIOA

 /* Please write pin pair  PORT,PIN For [R2R] DAC */
#define  AUDIO_DAC0_PIN    AUDIO_PORT,0
#define  AUDIO_DAC1_PIN    AUDIO_PORT,1
#define  AUDIO_DAC2_PIN    AUDIO_PORT,2
#define  AUDIO_DAC3_PIN    AUDIO_PORT,3
#define  AUDIO_DAC4_PIN    AUDIO_PORT,4
#define  AUDIO_DAC5_PIN    AUDIO_PORT,5
#define  AUDIO_DAC6_PIN    AUDIO_PORT,6
#define  AUDIO_DAC7_PIN    AUDIO_PORT,7
 
 /* Choose GPIO Frequency */
/* Options:
		OUTPUT_SPEED_10MHZ_PP
		OUTPUT_SPEED_2MHZ_PP
		OUTPUT_SPEED_50MHZ_PP

*/
#define AUDIO_DAC_PINS_SPEED       OUTPUT_SPEED_2MHZ_PP
 
#endif
