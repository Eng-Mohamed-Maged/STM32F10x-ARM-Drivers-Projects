/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V04                                                           */
/*   Date      : 25 September 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*               V02 : Update all NVIC Driver to make it more professional     */
/*               V03 : Update MNVIC_voidSetPriority function                   */
/*               V04 : Error Fixed - Modifications on MNVIC_voidSetPriority    */
/*******************************************************************************/
#ifndef	NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*
NOTE: 
The address of NVIC_ISER[2] = 0xE000E108
The address of NVIC_ICER[0] = 0xE000E180
#So you should put (0xE000E180 - 0xE000E10B) = 116 Bytes = 29 array locations * 4 as a reserved bits in struct

The address of NVIC_IABR[2] = 0xE000E308
The address of NVIC_IPR[0]  = 0xE000E400
#So you should put (0xE000E400 - 0xE000E30B) = 245 Bytes = 61 array locations * 4 as a reserved bits in struct



*/

/* Struct for the NVIC regsiter mapping */
typedef struct
{
	
     volatile u32 ISER[3]         ;   /* Interrupt Set Enable Registers                     */
	 volatile u32 RESERVED0[29]   ;   /* 116 Bytes reserved                                 */
     volatile u32 ICER[3]         ;   /* Interrupt Clear Enable Registers                   */
	 volatile u32 RESERVED1[29]   ;   /* 116 Bytes reserved                                 */
     volatile u32 ISPR[3]         ;   /* Interrupt Set Pending Registers                    */             
	 volatile u32 RESERVED2[29]   ;   /* 116 Bytes reserved                                 */  
     volatile u32 ICPR[3]         ;   /* Interrupt Clear Pending Registers                  */               
	 volatile u32 RESERVED3[29]   ;	  /* 116 Bytes reserved                                 */
     volatile u32 IABR[3]         ;   /* Interrupt Active Bit Registers                     */            
     volatile u32 RESERVED4[61]   ;	  /* 245 Bytes reserved                                 */   
	 volatile u8  IPR[80]         ;   /* Interrupt Priority registers                       */
	
}NVIC_t;

/* Register defintions  */
#define   NVIC_BASE_ADDRESS             0xE000E100
#define   SCB_BASE_ADDRESS              0xE000ED0C
#define   NVIC                          ((volatile NVIC_t *)NVIC_BASE_ADDRESS)
#define   NVIC_STIR                    *((volatile u32    *)NVIC_BASE_ADDRESS + 0xE00 )
#define	  SCB_AIRCR                    *((volatile u32    *)SCB_BASE_ADDRESS)


// Group priority options //
// Note:: These Macros including [VECTKEY = 0x05FA0000] 
/*
#define     MNVIC_GROUP_16_SUB_0        0x05FA0300 //0 bit for sub & 4 bit For group   << 0
#define     MNVIC_GROUP_8_SUB_2         0x05FA0400 //1 bit for sub & 3 bit For group   << 1
#define     MNVIC_GROUP_4_SUB_4         0x05FA0500 //2 bit for sub & 2 bit For group   << 2
#define     MNVIC_GROUP_2_SUB_8         0x05FA0600 //3 bit for sub & 1 bit For group   << 3
#define     MNVIC_GROUP_0_SUB_16        0x05FA0700 //4 bit for sub & 0 bit For group   << 4
*/



#endif
