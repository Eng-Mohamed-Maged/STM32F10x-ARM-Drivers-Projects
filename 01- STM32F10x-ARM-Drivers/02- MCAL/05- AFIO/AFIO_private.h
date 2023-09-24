/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 25 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Error Fixed                                             */
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



#define AFIO_BASE_ADDRESS         0x40010000
#define AFIO ((volatile AFIO_t *) AFIO_BASE_ADDRESS )



#endif
