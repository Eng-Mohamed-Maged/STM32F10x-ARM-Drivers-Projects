/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 26 September 2023                                             */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef	STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct 
{
	volatile  u32 STK_CTRL;
	volatile  u32 STK_LOAD;
	volatile  u32 STK_VAL;
	volatile  u32 STK_CALIB;
	
}SysTick_t;


#define   SysTick   ((SysTick_t*)0xE000E010)


#define   STK_AHB_BY_8      0
#define   STK_AHB           1

#define   DISABLE           0
#define   ENABLE            1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1


#endif
