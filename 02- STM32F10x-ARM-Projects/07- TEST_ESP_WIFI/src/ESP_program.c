#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ESP_interface.h"
#include"ESP_private.h"
#include"ESP_config.h"


#include<stdio.h>
#include <string.h>

u8 Global_u8Action;

void HESP_voidInit(void)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Stop Echo */
		MUSART1_voidTransmit("ATE0\r\n");
		/* Check if CMD was sent correctly */
		Local_u8Result = u8ESPValidateCmd() ;
 	}

	Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Set Station mode */
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		/* Check if CMD was sent correctly */
		Local_u8Result = u8ESPValidateCmd() ;
	}

}




void HESP_voidWifiConnect(u8 * Copy_u8Name,u8 * Copy_u8Password)
{
//	u8 Data_String[36] ={0};
//	sprintf(Data_String,"%s%s%s%s%s","AT+CWJAP_CUR=\"",Copy_u8Name,"\",\"",Copy_u8Password,"\"\r\n");
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
/*********** Connect On WiFi ***********/
//		MUSART1_voidTransmit(Data_String);
		MUSART1_voidTransmit("AT+CWJAP_CUR=\"");
		MUSART1_voidTransmit(Copy_u8Name);
		MUSART1_voidTransmit("\",\"");
		MUSART1_voidTransmit(Copy_u8Password);
		MUSART1_voidTransmit("\"\r\n");

		Local_u8Result =u8ESPValidateCmd();
	}
	
}

void HESP_voidWifiServerUrlTCP(u8 * Copy_u8Url , u8 * Copy_u8Port)
{
//	u8 Data_String2[40] ={0};
//	sprintf(Data_String2,"%s%s%s%s%s","AT+CIPSTART=\"TCP\",\"",Copy_u8Url,"\",",Copy_u8Port,"\r\n");
	u8 Local_u8Result = 0;
	while(Local_u8Result==0)
	{
/*********** Connect On Server ***********/
//		MUSART1_voidTransmit(Data_String2);
		MUSART1_voidTransmit("AT+CIPSTART=\"TCP\",\"");
		MUSART1_voidTransmit(Copy_u8Url);
		MUSART1_voidTransmit("\",");
		MUSART1_voidTransmit(Copy_u8Port);
		MUSART1_voidTransmit("\r\n");

		Local_u8Result = u8ESPValidateCmd();
	}
	
}

u8 HESP_u8SendReceiveData(u8 Copy_u8Length,u8 * Copy_u8URL)
{
	u8 Data_String3[15] ={0};
	sprintf(Data_String3,"%s%d%s","AT+CIPSEND=",Copy_u8Length,"\r\n");

	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
/******** Send length of data **********/
		MUSART1_voidTransmit(Data_String3);
		Local_u8Result = u8ESPValidateCmd();
	}
	Local_u8Result=0;

	u8 Data_String2[48] ={0};
	sprintf(Data_String2,"%s%s%s","GET ",Copy_u8URL,"\r\n");
	while(Local_u8Result==0)
	{
/******** Send Data **********/
		MUSART1_voidTransmit(Data_String2);
		Local_u8Result = u8ESPValidateCmd();
	}
	return Global_u8Action;
}


static u8 u8ESPValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i=0;
	u8 Result = 0;
	while( i<= 100)
	{
		Local_u8Response[i] = MUSART1_u8Receive();
		i++;
	}
	for(u8 i=0;i<70;i++)
	{
		if(Local_u8Response[i]==':')
		{
			Global_u8Action = Local_u8Response[i+1];
		}
	}
	
	/* Check if "OK" */
	for(u8 i=0;i<100;i++)
	{
		if(Local_u8Response[i]=='O' &&Local_u8Response[i+1]=='K')
		{
			Result = 1;
			break;
		}
	}
	return Result;
	
}
