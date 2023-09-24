/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V04                                                           */
/*   Date      : 25 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all NVIC Driver to make it more professional     */
/*               V03 : Update MNVIC_voidSetPriority function                   */
/*               V04 : Error Fixed - Modifications on MNVIC_voidSetPriority    */
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
// Number of groups = number of nesting
													                           */

#define     MNVIC_GROUP_16_SUB_0        0x05FA0300 //0 bit for sub & 4 bit For group   << 0
#define     MNVIC_GROUP_8_SUB_2         0x05FA0400 //1 bit for sub & 3 bit For group   << 1
#define     MNVIC_GROUP_4_SUB_4         0x05FA0500 //2 bit for sub & 2 bit For group   << 2
#define     MNVIC_GROUP_2_SUB_8         0x05FA0600 //3 bit for sub & 1 bit For group   << 3
#define     MNVIC_GROUP_0_SUB_16        0x05FA0700 //4 bit for sub & 0 bit For group   << 4


#define   MNVIC_GROUP_SUB_DISTRIBUTION			MNVIC_GROUP_0_SUB_16







#endif
