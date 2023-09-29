/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V01  												*/
/*	Date	 : 29 September 2023                                    */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#ifndef LEDMTX_CONFIG_H
#define LEDMTX_CONFIG_H

/* Please write pin pair  PORT,PIN For Rows */
#define  LEDMTX_ROW0_PIN    GPIOA,0
#define  LEDMTX_ROW1_PIN    GPIOA,1
#define  LEDMTX_ROW2_PIN    GPIOA,2
#define  LEDMTX_ROW3_PIN    GPIOA,3
#define  LEDMTX_ROW4_PIN    GPIOA,4
#define  LEDMTX_ROW5_PIN    GPIOA,5
#define  LEDMTX_ROW6_PIN    GPIOA,6
#define  LEDMTX_ROW7_PIN    GPIOA,7
/* Please write pin pair  PORT,PIN For Columns*/

#define  LEDMTX_COL0_PIN    GPIOB,0
#define  LEDMTX_COL1_PIN    GPIOB,1
#define  LEDMTX_COL2_PIN    GPIOB,5
#define  LEDMTX_COL3_PIN    GPIOB,6
#define  LEDMTX_COL4_PIN    GPIOB,7
#define  LEDMTX_COL5_PIN    GPIOB,8
#define  LEDMTX_COL6_PIN    GPIOB,9
#define  LEDMTX_COL7_PIN    GPIOB,10

/* Choose GPIO Frequency */
/* Options:
		OUTPUT_SPEED_10MHZ_PP
		OUTPUT_SPEED_2MHZ_PP
		OUTPUT_SPEED_50MHZ_PP

*/
#define LEDMTX_PINS_SPEED       OUTPUT_SPEED_2MHZ_PP      


/* Choose LEDMTX FPS */
#define LEDMTX_Frame_PER_SECOND          50

/* LEDMTX SIZE */
#define LEDMTX_ROW_NUMBER                8
#define LEDMTX_COLOUMNS_NUMBER           8



#endif