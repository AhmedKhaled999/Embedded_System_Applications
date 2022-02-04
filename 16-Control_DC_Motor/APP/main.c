/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task10****************************/
/*Write a C code that that Generate PWM With F = 3906.25Hz ,D = 75%  by Fast PWM mode and control the  Motor Speed with it :
 */


#include"../LIB/LSTD_TYPES.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../HAL/HSWITCH/HSWITCH_Interface.h"
#include"../MCAL/MEXTI/MEXTI_Interface.h"
#include"../MCAL/MGIE/MGIE_Interface.h"
#include"../MCAL/MTIMER/MTIMER_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"

#define F_CPU  8000000UL
#include<util\delay.h>

/*Hardware Interface--> OC0*/
LED_t Y_LED4 = {HLED_PORTB,PIN3};

SWITCH_t SW1 = {HSWITCH_PORTA,PIN7};
SWITCH_t SW2 = {HSWITCH_PORTA,PIN6};
SWITCH_t SW3 = {HSWITCH_PORTA,PIN5};
SWITCH_t SW4 = {HSWITCH_PORTA,PIN4};
SWITCH_t SW5 = {HSWITCH_PORTD,PIN3};
SWITCH_t SW6 = {HSWITCH_PORTD,PIN2};


volatile static u8 speed = 127;

int main(void)
{
	MEXTI0_VidInit();
	MEXTI1_VidInit();
	MGIE_VidEnable();
	/*Initialize LCD*/
	HCLCD_Vid4Bits_Init();
	HCLCD_Vid4Bits_DisplayString("Welcome...");
	/*PINA0 Output RED-LED */
	MDIO_Error_State_SetPinDirection(PIN0,MDIO_PORTA,PIN_OUTPUT);
	/*PINA1 Output GREEN-LED */
	MDIO_Error_State_SetPinDirection(PIN1,MDIO_PORTA,PIN_OUTPUT);
	/*PINA7 INPUT SW-start*/
	HSWITCH_VidInit_PullUP(&SW1);
	/*PINA6 INPUT SW-CW*/
	HSWITCH_VidInit_PullUP(&SW2);
	/*PINA5 INPUT SW-CCW*/
	HSWITCH_VidInit_PullUP(&SW3);
	/*PINA4 INPUT SW-STOP*/
	HSWITCH_VidInit_PullUP(&SW4);
	/*PIND3 INPUT speed increase*/
	HSWITCH_VidInit_PullUP(&SW5);
	/*PIND2 INPUT Speed-decrease*/
	HSWITCH_VidInit_PullUP(&SW6);
	/*PINB0 Output A-Motor */
	MDIO_Error_State_SetPinDirection(PIN0,MDIO_PORTB,PIN_OUTPUT);
	/*PINB1 Output B-Motor */
	MDIO_Error_State_SetPinDirection(PIN1,MDIO_PORTB,PIN_OUTPUT);

	/*F_cpu = 8MHz, prescaler = 8 -->F_timer = 1MHZ , T_tick = 1 micro second ,One_OVF = 256*1 = 256  micro second ,
	 * F_out = Fcpu/N*256
	 * F_out           |   N     |
	 * ----------------|---------|
	 * 31250Hz         |   1     |
	 * ----------------|---------|
	 * 3906.25Hz       |   8     |
	 * ----------------|---------|
	 * 488.28125Hz     |   64    |
	 *-----------------|---------|
	 * 122.0703125Hz   |   256   |
	 *-----------------|---------|
	 * 30.51757813Hz   |   1024  |
	 *-----------------|---------|
	 * T = 1 / F_out --> 1/3906.25 = 256 micro second
	 * Duty cycle = (T_on*100)/T
	 * T_on depend on the  the value of OCR
	 * if you need D = 75% --> T_on = T*D = 256 * 0.75 = 192 micro second -->Note OCR = 192 ticks    if you in NON_Inverting mode
	 * V_out = D * V_in
	 * */

	//MTIMER0_VidSetCTCValue(192);
	/*Timer Initialization*/
	MTIMER0_VidInit();

	/*Generate PWM on this OC0-->Pin PB3*/
	HLED_VidInit(&Y_LED4);
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();

	while(1)
	{       /*Start DC Motor*/
		if((HSWITCH_u8SwitchState(&SW1)==PRESSED))
		{   /*De-bouncing*/
			_delay_ms(100);
			if(HSWITCH_u8SwitchState(&SW1)==PRESSED)
			{
				/*PINB0 Output A-Motor */
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTB,PIN_HIGH);
				/*PINB1 Output B-Motor */
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTB,PIN_LOW);
				/*GREEN LED ON And RED LED OFF*/
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTA,PIN_HIGH);
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTA,PIN_LOW);

			}
		}
		/*CW Direction*/

		else if(HSWITCH_u8SwitchState(&SW2)==PRESSED)
		{
			/*De-bouncing*/
			_delay_ms(100);
			if(HSWITCH_u8SwitchState(&SW2)==PRESSED)
			{
				/*PINB0 Output A-Motor */
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTB,PIN_HIGH);
				/*PINB1 Output B-Motor */
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTB,PIN_LOW);
				/*GREEN LED ON And RED LED OFF*/
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTA,PIN_HIGH);
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTA,PIN_LOW);
			}
		}
		/*CCW Direction*/

		else if(HSWITCH_u8SwitchState(&SW3)==PRESSED)
		{
			/*De-bouncing*/
			_delay_ms(100);

			if(HSWITCH_u8SwitchState(&SW3)==PRESSED)
			{
				/*PINB0 Output A-Motor */
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTB,PIN_LOW);
				/*PINB1 Output B-Motor */
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTB,PIN_HIGH);
				/*GREEN LED ON And RED LED OFF*/
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTA,PIN_HIGH);
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTA,PIN_LOW);
			}

		}
		/*Stop DC Motor*/

		else if(HSWITCH_u8SwitchState(&SW4)==PRESSED)
		{
			/*De-bouncing*/
			_delay_ms(100);

			if(HSWITCH_u8SwitchState(&SW4)==PRESSED)
			{
				/*PINB0 Output A-Motor */
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTB,PIN_LOW);
				/*PINB1 Output B-Motor */
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTB,PIN_LOW);
				/*GREEN LED OFF And RED LED ON*/
				MDIO_Error_State_SetPinValue(PIN0,MDIO_PORTA,PIN_HIGH);
				MDIO_Error_State_SetPinValue(PIN1,MDIO_PORTA,PIN_LOW);
			}
		}
		/*change in T_on -->control motor Speed*/
		MTIMER0_VidSetCTCValue(speed);
		HCLCD_Vid4Bits_DisplayNumber(speed);
		_delay_ms(500);

		HCLCD_Vid4Bits_ClearScreen();


	}
	return 0 ;

}

/*INT0 --> motor speed Decrease*/
void __vector_1(void)      __attribute__((signal));
void __vector_1(void)
{
	if(speed>=0)
	{
		speed-=10;
	}

}

/*INT1  --> motor speed increase*/
void __vector_2(void)       __attribute__((signal));
void __vector_2(void)
{
	if(speed<255)
	{
		speed+=10 ;
	}

}
