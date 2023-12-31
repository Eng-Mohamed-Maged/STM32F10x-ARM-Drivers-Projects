/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V02                                                  */
/*  Date     : 5 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/*             V02 : Adding Timers Driver instead of SysTick        */
/********************************************************************/
#ifndef REMOTE_INTERFACE_H
#define REMOTE_INTERFACE_H

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

/**** Timer channels ****/
typedef enum {
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
}REMOTE_TIMERS_t;

/* 
  * REMOTE_voidInit - > Intialize the exti for remote  
*/
void REMOTE_voidInit(void);


/* 
  * REMOTE_getButton - > get the button pressed
  * O/P : (REMOTE_buttons_t) the pressed button if no data came return (REMOTE_NO_DATA)
		   if data was not right (REMOTE_ERROR)
*/
REMOTE_buttons_t REMOTE_getButton (void);




#endif
