/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 27 September 2023                                             */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Updating the driver to be more professional             */
/*******************************************************************************/

#ifndef STK_CONFIG_H
#define STK_CONFIG_H


/* Options :
                   STK_AHB_BY_8
                   STK_AHB                   */
								        
#define     STK_CLOCK_SOURCE             STK_AHB_BY_8



/*
	Determine the AHP clock in [HZ] to make the calculations be correct 
*/
#define    STK_AHP_CLK        8000000                    // 8 Mhz Clock


#endif
