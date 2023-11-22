/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V03                                                        */
/* Date        : 22 November 2023                                           */
/* Logs        : V01 : Initial Creation                                     */
/*               V02 : Adding [Function to get Elapsed Time ]               */
/*                     Adding [Function to Stop/Start Timer ]               */
/*               V03 : Fix Calculations Errors in BusyWaitFunction          */
/****************************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H


/*
	Enter the APB2 and APB1 bus clock 
*/
#define    APB2_CLK     8000000
#define    APB1_CLK     8000000

/*
	Number of timer in the MCU 
*/

#define   TIMER_NUMBER   4


/******************* Private data for the config.c ******************/

/***  Timer configurations struct  ***/
typedef struct {
	u8  u8Channel              ;
	u8  u8Enable               ;
	u8  u8Mode                 ;
	u8  u8InterruptEnable      ;
	u32 u32ClkSource           ;
	u16 u16Prescaler           ;
	u32 u32Interval            ;
	u8  u8AutoReload_REGISTER  ;
}TIMER_config_t;

/* Macros */
#define      ENABLE        1
#define      DISABLE       0

/* Timer Modes */
#define      UP_COUNTER    0
#define      DOWN_COUNTER  1




#endif
