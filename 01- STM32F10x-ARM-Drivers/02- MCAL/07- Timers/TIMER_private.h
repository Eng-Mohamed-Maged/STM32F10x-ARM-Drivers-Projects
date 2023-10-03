/*****************************************************/
/* Author      : Mohamed Maged                       */
/* Version     : V01                                 */
/* Date        : 3 October 2023                      */
/* Logs        : V01 : Initial Creation              */
/*****************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H
/*****************************************************/
#define TIMER1_BASE_ADDRESS   0x40012C00
#define TIMER2_BASE_ADDRESS   0x40000000
#define TIMER3_BASE_ADDRESS   0x40000400
#define TIMER4_BASE_ADDRESS   0x40000800
/*****************************************************/
/* Array of the base address of each timer  */
volatile u32 *TIM [TIMER_NUMBER] =
{ (u32*)(TIMER1_BASE_ADDRESS) ,
  (u32*)(TIMER2_BASE_ADDRESS) ,
  (u32*)(TIMER3_BASE_ADDRESS) ,
  (u32*)(TIMER4_BASE_ADDRESS)
};
/*****************************************************/
/* Offset of each rigester */
#define    CR1      0
#define    CR2      1
#define    SMCR     2
#define    DIER     3
#define    SR       4
#define    EGR      5
#define    CCMR1    6
#define    CCMR2    7
#define    CCER     8
#define    CNT      9
#define    PSC      10
#define    ARR      11
#define    RCR      12
#define    CCR1     13
#define    CCR2     14
#define    CCR3     15
#define    CCR4     16
#define    BDTR     17
#define    DCR      18
#define    DMAR     19
/*****************************************************/


#endif
