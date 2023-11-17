/**************************************************************************/
/* Author  : Mohamed Mostafa                                                                    */
/* Date  	 : 28 SEP 2020                                                                              */
/*Version  : V01																							*/
/************************************************************************/



#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H



void HESP_voidInit(void);
void HESP_voidWifiConnect(u8 * Copy_u8Name,u8 * Copy_u8Password);
void HESP_voidWifiServerUrlTCP(u8 * Copy_u8Url , u8 * Copy_u8Port);
u8	 HESP_u8SendReceiveData(u8 Copy_u8Length,u8 * Copy_u8URL);


#endif
