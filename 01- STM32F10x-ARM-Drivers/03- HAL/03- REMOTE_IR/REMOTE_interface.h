/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V01                                                  */
/*  Date     : 1 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/********************************************************************/
#ifndef REMOTE_INTERFACE_H
#define REMOTE_INTERFACE_H

/* 
  Important Rules you should follow :
  1) Open RCC for the GPIO-PORT which you will use as EXTI for the reciever.
  2) Open RCC for AFIO if you want mapping the EXTI [By default EXTI0=>A0].
  3) Don't use Systick Driver in any other applications [It will cause Problems].
  4) Call (REMOTE_voidInit) before While
  5) Check the Recieved data from (REMOTE_getButton)  .
  6) If the Recieved data is less than (REMOTE_NO_DATA) then the data is valid .
  

/* Buttons IDs for NEC Remote */
typedef enum {
	REMOTE_ZERO     ,
    REMOTE_ONE      ,
	REMOTE_TWO      ,
	REMOTE_THREE    ,
	REMOTE_FOUR     ,
	REMOTE_FIVE     ,
	REMOTE_SIX      ,
	REMOTE_SEVEN    ,
	REMOTE_EIGHT    ,
	REMOTE_NINE     ,
	REMOTE_RPT      ,
	REMOTE_U_SD     ,
	REMOTE_EQ       ,
	REMOTE_VOL_DOWN ,
	REMOTE_VOL_UP   ,
	REMOTE_P_RESUME ,
	REMOTE_RIGHT    ,
	REMOTE_LEFT     ,
	REMOTE_POWER    ,
	REMOTE_MODE     ,
	REMOTE_MUTE     ,
	REMOTE_NO_DATA  ,
	REMOTE_ERROR    ,
}REMOTE_buttons_t;



/* 
  - REMOTE_voidInit : Intialize the exti for remote  
  - Input           : NONE
  - Output          : NONE 
*/
void REMOTE_voidInit(void);


/* 
  - REMOTE_getButton  : Get the pressed button 
  - Inputs            : NONE
  - Output            :(REMOTE_buttons_t) the pressed button 
						# if no data came return   (REMOTE_NO_DATA)
		                # if data was not correct  (REMOTE_ERROR)
*/
REMOTE_buttons_t REMOTE_getButton (void);	
	
#endif
