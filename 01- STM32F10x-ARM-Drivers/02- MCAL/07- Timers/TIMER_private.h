/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V02                                                        */
/* Date        : 5 October 2023                                             */
/* Logs        : V01 : Initial Creation                                     */
/*               V02 : Adding [Function to get Elapsed Time ]               */
/*                     Adding [Function to Stop/Start Timer ]               */
/****************************************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H
/*****************************************************/
#define TIMER1_BASE_ADDRESS   0x40012C00
#define TIMER2_BASE_ADDRESS   0x40000000
#define TIMER3_BASE_ADDRESS   0x40000400
#define TIMER4_BASE_ADDRESS   0x40000800
/*****************************************************/
// Define an enum for the register offsets
typedef enum
{
    CR1_OFFSET   = 0x00,
    CR2_OFFSET   = 0x04,
    SMCR_OFFSET  = 0x08,
    DIER_OFFSET  = 0x0C,
    SR_OFFSET    = 0x10,
    EGR_OFFSET   = 0x14,
    CCMR1_OFFSET = 0x18,
    CCMR2_OFFSET = 0x1C,
    CCER_OFFSET  = 0x20,
    CNT_OFFSET   = 0x24,
    PSC_OFFSET   = 0x28,
    ARR_OFFSET   = 0x2C,
    RCR_OFFSET   = 0x30,
    CCR1_OFFSET  = 0x34,
    CCR2_OFFSET  = 0x38,
    CCR3_OFFSET  = 0x3C,
    CCR4_OFFSET  = 0x40,
    BDTR_OFFSET  = 0x44,
    DCR_OFFSET   = 0x48,
    DMAR_OFFSET  = 0x4C
} TimerRegisterOffset;
/*****************************************************/
// Define a struct for the timer registers
typedef struct
{
	  volatile u16 CR1;
	  u16  RESERVED0;
	  volatile u16 CR2;
	  u16  RESERVED1;
	  volatile u16 SMCR;
	  u16  RESERVED2;
	  volatile u16 DIER;
	  u16  RESERVED3;
	  volatile u16 SR;
	  u16  RESERVED4;
	  volatile u16 EGR;
	  u16  RESERVED5;
	  volatile u16 CCMR1;
	  u16  RESERVED6;
	  volatile u16 CCMR2;
	  u16  RESERVED7;
	  volatile u16 CCER;
	  u16  RESERVED8;
	  volatile u16 CNT;
	  u16  RESERVED9;
	  volatile u16 PSC;
	  u16  RESERVED10;
	  volatile u16 ARR;
	  u16  RESERVED11;
	  volatile u16 RCR;
	  u16  RESERVED12;
	  volatile u16 CCR1;
	  u16  RESERVED13;
	  volatile u16 CCR2;
	  u16  RESERVED14;
	  volatile u16 CCR3;
	  u16  RESERVED15;
	  volatile u16 CCR4;
	  u16  RESERVED16;
	  volatile u16 BDTR;
	  u16  RESERVED17;
	  volatile u16 DCR;
	  u16  RESERVED18;
	  volatile u16 DMAR;
	  u16  RESERVED19;
} TimerRegisters;

/*****************************************************/
// Define instances of TimerRegisters for each timer
TimerRegisters *const TIMER[TIMER_NUMBER] =
{
		(TimerRegisters *)TIMER1_BASE_ADDRESS ,
		(TimerRegisters *)TIMER2_BASE_ADDRESS ,
		(TimerRegisters *)TIMER3_BASE_ADDRESS ,
		(TimerRegisters *)TIMER4_BASE_ADDRESS
};

/*****************************************************/



#endif
