/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task2****************************/
/*Write a C code that apply 8 different animations on 8 LED string based on the
value of 3 way DIP Switch as following:


DIP value LED Action
1 	Flashing every 500 ms
2 	Shifting Left every 150 ms
3 	Shifting Right every 150 ms
4 	2-LEDs Converging every 250 ms
5 	2-LEDs Diverging every 250 ms
6 	Ping Pong effect every 250 ms
7 	Incrementing (Snake effect) every 250 ms
8 	2-LEDs Converging/Diverging every 250 ms
9   Display DIP Number on Seven Segment
 */

#define F_CPU  8000000UL

#include"../LIB/LSTD_TYPES.h"
#include"../LIB/LBIT_MATH.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../HAL/HSWITCH/HSWITCH_Interface.h"
#include"../HAL/HSEVEN_SEGMENT/HSEVEN_SEGMENT_Interface.h"

#include<util\delay.h>

/*Application define*/
#define switch1    1
#define switch2    2
#define switch3    3
#define switch4    4
#define switch5    5
#define switch6    6
#define switch7    7
#define switch8    8


/*Define 8 LEDs from PA0--->PA7*/
LED_t LED1 = {HLED_PORTA,PIN0};
LED_t LED2 = {HLED_PORTA,PIN1};
LED_t LED3 = {HLED_PORTA,PIN2};
LED_t LED4 = {HLED_PORTA,PIN3};
LED_t LED5 = {HLED_PORTA,PIN4};
LED_t LED6 = {HLED_PORTA,PIN5};
LED_t LED7 = {HLED_PORTA,PIN6};
LED_t LED8 = {HLED_PORTA,PIN7};

/*Define  Seven Segment*/

SEVEN_SEGMENT_t SEVEN_SEG1={HSEVEN_SEGMENT_PORTB,COMMON_CATHODE};

/*Define Switch*/
SWITCH_t Switch_1 ={HSWITCH_PORTC,PIN0} ;
SWITCH_t Switch_2 ={HSWITCH_PORTC,PIN1} ;
SWITCH_t Switch_3 ={HSWITCH_PORTC,PIN2} ;
SWITCH_t Switch_4 ={HSWITCH_PORTC,PIN3} ;
SWITCH_t Switch_5 ={HSWITCH_PORTC,PIN4} ;
SWITCH_t Switch_6 ={HSWITCH_PORTC,PIN5} ;
SWITCH_t Switch_7 ={HSWITCH_PORTC,PIN6} ;
SWITCH_t Switch_8 ={HSWITCH_PORTC,PIN7} ;

void APP_VidLED_Mode(u8 Copy_u8SwitchNumber);


int main(void)
{
	/*Initialize  8 LEDs*/
	HLED_VidInit(&LED1);
	HLED_VidInit(&LED2);
	HLED_VidInit(&LED3);
	HLED_VidInit(&LED4);
	HLED_VidInit(&LED5);
	HLED_VidInit(&LED6);
	HLED_VidInit(&LED7);
	HLED_VidInit(&LED8);
	/*Initialize Seven Segment*/
	HSEVEN_SEGMENT_VidInit(&SEVEN_SEG1);
	/*Initialize 8 Switches interface as Pull resistance */
	HSWITCH_VidInit_PullUP(&Switch_1);
	HSWITCH_VidInit_PullUP(&Switch_2);
	HSWITCH_VidInit_PullUP(&Switch_3);
	HSWITCH_VidInit_PullUP(&Switch_4);
	HSWITCH_VidInit_PullUP(&Switch_5);
	HSWITCH_VidInit_PullUP(&Switch_6);
	HSWITCH_VidInit_PullUP(&Switch_7);
	HSWITCH_VidInit_PullUP(&Switch_8);
	while(1)
	{
		if(PRESSED == HSWITCH_u8SwitchState(&Switch_1))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_1))
			{
				/*1- Flashing every 500 ms */
				APP_VidLED_Mode(switch1);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else if(PRESSED == HSWITCH_u8SwitchState(&Switch_2))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_2))
			{
				/*2- Shifting Left every 150 ms*/
				APP_VidLED_Mode(switch2);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else if(PRESSED == HSWITCH_u8SwitchState(&Switch_3))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_3))
			{
				/*3- Shifting Right every 150 ms*/

				APP_VidLED_Mode(switch3);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else if(PRESSED == HSWITCH_u8SwitchState(&Switch_4))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_4))
			{
		    	/*4- 2-LEDs Converging every 250 ms*/
				APP_VidLED_Mode(switch4);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else if(PRESSED == HSWITCH_u8SwitchState(&Switch_5))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_5))
			{
				/*5- 2-LEDs Diverging every 250 ms*/
				APP_VidLED_Mode(switch5);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else if(PRESSED == HSWITCH_u8SwitchState(&Switch_6))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_6))
			{
				/*6- Ping Pong effect every 250 ms*/
				APP_VidLED_Mode(switch6);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else if(PRESSED == HSWITCH_u8SwitchState(&Switch_7))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_7))
			{
				/*7- Incrementing (Snake effect) every 250 ms*/
				APP_VidLED_Mode(switch7);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else if(PRESSED == HSWITCH_u8SwitchState(&Switch_8))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_8))
			{
				/*8-	2-LEDs Converging/Diverging every 250 ms*/
				APP_VidLED_Mode(switch8);
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else
		{
			/*Do Nothing*/
		}
	}
	return 0 ;
}

void APP_VidLED_Mode(u8 Copy_u8SwitchNumber)
{

	switch(Copy_u8SwitchNumber)
	{
	/*1- Flashing every 500 ms */
	case switch1 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch1);
		HLED_VidLed_On(&LED1);
		HLED_VidLed_On(&LED2);
		HLED_VidLed_On(&LED3);
		HLED_VidLed_On(&LED4);
		HLED_VidLed_On(&LED5);
		HLED_VidLed_On(&LED6);
		HLED_VidLed_On(&LED7);
		HLED_VidLed_On(&LED8);
		_delay_ms(500);
		HLED_VidLed_Off(&LED1);
		HLED_VidLed_Off(&LED2);
		HLED_VidLed_Off(&LED3);
		HLED_VidLed_Off(&LED4);
		HLED_VidLed_Off(&LED5);
		HLED_VidLed_Off(&LED6);
		HLED_VidLed_Off(&LED7);
		HLED_VidLed_Off(&LED8);
		_delay_ms(500);
		break ;

	/*2- Shifting Right every 150 ms*/
	case switch2 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch2);
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);

		for(u8 i =0 ; i<8 ;i++)
		{
			MDIO_Error_State_SetPortValue(HLED_PORTA,0);
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			_delay_ms(150);
		}
		break  ;
		/*3- Shifting Left every 150 ms*/
	case switch3 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch3);
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);
		for(u8 i =0 ; i<8 ;i++)
		{
			MDIO_Error_State_SetPortValue(HLED_PORTA,0);
			MDIO_Error_State_SetPinValue((7-i),HLED_PORTA,PIN_HIGH);
			_delay_ms(150);

		}
		break  ;
		/*4- 2-LEDs Converging every 250 ms*/
	case switch4 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch4);
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);
		for(s8 i =7 ; i>=4 ;i--)
		{
			MDIO_Error_State_SetPortValue(HLED_PORTA,0);
			MDIO_Error_State_SetPinValue((7-i),HLED_PORTA,PIN_HIGH);
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			_delay_ms(250);
		}
		break  ;
		/*5- 2-LEDs Diverging every 250 ms*/
	case switch5 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch5);
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);
		for(s8 i =3 ; i>= 0 ;i--)
		{
			MDIO_Error_State_SetPortValue(HLED_PORTA,0);
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			MDIO_Error_State_SetPinValue((7-i),HLED_PORTA,PIN_HIGH);
			_delay_ms(250);
		}
		break  ;
		/*6- Incrementing (Snake effect) every 250 ms*/
	case switch6 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch6);
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);
		for(u8 i = 0 ; i<8 ;i++)
		{
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			_delay_ms(250);
		}
		break  ;
		/*7- Ping Pong effect every 250 ms*/

	case switch7 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch7);
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);
		for(u8 i = 0 ; i<8 ;i++)
		{
			MDIO_Error_State_SetPortValue(HLED_PORTA,0);
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			_delay_ms(250);
		}
		for(s8 i =7 ; i>=0 ;i--)
		{
			MDIO_Error_State_SetPortValue(HLED_PORTA,0);
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			_delay_ms(250);
		}
		break  ;
		/*8-	2-LEDs Converging/Diverging every 250 ms*/
	case switch8 :
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch8);
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);
		for(u8 i =0 ; i<8 ;i++)
		{
			MDIO_Error_State_SetPortValue(HLED_PORTA,0);
			MDIO_Error_State_SetPinValue((7-i),HLED_PORTA,PIN_HIGH);
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			_delay_ms(250);
		}
		break  ;
	default :
		break ;
		/*Do Nothing*/
	}
}
