/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 18 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#ifndef  AFIO_INTERFACE_H
#define  AFIO_INTERFACE_H


/*  EXTI Lines Options  */
typedef enum
{
	MAFIO_EXTI0 = 0 ,
	MAFIO_EXTI1     ,
	MAFIO_EXTI2     ,
	MAFIO_EXTI3     ,
	MAFIO_EXTI4     ,
	MAFIO_EXTI5     ,
	MAFIO_EXTI6     ,
	MAFIO_EXTI7     ,
	MAFIO_EXTI8     ,
	MAFIO_EXTI9     ,
	MAFIO_EXTI10    ,
	MAFIO_EXTI11    ,
	MAFIO_EXTI12    ,
	MAFIO_EXTI13    ,
	MAFIO_EXTI14    ,
	MAFIO_EXTI15

}MAFIO_EXTI_LINES_t;

typedef enum
{
	MAFIO_PORT_A = 0 ,
	MAFIO_PORT_B     ,
	MAFIO_PORT_C     ,
	MAFIO_PORT_D     ,
	MAFIO_PORT_E     ,
	MAFIO_PORT_F     ,
	MAFIO_PORT_G

}MAFIO_PORTS_t;


void  MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI_LINES_t Copy_Line ,MAFIO_PORTS_t Copy_PortMap);

#endif
