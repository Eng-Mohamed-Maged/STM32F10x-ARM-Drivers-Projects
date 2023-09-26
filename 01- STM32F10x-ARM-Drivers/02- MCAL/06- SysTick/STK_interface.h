/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 26 September 2023                                             */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef STK_INTERFACE_H
#define	STK_INTERFACE_H


void   MSTK_voidInit               (void) ;
void   MSTK_voidSetBusyWait        (u32 Copy_u32Ticks );
void   MSTK_voidSetIntervalSingle  (u32 Copy_u32Ticks , void (*Copy_ptr) (void));
void   MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr) (void));
void   MSTK_voidStopInterval       (void) ;
u32    MSTK_u32GetElapsedTime      (void) ;
u32    MSTK_u32GetRemainingTime    (void) ;

#endif
