/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V02                                                  */
/*  Date     : 5 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/*             V02 : Adding Timers Driver instead of SysTick        */
/********************************************************************/

/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* MCAL includes */
#include   "GPIO_interface.h"
#include   "EXTI_interface.h"
#include   "AFIO_interface.h"
#include   "NVIC_interface.h"


/* module includes */
#include "REMOTE_interface.h"
#include "REMOTE_config.h"
#include "REMOTE_private.h"

#if   TIMER_TYPE == SYSTICK_TIMER
	#include   "STK_interface.h"
#elif TIMER_TYPE == TIMERS_1_4
	#include   "TIMER_interface.h"
#endif


volatile u8 global_u8Flag               = 0 ;
volatile u8 global_u8FinishFlag         = 0 ;
volatile u32 global_u32Frame            = 0 ;
volatile u8 global_u8Index              = 0 ;

u32 global_u32Data                      = 0 ;
u32 global_u32DataInverted              = 0 ;
u32 global_u32Address                   = 0 ;
u32 global_u32AddressInverted           = 0 ;

void REMOTE_HANDLER(void);
void REMOTE_voidInit(void)
{	
	/* Making the pin INPUT */
	MGPIO_voidSetPinDirection(REMOTE_EXTI_PORT , REMOTE_EXTI_LINE , INPUT_FLOATING);
	
	MNVIC_voidInit();

	/* Intialize EXTI */
	MNVIC_voidEnableInterrupt(REMOTE_NVIC_NUMBER);
	MEXTI_voidSetCallBack(REMOTE_HANDLER,REMOTE_EXTI_LINE);
	MEXTI_voidSetSignalLatch(REMOTE_EXTI_LINE , MEXTI_FALLING_EDGE);
	MEXTI_voidEnableEXTI(REMOTE_EXTI_LINE);
	
	/* Configure the AFIO */
	MAFIO_voidSetEXTIConfiguration(REMOTE_EXTI_LINE,REMOTE_EXTI_PORT);

    #if   TIMER_TYPE == SYSTICK_TIMER
			/* Systick initialize */
			MSTK_voidInit();
    #elif TIMER_TYPE == TIMERS_1_4
			/* Systick initialize */
			TIMER_voidInit();
    #endif

}


REMOTE_buttons_t REMOTE_getButton (void)
{
	REMOTE_buttons_t local_button = REMOTE_NO_DATA ;
	if (global_u8FinishFlag){
		u8 local_u8Check = REMOTE_u8CheckFrame();
		if (local_u8Check){
			switch (global_u32Data){
				case POWER       :  local_button = REMOTE_POWER;         break;
				case MODE        :  local_button = REMOTE_MODE;          break;
				case MUTE        :  local_button = REMOTE_MUTE;          break;
				case PLAY_RESUME :  local_button = REMOTE_P_RESUME ;     break;
				case RIGHT       :  local_button = REMOTE_RIGHT;         break;
				case LEFT        :  local_button = REMOTE_LEFT;          break;
				case EQ          :  local_button = REMOTE_EQ ;           break;
				case VOLUME_DOWN :  local_button = REMOTE_VOL_DOWN;      break;
				case VOLUME_UP   :  local_button = REMOTE_VOL_UP;        break;
				case ZERO        :  local_button = REMOTE_ZERO ;         break;
				case RPT         :  local_button = REMOTE_RPT;           break;
				case U_USD       :  local_button = REMOTE_U_SD;          break;
				case ONE         :  local_button = REMOTE_ONE ;          break;
				case TWO         :  local_button = REMOTE_TWO  ;         break;
				case THREE       :  local_button = REMOTE_THREE;         break;
				case FOUR        :  local_button = REMOTE_FOUR ;         break;
				case FIVE        :  local_button = REMOTE_FIVE ;         break;
				case SIX         :  local_button = REMOTE_SIX  ;         break;
				case SEVEN       :  local_button = REMOTE_SEVEN;         break;
				case EIGHT       :  local_button = REMOTE_EIGHT;         break;
				case NINE        :  local_button = REMOTE_NINE ;         break;
				default          :  
					/* If it is here data is not correct*/  
					local_button = REMOTE_ERROR ;			             break;                                   
			} 
		}
		global_u8FinishFlag = 0 ;
	}
	return local_button ; 
} 


void REMOTE_HANDLER(void)
{
	/* Clear flag */
	MEXTI_voidClearPendingFlag(REMOTE_EXTI_LINE);
    #if   TIMER_TYPE == SYSTICK_TIMER
		/* Get time elapsed*/
		u32 etime = MSTK_u32GetElapsedTime(TIME_US);
		/* Start timer to count till the next isr */
		MSTK_voidStart();
    #elif TIMER_TYPE == TIMERS_1_4
		/* Get time elapsed*/
		 u32 etime = TIMER_u32GetElapsedTime(TIMER_NUMBER,TIMER_US);
		/* Start timer to count till the next isr */
		 TIMER_voidStart(TIMER_NUMBER);
    #endif

	/* Wait for the start bit before recording frame*/
	if ((global_u8Flag == 0) && (etime > 10000) && (etime < 15000)){
		global_u8Flag = 1 ;
		global_u8Index = 0 ;
	}
	/* Start bit came and will start recording the frame */
	else if (global_u8Flag == 1){
		/* If bit == 1 */
		if ((etime > 2000 ) && (etime < 2400 )){
			SET_BIT(global_u32Frame , global_u8Index );
			global_u8Index++;
		}
		/* If bit == 0 */
		else if ( (etime > 1000 ) &&  (etime < 1200 ) ){
			CLR_BIT(global_u32Frame , global_u8Index );
			global_u8Index++;
		}
		/* the Wait before the next frame */
		else if ( (etime > 20000 )){
			global_u8Flag = 0 ;
			global_u8FinishFlag = 1 ; 
		}
		else {

		}
	}
}


/***** Private functions ******/
static u8 REMOTE_u8CheckFrame(void)
{
	u8 local_u8Error = FRAME_ERROR ;
	/* Get data inverted from the frame*/
	global_u32DataInverted = (global_u32Frame & 0xff000000);
	global_u32DataInverted = (global_u32DataInverted >> DATA_INVERTED_BIT);
	
	/* Get data from the frame */
	global_u32Data         = (global_u32Frame & 0x00ff0000);
	global_u32Data         = (global_u32Data >> DATA_BIT);
	
	/* Get Address inverted from the frame */
	global_u32AddressInverted = (global_u32Frame & 0x0000ff00);
	global_u32AddressInverted = (global_u32AddressInverted >> ADDRESS_INVERTED_BIT);
	
	/* Get Address from the frame */
	global_u32Address = (global_u32Address & 0x000000ff);
	
	if ( (global_u32Data & global_u32DataInverted) | (global_u32Address & global_u32AddressInverted) ){
		local_u8Error = FRAME_ERROR ;
	}
	else {
		local_u8Error = FRAME_CORRECT ;
	}
	
	return local_u8Error ;

}

                                       
