/****************************************************************************/
/* Author      : Mohamed Maged                                              */
/* Version     : V02                                                        */
/* Date        : 5 October 2023                                             */
/* Logs        : V01 : Initial Creation                                     */
/*               V02 : Adding [Function to get Elapsed Time ]               */
/*                     Adding [Function to Stop/Start Timer ]               */
/****************************************************************************/

#include "STD_TYPES.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"


/*
 * Important NOTES :
 * 1) You should know the clock frequency of the timer peripheral bus like [APB1_CLK]
 * 2) So you should go to RCC register to know the clock source and the prescaler of APB1 OR APB2 Buses
 * 3) In my case i didnt use any prescaler for APB1 - APB2 Buses
 * 	  so the clock of APB1 = APB2 = AHB = 8 MHZ
 * 4) Now there is a problem => if we use this frequency for the timer without prescaler
 * 	  the maximum time we will get for 1 tick = (1 / 8MHZ) = 0.125us
 * 5) And this timer is 16 bit so it overflow every [0.125 * 65536] = 8192 us
 * 6) If you want increase this overflow time you should use prescaler
 *    EX: Clock = 8MHZ - Prescaler = 8 so tick time = [1 / 1MHZ] = 1us
 *        The Maximum overflow time = 1us * 65536 = 65536 us
 *
 * TODO: Implementation for DOWN_COUNTER
 */




/** Timer configurations table **/
const TIMER_config_t configTable[TIMER_NUMBER] = {
//   Timer      Timer        Timer          Interrupt    CLK         Prescaler       Interval    AutoReload
//   channel	enable       mode           enable       source                       in US       Enable
	{TIM1    ,  DISABLE     , UP_COUNTER    , DISABLE    , APB2_CLK    , 8              , 0    ,  DISABLE    } ,
	{TIM2    ,  ENABLE      , UP_COUNTER    , DISABLE    , APB1_CLK    , 8              , 0    ,  ENABLE     } ,
	{TIM3    ,  DISABLE     , UP_COUNTER    , DISABLE    , APB1_CLK    , 8              , 0    ,  ENABLE     } ,
	{TIM4    ,  DISABLE     , UP_COUNTER    , DISABLE    , APB1_CLK    , 8              , 0    ,  DISABLE    }
};
