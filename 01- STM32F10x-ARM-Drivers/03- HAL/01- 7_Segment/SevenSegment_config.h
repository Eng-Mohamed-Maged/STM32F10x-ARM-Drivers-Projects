/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 29 Srptember 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#ifndef	SEVENSEGMENT_CONFIG_H
#define SEVENSEGMENT_CONFIG_H
/*********************************************/	
/* Choose : 
				ONE_SEVEN_SEGMENT
				TWO_SEVEN_SEGMENT
									     	 */
#define 	    NUMBER_SEVEN_SEGMENTS                ONE_SEVEN_SEGMENT
/* Choose : 
				GPIOA                       
				GPIOB                       
				GPIOC                       
									     	 */

#define     CONNECTED_PORT_FIRST_SEGMENT	         GPIOA
/* Choose : 
				COMMEN_CATHOD
				COMMEN_ANODE                                                              
									     	 */
#define     FIRST_SEVEN_SEGMENT_TYPE	             COMMEN_CATHOD			
#if NUMBER_SEVEN_SEGMENTS == TWO_SEVEN_SEGMENT
	/* Choose : 
						GPIOA                       
						GPIOB                       
						GPIOC                       
									     	 */
	#define		CONNECTED_PORT_SECOND_SEGMENT         GPIOB
	/* Choose : 
				COMMEN_CATHOD
				COMMEN_ANODE                                                              
									     	 */
	#define     SECOND_SEVEN_SEGMENT_TYPE	         COMMEN_CATHOD	
#endif




#endif
