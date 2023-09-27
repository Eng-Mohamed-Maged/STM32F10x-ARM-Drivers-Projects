/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 17 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all EXTI Driver with enum configurations         */
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
