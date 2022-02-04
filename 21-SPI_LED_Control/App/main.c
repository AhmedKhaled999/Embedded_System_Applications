/*

 * main.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Ahmed Khaled Hammad
 */

#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../MCAL/MEXTI/MEXTI_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"
#include"../MCAL\MSPI\MSPI_Interface.h"

#define F_CPU 8000000
#define M2_READY 0x10

#include<util\delay.h>
int main(void)
{
	/*Set MOSI Pin --> PINB5 as an Output*/
	MDIO_Error_State_SetPinDirection(PIN5,MDIO_PORTB,PIN_OUTPUT);
	/*Set MISO Pin --> PINB6 as an Input*/
	MDIO_Error_State_SetPinDirection(PIN6,MDIO_PORTB,PIN_INPUT);
	/*Set SCK  Pin --> PINB7 as an output*/
	MDIO_Error_State_SetPinDirection(PIN7,MDIO_PORTB,PIN_OUTPUT);

	MSPI_VidMaster_Init();

    _delay_ms(2000);

    while(MSPI_u8Send_Receive_Char(0) != M2_READY){}
    MSPI_u8Send_String("I am Micro1#");

	/*u8 name[] = "AHMED#KHALED*" ;
		for(u8 i = 0 ; i < 13 ; i++)
		{
			//MSPI_u8Send_Char(0);
			//while(MSPI_u8Send_Receive_Char('0') != M2_READY){} // wait until MC2 is ready
			MSPI_u8Send_Receive_Char(name[i]);
			_delay_ms(100);
		}*/
	while(1)
	{
		MSPI_u8Send_Receive_Char(2);
		_delay_ms(1000);
		MSPI_u8Send_Receive_Char(1);
		_delay_ms(1000);

	}
	return 0;
}


