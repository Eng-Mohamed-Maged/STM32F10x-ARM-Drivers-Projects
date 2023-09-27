/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 17 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all EXTI Driver with enum configurations         */
/*******************************************************************************/
#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

/* Enum for External Interrupt Modes */
typedef enum
{
	MEXTI_RISING_EDGE  = 0 ,
	MEXTI_FALLING_EDGE     ,
	MEXTI_ON_CHANGE 
}MEXTI_MODE_t;
	
/* Enum for External Interrupt Lines */
typedef enum
{
	MEXTI_LINE0    =  0   ,
	MEXTI_LINE1           ,
	MEXTI_LINE2           ,
	MEXTI_LINE3           ,
	MEXTI_LINE4           ,
	MEXTI_LINE5           ,
	MEXTI_LINE6           ,
	MEXTI_LINE7           ,
	MEXTI_LINE8           ,
	MEXTI_LINE9           ,
	MEXTI_LINE10          ,
	MEXTI_LINE11          ,
	MEXTI_LINE12          ,
	MEXTI_LINE13          ,
	MEXTI_LINE14          ,
	MEXTI_LINE15	
}MEXTI_LINE_t;




/****************  Functions Decleration  ******************/

void MEXTI_voidInit();

void MEXTI_voidSetSignalLatch(MEXTI_LINE_t Copy_EXTILine , MEXTI_MODE_t Copy_EXTIMode);

void MEXTI_voidEnableEXTI( MEXTI_LINE_t LOC_EXTILine);

void MEXTI_voidDisableEXTI( MEXTI_LINE_t LOC_EXTILine);

void MEXTI_voidSoftWareTrigger( MEXTI_LINE_t LOC_EXTILine);

/************  CallBack Functions Declerations  *************/

void MEXTI_voidSetCallBack(void (*ptr)(void), MEXTI_LINE_t Copy_Line) ;



/*  External Interrupt Modes  */

#define MEXTI_RISING_EDGE    0
#define MEXTI_FALLING_EDGE   1
#define MEXTI_ON_CHANGE      2





#endif
