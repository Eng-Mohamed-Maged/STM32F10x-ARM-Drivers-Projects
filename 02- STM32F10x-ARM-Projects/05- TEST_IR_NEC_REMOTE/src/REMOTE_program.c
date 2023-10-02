/********************************************************************/
/*  Author   : Mohamed Maged                                        */
/*  Version  : V02                                                  */
/*  Date     : 2 October 2023                                       */
/*  Logs     : V01 : Initial Creation                               */
/*             V02 : Adding NULL MACRO                              */
/********************************************************************/
/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL includes */
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include  "NVIC_interface.h"

/* Module includes */
#include  "REMOTE_interface.h"
#include  "REMOTE_private.h"
#include  "REMOTE_config.h"

/********************************************** Global variabled  **********************************************/
volatile u8 global_u8Flag                   = 0 ;          /* Flag for start bit of the IR Frame               */
volatile u8 global_u8FinishFlag             = 0 ;          /* Flag indicates Recieving the whole Frame         */
volatile u32 global_u32Frame                = 0 ;          /* Contains the recived IR Frame                    */
volatile u8 global_u8Index                  = 0 ;
volatile u32 global_u32Data                 = 0 ;          /* Variables contains the recived Data              */
volatile u32 global_u32DataInverted         = 0 ;          /* Variables contains the recived inverted Data     */
volatile u32 global_u32Address              = 0 ;          /* Variables contains the recived Address           */
volatile u32 global_u32AddressInverted      = 0 ;          /* Variables contains the recived inverted Address  */
/****************************************************************************************************************/
/* Callback function for EXTI */
void REMOTE_HANDLER(void);
/****************************************************************************************************************/

/*
 @ REMOTE Initialization includes :
   1) NVIC Initialization
   2) EXTI Initialization
   3) Set EXTI PIN as Input floating for IR Reciever [EXTI0 => A0]
   4) Using [EXTI0_IRQHandler] for REMOTE_HANDLER CallBack function
   5) Setting EXTI Mode for IR Reciever => FALLING_EDGE mode
   6) Enable EXTI Interrupt
   7) Configure the AFIO for EXTI mapping
   8) Systick Initialization
   9) Enable EXTI from NVIC
 */

void REMOTE_voidInit(void)
{	
	/* Set EXTI PIN as Input floating for IR Reciever */
	MGPIO_voidSetPinDirection(REMOTE_EXTI_PORT, REMOTE_EXTI_LINE , INPUT_FLOATING);
	

	/* Initialize NVIC */
	NVIC_voidInit();

	/* Configure the AFIO */
//	MAFIO_voidSetEXTIConfiguration(REMOTE_EXTI_LINE,REMOTE_EXTI_PORT);
	/* Enable EXTI Line Interrupt */
	MEXTI_voidEnableEXTI(REMOTE_EXTI_LINE);
	/* Set REMOTE_HANDLER as Callback function for EXTI */
	MEXTI_voidSetCallBack(REMOTE_HANDLER,REMOTE_EXTI_LINE);

	/* Setting EXTI Mode for IR Reciever */
	MEXTI_voidSetSignalLatch(REMOTE_EXTI_LINE,MEXTI_FALLING_EDGE);


	/* Enable EXTI from NVIC */
	NVIC_voidEnableIRQ(REMOTE_NVIC_NUMBER);
	
	/* Initialize Systick  */
	MSTK_voidInit();
}

/****************************************************************************************************************/

REMOTE_buttons_t REMOTE_getButton (void)
{
	REMOTE_buttons_t local_button = REMOTE_NO_DATA ;
	if (global_u8FinishFlag){
		u8 local_u8Check = REMOTE_u8CheckFrame();
		// determine which button was pressed 
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
				case U_SD        :  local_button = REMOTE_U_SD;          break;
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

/****************************************************************************************************************/

void REMOTE_HANDLER(void) 
{
	MEXTI_voidClearPendingFlag(REMOTE_EXTI_LINE);
	/* Get time elapsed*/
	volatile u32 time = MSTK_u32GetElapsedTime(TIME_US);
	/* Start timer to count till the next isr */	
	MSTK_voidStart();
//  	MSTK_voidSetIntervalPeriodic(1,TIME_S,NULL);
	
	/* Wait for the start bit before recording frame [Ideal time = 13500 us]  */
	if((global_u8Flag == 0) && (time > 10000) && (time < 15000))
	{

		global_u8Index = 0 ;
	}
	/* Start bit came and will start recording the frame */
	else if (global_u8Flag == 1)
	{
		/* If bit == 1  [Ideal time = 2250 us] */
		if ((time > 2000 ) && (time < 2400 ))
		{
			SET_BIT(global_u32Frame , global_u8Index );
			global_u8Index++;
		}
		/* If bit == 0  [Ideal time = 1125 us] */
		else if ( (time > 1000 ) &&  (time < 1200 ))
		{
			CLR_BIT(global_u32Frame , global_u8Index );
			global_u8Index++;
		}
		/* the Wait before the next frame */
		else if ( (time > 20000 ))
		{
			global_u8Flag = 0 ;
			global_u8FinishFlag = 1 ; 
		}
		else {

		}
	}
}
/****************************************************************************************************************/
/********************* Private functions **********************/
static u8 REMOTE_u8CheckFrame(void)
{
	/*************** Frame Validation ***************/
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
	
	/* Check the data for errors */
	if ( (global_u32Data & global_u32DataInverted) | (global_u32Address & global_u32AddressInverted) ){
		local_u8Error = FRAME_ERROR ;
	}
	else {
		local_u8Error = FRAME_CORRECT ;
	}
	
	return local_u8Error ;

}
