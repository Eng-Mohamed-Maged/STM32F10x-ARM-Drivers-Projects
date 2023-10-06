/********************************************************************/
/*  Author	 : Mohamed Maged							 	        */
/*  Version	 : V02  												*/
/*	Date	 : 6 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/*             V02 : Update the whole Driver                        */
/********************************************************************/
#ifndef LEDMTX_INTERFACE_H
#define LEDMTX_INTERFACE_H



/********************************************************************/
/* Function Name :  HLEDMTX_voidInit                                */
/* Inputs        :  NONE                                            */
/* Outputs       :  NONE                                            */
/* Descreiption  :  Intialization of Pins [Rows - Columns]          */
/********************************************************************/
void HLEDMTX_voidInit (void);
/********************************************************************/


/********************************************************************/
/* Function Name :  HLEDMTX_voidDisplay                             */
/* Inputs        :  LED MATRIX [DATA]                               */
/* Outputs       :  NONE                                            */
/* Descreiption  :  Display a static figure                         */
/********************************************************************/
void HLEDMTX_voidDisplay (u8 *copy_u8Data);
/********************************************************************/




/********************************************************************/
/* Function Name :  HLEDMTX_voidShiftDisplay                        */
/* Inputs        :  LED MATRIX [DATA] - DATA Length - Delay         */
/* Outputs       :  NONE                                            */
/* Descreiption  :  Display a dynamic figure with shifting          */
/********************************************************************/
void HLEDMTX_voidShiftDisplay (u8 * Copy_u8Data,u8 Copy_u8DataLength,u8 Copy_u8ShiftDelay);



#endif
