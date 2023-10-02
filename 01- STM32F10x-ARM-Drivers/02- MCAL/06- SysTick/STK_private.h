/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V03                                                           */
/*   Date      : 2 October 2023                                                */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Updating the driver to be more professional             */
/*               V03 : Errors Fixed                                            */
/*******************************************************************************/
#ifndef	STK_PRIVATE_H
#define STK_PRIVATE_H

/* Struct for [Core Peripheral (Systick)] Registers' mapping */
typedef struct 
{
	volatile  u32 CTRL   ;      /* SysTick control and status register  */
	volatile  u32 LOAD   ;      /* SysTick reload value register        */
	volatile  u32 VAL    ;      /* SysTick current value register       */
	volatile  u32 CALIB  ;      /* SysTick calibration value register   */
	
}STK_t;

/****************************************************************************/
#define   STK_BASE_ADDRESS       0xE000E010
#define   STK   				 ((volatile STK_t*)STK_BASE_ADDRESS)
/*********************      Clock Source Options        *********************/
#define   STK_AHB_BY_8      	 0
#define   STK_AHB           	 1
/*********************        Interrupt Options         *********************/
#define   DISABLE           	 0
#define   ENABLE            	 1
/****************************************************************************/
#define   MSTK_SINGLE_INTERVAL   0
#define   MSTK_PERIOD_INTERVAL   1
/*********************        Register Bits             *********************/
#define   MSTK_CTRL_ENABLE       0
#define   MSTK_CTRL_TICKINT      1
#define   MSTK_CTRL_CLKSOURCE    2
#define   MSTK_CTRL_COUNTFLAG    16
/****************************************************************************/
#define   MSTK_MAXIMUM_VALUE     0x00FFFFFF
/****************************************************************************/
#define NULL        ((void *)0)
/****************************************************************************/

#endif
