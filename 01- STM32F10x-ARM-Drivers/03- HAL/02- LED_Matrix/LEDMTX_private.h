/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V02  												*/
/*	Date	 : 6 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/*             V02 : Update the whole Driver                        */
/********************************************************************/
#ifndef LEDMTX_PRIVATE_H
#define LEDMTX_PRIVATE_H
/*********************************************************************/


/*********************************************************************/
/* LEDMTX Delay to achieve the selected number of FPS */
#define LED_MTX_DELAY_IN_US        (1000000 /(LEDMTX_ROW_NUMBER * LEDMTX_Frame_PER_SECOND))
/*********************************************************************/


/*********************************************************************/
/* Function Name : SetRowValues                                      */
/* Inputs        : LED MATRIX [DATA]                                 */
/* Outputs       : NONE                                              */
/* Descreiption  : Set Rows Value corresponding to LED MATRIX [DATA] */
/*********************************************************************/
static void SetRowValues(u8 Copy_u8Value);


#endif