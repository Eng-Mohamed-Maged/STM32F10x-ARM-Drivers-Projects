/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V03                                                           */
/*   Date      : 25 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all EXTI Driver with enum configurations         */
/*               V03 : Warnning Fixed "#else - #endif"                         */
/*******************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidInit()
{
	// Configurations : //
	/* Options :
		//  External Interrupt Modes  //
		MEXTI_RISING_EDGE    0
		MEXTI_FALLING_EDGE   1
		MEXTI_ON_CHANGE      2
		
	*/
	MEXTI_LINE_t EXTI_LINE = MEXTI_ON_CHANGE;
	#if   	EXTI_MODE == MEXTI_RISING_EDGE
		SET_BIT( EXTI->RTSR , EXTI_LINE );
	#elif 	EXTI_MODE == MEXTI_FALLING_EDGE
		SET_BIT( EXTI->FTSR , EXTI_LINE );
	#elif	EXTI_MODE == MEXTI_ON_CHANGE
		SET_BIT( EXTI->RTSR , EXTI_LINE );
		SET_BIT( EXTI->FTSR , EXTI_LINE );
	#else
		#error "Wrong Mode or Line configurations"
	#endif	
	
	/* Disable Interrupt */
	MEXTI_voidDisableEXTI(EXTI_LINE);
}


void MEXTI_voidSetSignalLatch(MEXTI_LINE_t Copy_EXTILine , MEXTI_MODE_t Copy_EXTIMode)
{
	switch (Copy_EXTIMode)
	{
		case MEXTI_RISING_EDGE  : SET_BIT( EXTI->RTSR , Copy_EXTILine );    break;
		case MEXTI_FALLING_EDGE : SET_BIT( EXTI->FTSR , Copy_EXTILine );    break;
		case MEXTI_ON_CHANGE    : SET_BIT( EXTI->RTSR , Copy_EXTILine );
								  SET_BIT( EXTI->FTSR , Copy_EXTILine );    break;
	}
	/* Set NOT Masked Interrupt  */
	SET_BIT( EXTI->IMR , Copy_EXTILine );
}




void MEXTI_voidEnableEXTI( MEXTI_LINE_t LOC_EXTILine)
{
	SET_BIT( EXTI->IMR , LOC_EXTILine );
}





void MEXTI_voidDisableEXTI( MEXTI_LINE_t LOC_EXTILine)
{
	CLR_BIT( EXTI->IMR , LOC_EXTILine );
}




void MEXTI_voidSoftWareTrigger( MEXTI_LINE_t LOC_EXTILine)
{
	SET_BIT( EXTI->SWIER , LOC_EXTILine );
}



void MEXTI_voidSetCallBack(void (*ptr)(void), MEXTI_LINE_t Copy_EXTILine)
{

	EXTI_CallBack[Copy_EXTILine]= ptr;

}



/*************************  ISR 0 ***************************/
void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 0 );
}

/*************************  ISR 1 ***************************/
void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 1 );
}
/*************************  ISR 2 ***************************/
void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[2]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 2 );
}
/*************************  ISR 3 ***************************/
void EXTI3_IRQHandler(void)
{
	EXTI_CallBack[3]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 3 );
}
/*************************  ISR 4 ***************************/
void EXTI4_IRQHandler(void)
{
	EXTI_CallBack[4]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 4 );
}
/*************************  ISR 5 ***************************/
void EXTI5_IRQHandler(void)
{
	EXTI_CallBack[5]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 5 );
}
/*************************  ISR 6 ***************************/
void EXTI6_IRQHandler(void)
{
	EXTI_CallBack[6]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 6 );
}
/*************************  ISR 7 ***************************/
void EXTI7_IRQHandler(void)
{
	EXTI_CallBack[7]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 7 );
}
/*************************  ISR 8 ***************************/
void EXTI8_IRQHandler(void)
{
	EXTI_CallBack[8]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 8 );
}
/*************************  ISR 9 ***************************/
void EXTI9_IRQHandler(void)
{
	EXTI_CallBack[9]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 9 );
}
/*************************  ISR 10 ***************************/
void EXTI10_IRQHandler(void)
{
	EXTI_CallBack[10]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 10 );
}
/*************************  ISR 11 ***************************/
void EXTI11_IRQHandler(void)
{
	EXTI_CallBack[11]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 11 );
}
/*************************  ISR 12 ***************************/
void EXTI12_IRQHandler(void)
{
	EXTI_CallBack[12]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 12 );
}
/*************************  ISR 13 ***************************/
void EXTI13_IRQHandler(void)
{
	EXTI_CallBack[13]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 13 );
}
/*************************  ISR 14 ***************************/
void EXTI14_IRQHandler(void)
{
	EXTI_CallBack[14]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 14 );
}
/*************************  ISR 15 ***************************/
void EXTI15_IRQHandler(void)
{
	EXTI_CallBack[15]();
	/* Clear Pending bit */
	SET_BIT( EXTI->PR , 15 );
}

