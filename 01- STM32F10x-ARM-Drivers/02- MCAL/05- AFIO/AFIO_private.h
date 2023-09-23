/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 18 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#ifndef  AFIO_PRIVATE_H
#define  AFIO_PRIVATE_H

typedef struct
{
	volatile u32 EVCR         ;
	volatile u32 MAPR         ;
	volatile u32 EXTICR[4]    ;
	volatile u32 RESERVED0    ;
	volatile u32 MAPR2        ;

}AFIO_t;


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


#define AFIO_BASE_ADDRESS         0x40010000
#define AFIO ((volatile AFIO_t *) AFIO_BASE_ADDRESS )



#endif
