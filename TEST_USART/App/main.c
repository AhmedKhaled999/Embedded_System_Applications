/*

 * main.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Ahmed Khaled Hammad
 */

#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../MCAL/MUSART/MUSART_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"

#define F_CPU 8000000

#define M2_READY 0x10


#include<util\delay.h>

LED_t LED = {HLED_PORTA,PIN0};

int main(void)
{
	u8 LOC_u8ReciveValue = 0 ;
	u8 bufer[20];

	/*Set TX Pin-->PIND1  as an output*/
	MDIO_Error_State_SetPinDirection(PIN1,MDIO_PORTD,PIN_OUTPUT);
	/*Set RX Pin-->PIND0  as an input*/
	MDIO_Error_State_SetPinDirection(PIN0,MDIO_PORTD,PIN_INPUT);
	/*set Led Pin-->PINA0 as an output*/
	HLED_VidInit(&LED);
	/*USART Initialization*/
	MUSART_VidInit();
	/*CLCD Initialization*/
	HCLCD_Vid4Bits_Init();
	HCLCD_Vid4Bits_DisplayString((u8*)"Welcome...");
	_delay_ms(100);
	HCLCD_Vid4Bits_ClearScreen();
	MUSART_VidSendChar(M2_READY); // MC2 is ready
	MUSART_VidReceiveString(bufer);
	HCLCD_Vid4Bits_DisplayString(bufer); // display the string on LCD
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();

	while(1)
	{
		MUSART_VidSendChar(M2_READY); // MC2 is ready
		LOC_u8ReciveValue = MUSART_VidReceiveData();
		if((LOC_u8ReciveValue!='#')&&(LOC_u8ReciveValue!='*'))
		{
			HCLCD_Vid4Bits_DisplayCharacter(LOC_u8ReciveValue);
		}
		else if(LOC_u8ReciveValue =='#')
		{
			HCLCD_Vid4Bits_DisplayCharacter(' ');

		}
		else if(LOC_u8ReciveValue =='*')
		{
			HLED_VidLed_Toggle(&LED);
			_delay_ms(1000);
			HCLCD_Vid4Bits_ClearScreen();
		}
		else
		{/*Do Nothing*/}

	}


	return 0;
}
