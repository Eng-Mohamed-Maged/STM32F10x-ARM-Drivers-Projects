/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V04                                                           */
/*   Date      : 4 October 2023                                                */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all EXTI Driver with enum configurations         */
/*               V03 : Warnning Fixed "#else - #endif"                         */
/*               V04 : Fix EXTI_HANDLER {5 - 15}                               */
/*******************************************************************************/

#ifndef  EXTI_CONFIG_H
#define  EXTI_CONFIG_H


/* Options :
		//  External Interrupt Modes  //
		MEXTI_RISING_EDGE    0
		MEXTI_FALLING_EDGE   1
		MEXTI_ON_CHANGE      2
		
*/
#define  EXTI_MODE          MEXTI_FALLING_EDGE



/* Options :
		//  External Interrupt Lines  //
		MEXTI_LINE0  0
		MEXTI_LINE1  1
		MEXTI_LINE2  2
		MEXTI_LINE3  3
		MEXTI_LINE4  4
		MEXTI_LINE5  5
		MEXTI_LINE6  6
		MEXTI_LINE7  7
		MEXTI_LINE8  8
		MEXTI_LINE9  9
		MEXTI_LINE10 10
		MEXTI_LINE11 11
		MEXTI_LINE12 12
		MEXTI_LINE13 13
		MEXTI_LINE14 14
		MEXTI_LINE15 15
*/

#define  EXTI_LINE          MEXTI_LINE0






#endif
