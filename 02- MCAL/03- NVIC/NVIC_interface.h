/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 15 September 2023                                             */
/*******************************************************************************/
#ifndef NVIC_INTERFACE_H
#define	NVIC_INTERFACE_H




void MNVIC_voidEnableInterrupt       (u8 Copy_u8InterruptNum);
void MNVIC_voidDisableInterrupt      (u8 Copy_u8InterruptNum);
void MNVIC_voidSetPendingFlag        (u8 Copy_u8InterruptNum);
void MNVIC_voidClearPendingFlag      (u8 Copy_u8InterruptNum);
u8   MNVIC_u8GetActiveFlag           (u8 Copy_u8InterruptNum);
void MNVIC_voidInit(void) ;
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx , u8 Copy_u8Priority);

#endif
