/*

 * App.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Ahmed Khaled
 */

#define F_CPU 8000000UL
#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../MCAL/MTWI/MTWI_Interface.h"
#include"../HAL/HEEPROM/HEEPROM_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"

#include<util\delay.h>
int main(void)
{
	u8 Local_u8ReceiveData=1;
	/*Set PORTD as an output*/
	MDIO_Error_State_SetPortDirection(MDIO_PORTD,PORT_OUTPUT);
	_delay_ms(1000);

	/*CLCD Initialization*/
	HCLCD_Vid4Bits_Init();
	HCLCD_Vid4Bits_DisplayString((u8*)"Welcome...");
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();

	//Init EEPROM
	HEEPROM_VidInit();
	_delay_ms(1000);

	HEEPROM_Write_Byte(0x0311,0x0F);    /* Write 0x0F in the external EEPROM*/
	_delay_ms(1000);
	HEEPROM_Read_Byte(0x0311,&Local_u8ReceiveData);  /* Read 0x01 from the external EEPROM*/
	while(1)
	{
		/*EEPROM Send Byte*/
		HEEPROM_Write_Byte(0x0311,0x0F);
		/*Get Data From Memory*/
		_delay_ms(2000);
		HEEPROM_Read_Byte(0x0311,&Local_u8ReceiveData);
		MDIO_Error_State_SetPortValue(MDIO_PORTD,Local_u8ReceiveData);
		HCLCD_Vid4Bits_ClearScreen();
		HCLCD_Vid4Bits_DisplayString("1st Four LEDs ON");
		/*EEPROM Send Byte*/
		HEEPROM_Write_Byte(0x0311,0xF0);
		_delay_ms(2000);
		/*Get Data From Memory*/
		HEEPROM_Read_Byte(0x0311,&Local_u8ReceiveData);
		MDIO_Error_State_SetPortValue(MDIO_PORTD,Local_u8ReceiveData);
		HCLCD_Vid4Bits_ClearScreen();
		HCLCD_Vid4Bits_DisplayString("2nd Four LEDs ON");
	}
	return 0;
}

