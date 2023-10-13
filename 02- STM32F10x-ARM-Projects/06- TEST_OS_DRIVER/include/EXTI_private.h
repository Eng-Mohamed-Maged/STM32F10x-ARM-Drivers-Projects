/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V04                                                           */
/*   Date      : 4 October 2023                                                */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all EXTI Driver with enum configurations         */
/*               V03 : Warnning Fixed "#else - #endif"                         */
/*               V04 : Fix EXTI_HANDLER {5 - 15}                               */
/*******************************************************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H


void (* EXTI_CallBack[16] ) (void) ={'\0'} ;

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_t;

#define EXTI_BASE_ADDRESS 			0x40010400
#define EXTI ((volatile EXTI_t *) EXTI_BASE_ADDRESS)




#endif
