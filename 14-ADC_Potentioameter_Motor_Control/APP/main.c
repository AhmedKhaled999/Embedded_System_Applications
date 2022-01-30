/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task14****************************/
/*Write a C code that that Generate PWM With F =  245.0980392Hz ,D = 75%  by phase Correct Fast PWM mode IN TIMER0  and control
 * the  Motor Speed by The potentiometer
 *
 */


#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../MCAL/MTIMER/MTIMER_Interface.h"
#include"../MCAL/MADC/MADC_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"

#define F_CPU  8000000UL
#include<util\delay.h>

/*Hardware Interface--> OC0*/
LED_t Y_LED4 = {HLED_PORTB,PIN3};


int main(void)
{
	u16 LOC_u16DigitalValue=0;
	u16 LOC_u16AnalogValue=0;
	u16 LOC_u16Analog_OldValue=0;
	u16 LOC_u16OCR_Value = 0 ;

	/*Generate PWM on this OC0-->Pin PB3*/
	HLED_VidInit(&Y_LED4);
	/*LCD Initialization*/
	HCLCD_Vid4Bits_Init();
	/*Send Welcome message*/
	HCLCD_Vid4Bits_DisplayString((u8*)"Welcome....");
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();
	/*Initialize ADC*/
	MADC_VidInit();

	/*F_cpu = 8MHz, prescaler = 64 -->F_timer = 125000HZ , T_tick = 8 micro second ,One_OVF = 256*8 = 2048  micro second ,
	 * F_out = Fcpu/N*510
	 * F_out           |   N     |
	 * ----------------|---------|
	 * 15686.27451Hz   |   1     |
	 * ----------------|---------|    510 ticks---->4.08ms
	 * 1960.784314Hz   |   8     |     ?? ticks---->3.06ms   ----------->??=382.5 ticks   so,OCR = 382.5/2 = 191 Ticks
	 * ----------------|---------|
	 * 245.0980392Hz   |   64    |
	 *-----------------|---------|
	 * 61.2745098Hz    |   256   |
	 *-----------------|---------|
	 * 15.31862745Hz   |   1024  |
	 *-----------------|---------|
	 * T = 1 / F_out --> 1/245.0980392 = 4080 micro second  = 4.08 ms
	 * Duty cycle = (T_on*100)/T
	 * T_on depend on the  the value of OCR
	 * if you need D = 75% --> T_on = T*D = 4.08 * 0.75 = 3.06 ms -->Note OCR = 192 ticks    if you in NON_Inverting mode
	 * V_out = D * V_in
	 * */
	/*Set CTC Value-->DutyCycle=75%*/
	MTIMER0_VidSetCTCValue(191);

	/*Timer0 Initialization in Phase Correct PWM */
	MTIMER0_VidInit();
	/*Enable To GIE*/
	//MGIE_VidEnable();
   /**********************************************************************************************
    * 	1023 Digital values -----> 255    Counts    ---> 1 Counts = 4 Digital Values
    * 	xx   //		//	    -----> 191    Counts    ---> xx =770 Digital Values																			 *
    * */
	while(1)
		{
			LOC_u16DigitalValue=MADC_u16ADC_StartConversion(CHANNEL_0);
			LOC_u16AnalogValue=(LOC_u16DigitalValue*5000UL)/1023;
			LOC_u16OCR_Value = LOC_u16DigitalValue/4 ;
			if(LOC_u16AnalogValue!=LOC_u16Analog_OldValue)
			{
				HCLCD_Vid4Bits_ClearScreen();
				HCLCD_Vid4Bits_SetPosition(1,0);
				HCLCD_Vid4Bits_DisplayString((u8*)"Digital =");
				HCLCD_Vid4Bits_DisplayNumber(LOC_u16DigitalValue);
				HCLCD_Vid4Bits_SetPosition(2,0);
				HCLCD_Vid4Bits_DisplayString((u8*)"Analog =");
				HCLCD_Vid4Bits_DisplayNumber(LOC_u16AnalogValue);
				//HCLCD_Vid4Bits_DisplayString("Volte=");
				HCLCD_Vid4Bits_DisplayString((u8*)"MV");
			    LOC_u16Analog_OldValue=LOC_u16AnalogValue;
				MTIMER0_VidSetCTCValue(LOC_u16OCR_Value);

			}
			else
			{
				/*Do Nothing*/
			}
		}
	return 0 ;

}

