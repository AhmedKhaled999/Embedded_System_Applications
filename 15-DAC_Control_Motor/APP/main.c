/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task15****************************/
/*Write a C code that control
 * the  Motor Speed by The Analog Voltage by using DAC Circuit
 *
 */


#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"

#define F_CPU  8000000UL
#include<util\delay.h>



int main(void)
{
	u16 LOC_u16DigitalValue=0;
	u16 LOC_u16AnalogValue=0;
	u16 LOC_u16Analog_OldValue=0;


	MDIO_Error_State_SetPortDirection(MDIO_PORTB,PORT_OUTPUT);
	MDIO_Error_State_SetPortValue(MDIO_PORTB,LOC_u16DigitalValue);

	/*LCD Initialization*/
	HCLCD_Vid4Bits_Init();
	/*Send Welcome message*/
	HCLCD_Vid4Bits_DisplayString((u8*)"Welcome....");
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();

	/*  in 4 Bits DAC
	 * Analog_voltage = V_ref *[B0/16 + B1/8 +B2/4 +B3/2] ----> == Digital_Value * Step_size ,  Step_size = 5000/16 = 312.5 mv
	 * if you enter 8 in Digital value ---> Analog_voltage = 8*312.5 = 2500 mv
	 * if V_ref = 12 V --> Step_size = 12000/16 = 750 mv
	 *  */

	while(1)
	{
		for(u8 i = LOC_u16DigitalValue;i<16;i++)
		{
			MDIO_Error_State_SetPortValue(MDIO_PORTB,i);
			LOC_u16AnalogValue=i*312.5;
			if(LOC_u16AnalogValue!=LOC_u16Analog_OldValue)
			{
				HCLCD_Vid4Bits_ClearScreen();
				HCLCD_Vid4Bits_SetPosition(1,0);
				HCLCD_Vid4Bits_DisplayString((u8*)"Digital =");
				HCLCD_Vid4Bits_DisplayNumber(i);
				HCLCD_Vid4Bits_SetPosition(2,0);
				HCLCD_Vid4Bits_DisplayString((u8*)"Analog =");
				HCLCD_Vid4Bits_DisplayNumber(LOC_u16AnalogValue);
				//HCLCD_Vid4Bits_DisplayString("Volte=");
				HCLCD_Vid4Bits_DisplayString((u8*)"MV");
				LOC_u16Analog_OldValue=LOC_u16AnalogValue;
			}
			else
			{
				/*Do Nothing*/
			}
			_delay_ms(2000);
		}
	}
	return 0 ;

}

