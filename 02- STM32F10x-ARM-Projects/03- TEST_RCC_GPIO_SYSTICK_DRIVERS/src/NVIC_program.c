/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V03                                                           */
/*   Date      : 17 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all NVIC Driver to make it more professional     */
/*               V03 : Update MNVIC_voidSetPriority function                   */
/*******************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "NVIC_interface.h"
#include  "NVIC_private.h"
#include   "NVIC_config.h"

//-------------------------------------------------------------------------------------
/*
 MNVIC_voidInit - > Initialize the periority system (determine the number of group priorities and sub priorties)
*/
void MNVIC_voidInit(void)
{
	/* Choose configurations */
	//0 bit for sub & 4 bit For group
	#if   MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_16_SUB_0
		SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

	//1 bit for sub & 3 bit For group
	#elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_8_SUB_2
		SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

	//2 bit for sub & 2 bit For group
	#elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_4_SUB_4
		SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

	//3 bit for sub & 1 bit For group
	#elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_2_SUB_8
		SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

	//4 bit for sub & 0 bit For group
	#elif MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_0_SUB_16
		SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

	#else
		#error (" Configuration error ")
	#endif
}
//-------------------------------------------------------------------------------------

/*
  * MNVIC_voidEnableInterrupt - > Enable a specific external interrupt
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/
void MNVIC_voidEnableInterrupt       (NVIC_IRQn_t Copy_IRQn)
{
	/* Devided by 32 to write to the right regsiter index         */
	/* Anding (Copy_IRQn) with 31 so value will always be under 32 */
	u8 reg_index = Copy_IRQn / 32 ;
	NVIC->ISER[reg_index] = ( 1 << (Copy_IRQn & 31));
}
//-------------------------------------------------------------------------------------

/*
  * MNVIC_voidDisableInterrupt - > Disable a specific external interrupt
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/
void MNVIC_voidDisableInterrupt      (NVIC_IRQn_t Copy_IRQn)
{
	/* Devided by 32 to write to the right regsiter index         */
	/* Anding (Copy_IRQn) with 31 so value will always be under 32 */
	u8 reg_index = Copy_IRQn / 32 ;
	NVIC->ICER[reg_index] = ( 1 << (Copy_IRQn & 31));
}
//-------------------------------------------------------------------------------------


/*
  * MNVIC_voidSetPendingFlag - > set pending flag for a specific external interrupt
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/

void MNVIC_voidSetPendingFlag        (NVIC_IRQn_t Copy_IRQn)
{
	/* Devided by 32 to write to the right regsiter index         */
	/* Anding (Copy_IRQn) with 31 so value will always be under 32 */
	u8 reg_index = Copy_IRQn / 32 ;
	NVIC->ISPR[reg_index] = ( 1 << (Copy_IRQn & 31));
}

//-------------------------------------------------------------------------------------

/*
  * MNVIC_voidClearPendingFlag - > Clear pending flag for a specific external interrupt
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
*/

void MNVIC_voidClearPendingFlag      (NVIC_IRQn_t Copy_IRQn)
{
	/* Devided by 32 to write to the right regsiter index         */
	/* Anding (Copy_IRQn) with 31 so value will always be under 32 */
	u8 reg_index = Copy_IRQn / 32 ;
	NVIC->ICPR[reg_index] = ( 1 << (Copy_IRQn & 31));
}
//-------------------------------------------------------------------------------------

/*
  * MNVIC_u8GetPendingFlag - > Get the pending flag state
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
  * o/p : (u8) 0 or 1
*/

u8 MNVIC_u8GetPendingFlag            (NVIC_IRQn_t Copy_IRQn)
{
	u8 reg_index = Copy_IRQn / 32 ;
	u8 Local_u8Result = GET_BIT(NVIC->ISPR[reg_index],(Copy_IRQn & 31));
	return Local_u8Result;

}
//-------------------------------------------------------------------------------------

/*
  * MNVIC_u8GetActiveFlag - > Get the Active flag state
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
  * o/p : (u8) 0 or 1
*/


u8   MNVIC_u8GetActiveFlag           (NVIC_IRQn_t Copy_IRQn)
{
	u8 reg_index = Copy_IRQn / 32 ;
	u8 Local_u8Result = GET_BIT(NVIC->IABR[reg_index],(Copy_IRQn & 31));
	return Local_u8Result;
}
//-------------------------------------------------------------------------------------

/*
  * MNVIC_voidSetPriority - > Set periority for a specific external interrupt
  * i/p : Interrupt number (NVIC_IRQn_t) 0:59
          Copy_u8GroupPriority(u8) -> Decimal number
		  Copy_u8SubPriority(u8)   -> Decimal number
		  Copy_u8Group(u32) :
				// Group priority options //
				#define     MNVIC_GROUP_16_SUB_0        0x05FA0300 //0 bit for sub & 4 bit For group   << 0
				#define     MNVIC_GROUP_8_SUB_2         0x05FA0400 //1 bit for sub & 3 bit For group   << 1
				#define     MNVIC_GROUP_4_SUB_4         0x05FA0500 //2 bit for sub & 2 bit For group   << 2
				#define     MNVIC_GROUP_2_SUB_8         0x05FA0600 //3 bit for sub & 1 bit For group   << 3
				#define     MNVIC_GROUP_0_SUB_16        0x05FA0700 //4 bit for sub & 0 bit For group   << 4

NOTE::
	Each priority field holds a priority value, 0-255. The lower the value,
	the greater the priority of the corresponding interrupt. The processor
	implements only bits[7:4] of each field
	** That is why i shift (copy_u8Priority << 4) by 4 **
*/
void MNVIC_voidSetPriority (NVIC_IRQn_t Copy_IRQn, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority , MNVIC_GROUP_SUB_t Copy_u8Group )
{
	u8 Local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - MNVIC_GROUP_16_SUB_0) / 256 );
	// For Core Peripheral //
	//TODO:: 
	
	// For External Peripheral //
	/* Writing into the four bit the priority */
	NVIC->IPR[Copy_IRQn] = (Local_u8Priority << 4);
	
	SCB_AIRCR = Copy_u8Group ;
}

//-------------------------------------------------------------------------------------

