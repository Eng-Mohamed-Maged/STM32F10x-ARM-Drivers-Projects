/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V01  												*/
/*	Date	 : 29 September 2023                                    */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#ifndef LEDMTX_INTERFACE_H
#define LEDMTX_INTERFACE_H

/* LEDMTX Delay to achieve the selected number of FPS */
#define LED_MTX_DELAY_IN_US        (1000000 /(LEDMTX_ROW_NUMBER * LEDMTX_Frame_PER_SECOND))



void HLEDMTX_voidInit (void);
void HLEDMTX_voidShiftDisplay (u8 * Copy_u8Data,u8 Copy_u8DataLength,u8 Copy_u8ShiftDelay);



#endif
