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
#include"../HAL/HLED/HLED_Interface.h"
#include"../MCAL\MSPI\MSPI_Interface.h"

#define F_CPU 8000000
#define M2_READY 0x10

#include<util\delay.h>
int main(void)
{
	u8 bufer[20];
	LED_t LED1={MDIO_PORTA,PIN0};
	/*Set MOSI Pin --> PINB5 as an Input*/
	MDIO_Error_State_SetPinDirection(PIN5,MDIO_PORTB,PIN_INPUT);
	/*Set MISO Pin --> PINB6 as an Output*/
	MDIO_Error_State_SetPinDirection(PIN6,MDIO_PORTB,PIN_OUTPUT);
	/*Set SCK  Pin --> PINB7 as an Input*/
	MDIO_Error_State_SetPinDirection(PIN7,MDIO_PORTB,PIN_INPUT);

	HLED_VidInit(&LED1);

	MSPI_VidSlave_Init();
	/*CLCD Initialization*/
	HCLCD_Vid4Bits_Init();
	HCLCD_Vid4Bits_DisplayString((u8*)"Welcome...");
	_delay_ms(100);
	HCLCD_Vid4Bits_ClearScreen();
	MSPI_u8Send_Receive_Char(M2_READY);
	MSPI_Receive_String(bufer);
	HCLCD_Vid4Bits_DisplayString(bufer);
	_delay_ms(1000);

	u8 LOC_u8SPIReceivechar;
	while(1)
	{
		LOC_u8SPIReceivechar = MSPI_u8Send_Receive_Char(0);
		if(LOC_u8SPIReceivechar==2)
		{
			HLED_VidLed_On(&LED1);
			HCLCD_Vid4Bits_ClearScreen();
			HCLCD_Vid4Bits_DisplayCharacter('2');
		}
		else if(LOC_u8SPIReceivechar==1)
		{
			HLED_VidLed_Off(&LED1);
			HCLCD_Vid4Bits_ClearScreen();
			HCLCD_Vid4Bits_DisplayCharacter('1');
		}
		else
		{
			/*Do Nothing*/
		}
	}
	return 0;
}
/*
  MSPI_u8Send_Receive_Char(M2_READY);
 LOC_u8SPIReceivechar = MSPI_u8Send_Receive_Char(0);
				if((LOC_u8SPIReceivechar!='#')&&(LOC_u8SPIReceivechar!='*'))
				{
					HCLCD_Vid4Bits_DisplayCharacter(LOC_u8SPIReceivechar);
				}
				else if(LOC_u8SPIReceivechar =='#')
				{
					HCLCD_Vid4Bits_DisplayCharacter(' ');

				}
				else if(LOC_u8SPIReceivechar =='*')
				{
					HLED_VidLed_Toggle(&LED1);
					_delay_ms(1000);
					HCLCD_Vid4Bits_ClearScreen();
				}
				else
		{}
 */
