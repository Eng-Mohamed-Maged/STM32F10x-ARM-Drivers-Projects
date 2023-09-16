/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 16 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all NVIC Driver to make it more professional     */
/*******************************************************************************/

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/* Options :
                 MNVIC_GROUP_16_SUB_0
                 MNVIC_GROUP_8_SUB_2
                 MNVIC_GROUP_4_SUB_4
                 MNVIC_GROUP_2_SUB_8
                 MNVIC_GROUP_0_SUB_16        
                 	 	 	 	 	 	 	 	 	 
													 
//NOTE :: if you want to disable normal nesting choose -> MNVIC_GROUP_0_SUB_16
													 
													                           */


#define   MNVIC_GROUP_SUB_DISTRIBUTION			MNVIC_GROUP_0_SUB_16







#endif
