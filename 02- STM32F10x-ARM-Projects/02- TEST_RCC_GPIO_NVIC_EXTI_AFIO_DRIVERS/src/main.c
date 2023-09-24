/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 23 September  2023                                            */
/*   Logs      : V01 : Testing [GPIO-RCC] Drivers                              */
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

/********************************/
/*  # Functions Declarations #  */
/********************************/
/* CallBack Function for EXTI0  */
void EXTI0_Mohamed (void);
/* CallBack Function for EXTI1  */
void EXTI1_Maged   (void);
/* CallBack Function for EXTI2  */
void EXTI2_Khalil  (void);
/********************************/



void main (void)
{
	/* Initialize system clock */
	RCC_voidInitSysClock();

	/* Enable AFIO Peripheral */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_AFIO);

	/* Enable GPIOA Peripheral */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOA);


	/* Initialize NVIC */
	MNVIC_voidInit();


	//--------------------- OUTPUT PINS ---------------------------//
	/* Configure Pin Mode for GPIOA_PIN3 as Output 2 MHZ */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN3,OUTPUT_SPEED_2MHZ_PP);
	/* Set default state of output pin as LOW                */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN3,GPIO_LOW);


	/* Configure Pin Mode for GPIOA_PIN4 as Output 2 MHZ */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN4,OUTPUT_SPEED_2MHZ_PP);
	/* Set default state of output pin as LOW                */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN4,GPIO_LOW);


	/* Configure Pin Mode for GPIOA_PIN5 as Output 2 MHZ */
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN5,OUTPUT_SPEED_2MHZ_PP);
	/* Set default state of output pin as LOW                */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN5,GPIO_LOW);

	//--------------------- INPUT PINS ---------------------------//

	/* Configure Pin Mode for GPIOA_PIN0 as input ===> PULL UP Resistor	*/
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN0,INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN0,GPIO_HIGH);

	/* Configure Pin Mode for GPIOA_PIN1 as input ===> PULL UP Resistor	*/
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN1,INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN1,GPIO_HIGH);

	/* Configure Pin Mode for GPIOA_PIN2 as input ===> PULL UP Resistor	*/
	MGPIO_voidSetPinDirection(GPIOA,GPIO_PIN2,INPUT_PULLUP_PULLDOWN);
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN2,GPIO_HIGH);


	//--------------------- AFIO PINS ---------------------------//
	/* Set AFIO for EXTI0 -> GPIOA_PIN0 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI0,MAFIO_PORT_A);

	/* Set AFIO for EXTI1 -> GPIOA_PIN1 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI1,MAFIO_PORT_A);

	/* Set AFIO for EXTI2 -> GPIOA_PIN2 */
	MAFIO_voidSetEXTIConfiguration(MAFIO_EXTI2,MAFIO_PORT_A);

	//---------------- EXTI Callback functions  -----------------//
	/* Set CallBack Function for EXTI0  */
	MEXTI_voidSetCallBack(EXTI0_Mohamed,MEXTI_LINE0);

	/* Set CallBack Function for EXTI1  */
	MEXTI_voidSetCallBack(EXTI1_Maged,MEXTI_LINE1);

	/* Set CallBack Function for EXTI2  */
	MEXTI_voidSetCallBack(EXTI2_Khalil,MEXTI_LINE2);

	//----------- Setup the Signal Latch for EXTI0  -------------//
	//    Choose FALLING_EDGE cause all input pins are High      //
	MEXTI_voidSetSignalLatch(MEXTI_LINE0,MEXTI_FALLING_EDGE);

	//----------- Setup the Signal Latch for EXTI1  -------------//
	//    Choose FALLING_EDGE cause all input pins are High      //
	MEXTI_voidSetSignalLatch(MEXTI_LINE1,MEXTI_FALLING_EDGE);

	//----------- Setup the Signal Latch for EXTI2  -------------//
	//    Choose FALLING_EDGE cause all input pins are High      //
	MEXTI_voidSetSignalLatch(MEXTI_LINE2,MEXTI_FALLING_EDGE);

	//--------------------- Set Priorities ----------------------//
	//        ## Number of groups = number of nesting ##        //
	/*           Set EXTI0 => [Group = 0 - Sub = 0 ]            */
	MNVIC_voidSetPriority(EXTI0_IRQ,0,0,MNVIC_GROUP_4_SUB_4);

	/*           Set EXTI1 => [Group = 1 - Sub = 0 ]            */
	MNVIC_voidSetPriority(EXTI1_IRQ,1,0,MNVIC_GROUP_4_SUB_4);

	/*           Set EXTI2 => [Group = 2 - Sub = 0 ]            */
	MNVIC_voidSetPriority(EXTI2_IRQ,2,0,MNVIC_GROUP_4_SUB_4);


	//------------- Enable [EXTI0 - EXTI1 - EXTI2]  -------------//
	/* Enable EXTI0 from NVIC */
	MNVIC_voidEnableInterrupt(EXTI0_IRQ);

	/* Enable EXTI1 from NVIC */
	MNVIC_voidEnableInterrupt(EXTI1_IRQ);

	/* Enable EXTI2 from NVIC */
	MNVIC_voidEnableInterrupt(EXTI2_IRQ);

	while(1)
	{

	}
}


/* CallBack Function for EXTI0  */
void EXTI0_Mohamed (void)
{
	/* Set GPIOA-PIN3 As High             */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN3,GPIO_HIGH);

	/* NON-professional Delay before implementing [Systick Driver] */
	for(u16 i=0 ; i<1000 ; i++)
	{
		for(u16 y=0 ; y <500 ; y++)
		{

		}
	}

	/* Set GPIOA-PIN3 As LOW                */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN3,GPIO_LOW);

	/* NON-professional Delay before implementing [Systick Driver] */
	for(u16 i=0 ; i<1000 ; i++)
	{
		for(u16 y=0 ; y <500 ; y++)
		{

		}
	}


}

/* CallBack Function for EXTI1  */
void EXTI1_Maged (void)
{
	/* Set GPIOA-PIN4 As High             */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN4,GPIO_HIGH);

	/* NON-professional Delay before implementing [Systick Driver] */
	for(u16 i=0 ; i<1000 ; i++)
	{
		for(u16 y=0 ; y <500 ; y++)
		{

		}
	}

	/* Set GPIOA-PIN4 As Low             */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN4,GPIO_LOW);

	/* NON-professional Delay before implementing [Systick Driver] */
	for(u16 i=0 ; i<1000 ; i++)
	{
		for(u16 y=0 ; y <500 ; y++)
		{

		}
	}

}

/* CallBack Function for EXTI2  */
void EXTI2_Khalil (void)
{
	/* Set GPIOA-PIN5 As High             */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN5,GPIO_HIGH);

	/* NON-professional Delay before implementing [Systick Driver] */
	for(u16 i=0 ; i<1000 ; i++)
	{
		for(u16 y=0 ; y <500 ; y++)
		{

		}
	}

	/* Set GPIOA-PIN5 As Low             */
	MGPIO_voidSetOrResetPinValue_BSRR_BRR(GPIOA,GPIO_PIN5,GPIO_LOW);

	/* NON-professional Delay before implementing [Systick Driver] */
	for(u16 i=0 ; i<1000 ; i++)
	{
		for(u16 y=0 ; y <500 ; y++)
		{

		}
	}



}

