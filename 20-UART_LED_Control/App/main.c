/*

 * main.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Ahmed Khaled Hammad
 */

#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../MCAL/MUSART/MUSART_Interface.h"
#include"../MCAL/MEXTI/MEXTI_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../MCAL/MADC/MADC_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"

#define F_CPU 8000000

#define M2_READY 0x10

#include<util\delay.h>
int main(void)
{
	//u8 LOC_u8ReceiveValue = 0  ;
	/*Set TX Pin-->PIND1  as an output*/
	MDIO_Error_State_SetPinDirection(PIN1,MDIO_PORTD,PIN_OUTPUT);
	/*Set RX Pin-->PIND0  as an input*/
	MDIO_Error_State_SetPinDirection(PIN0,MDIO_PORTD,PIN_INPUT);


	/*USART Initialization*/
	MUSART_VidInit();
	while(MUSART_VidReceiveData() != M2_READY){} // wait until MC2 is ready

	MUSART_VidSendString("I am Micro1#"); // send the required string to MC2
	u8 name[] = "AHMED#KHALED*" ;
	for(u8 i = 0 ; i < 13 ; i++)
	{
		while(MUSART_VidReceiveData() != M2_READY){} // wait until MC2 is ready
		MUSART_VidSendChar(name[i]);
	}
	while(1)
	{


	}

	return 0;
}
