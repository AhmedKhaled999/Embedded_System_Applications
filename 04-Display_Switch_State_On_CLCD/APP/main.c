/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task4****************************/
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
10  Display DIP Number on LCD
 */

#define F_CPU  8000000UL

#include"../LIB/LSTD_TYPES.h"
#include"../LIB/LBIT_MATH.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../HAL/HSWITCH/HSWITCH_Interface.h"
#include"../HAL/HSEVEN_SEGMENT/HSEVEN_SEGMENT_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"

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
	/*pattern for Ahmed in Arabic */
	//pattern for Alph character
	u8 pattern0[8]={0x06,0x04,0x0E,0x00,0x04,0x04,0x04,0x00};
	// pattern for 7a8
	u8 pattern1[8]={0x00,0x00,0x08,0x14,0x02,0x1F,0x00,0x00};
	// pattern for mem
	u8 pattern2[8]={0x00,0x00,0x00,0x00,0x02,0x1D,0x02,0x00};
	// pattern for dal
	u8 pattern3[8]={0x00,0x00,0x01,0x01,0x01,0x1F,0x00,0x00};

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
	/*Initialize LCD*/
	HCLCD_Vid4Bits_Init();

	/*Initialize patterns*/
	HCLCD_Vid4Bits_CustomAlphChar(0, pattern0);
	HCLCD_Vid4Bits_CustomAlphChar(1, pattern1);
	HCLCD_Vid4Bits_CustomAlphChar(2, pattern2);
	HCLCD_Vid4Bits_CustomAlphChar(3, pattern3);
	/***********************************************Display Welcome Massage on LCD ********************************************************/
	_delay_ms(10);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
	//LCD_VidGoToRowCol(0,4);
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE1,4);
	HCLCD_Vid4Bits_DisplayCharacter('W');
	HCLCD_Vid4Bits_DisplayCharacter('e');
	HCLCD_Vid4Bits_DisplayCharacter('l');
	HCLCD_Vid4Bits_DisplayCharacter('c');
	HCLCD_Vid4Bits_DisplayCharacter('o');
	HCLCD_Vid4Bits_DisplayCharacter('m');
	HCLCD_Vid4Bits_DisplayCharacter('e');
	_delay_ms(1000);
	HCLCD_Vid4Bits_DisplayShiftLeft(7);
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,5);
	HCLCD_Vid4Bits_DisplayCharacter('T');
	HCLCD_Vid4Bits_DisplayCharacter('A');
	HCLCD_Vid4Bits_DisplayCharacter('S');
	HCLCD_Vid4Bits_DisplayCharacter('K');
	HCLCD_Vid4Bits_DisplayCharacter(' ');
	HCLCD_Vid4Bits_DisplayCharacter('4');
	HCLCD_Vid4Bits_CursorShiftRight(2);
	HCLCD_Vid4Bits_DisplayCharacter('R');

	_delay_ms(1000);
	/*send most Nipple first*/

	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
	//HCLCD_Vid4Bits_SetPosition(HCLCD_LINE1,4);
	HCLCD_Vid4Bits_CursorShiftRight(4);
	HCLCD_Vid4Bits_DisplayString((u8*)"My Name is");
	_delay_ms(2000);

	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,2);

	u8 LOC_Name[] = "Khaled";
	HCLCD_Vid4Bits_DisplayString((u8*)"Ahmed");
	HCLCD_Vid4Bits_DisplayCharacter(' ');
	HCLCD_Vid4Bits_DisplayString(LOC_Name);
	_delay_ms(2000);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
	_delay_ms(2000);
	HCLCD_Vid4Bits_DisplayString((u8*)"My Phone is");
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,2);
	HCLCD_Vid4Bits_DisplayNumber(01105555555);
	_delay_ms(2000);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
	HCLCD_Vid4Bits_DisplayString((u8*)"My Name is");
	/*Print my name in Arabic*/
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,9);
	HCLCD_Vid4Bits_DisplayCharacter(0);
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,8);
	HCLCD_Vid4Bits_DisplayCharacter(1);
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,7);
	HCLCD_Vid4Bits_DisplayCharacter(2);
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
	HCLCD_Vid4Bits_DisplayCharacter(3);
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,5);
	_delay_ms(2000);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);

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


			HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,OFF);
			HCLCD_Vid4Bits_DisplayString((u8*)"No Switch is");
			HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
			HCLCD_Vid4Bits_DisplayString((u8*)"Pressed");
			_delay_ms(1000);
			HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
			HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
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
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch1);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [1]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
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
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch2);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [2]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
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
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch3);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [3]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
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
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch4);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [4]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
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
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch5);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [5]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
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
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch6);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [6]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
		MDIO_Error_State_SetPortValue(HLED_PORTA,0);
		for(u8 i = 0 ; i<8 ;i++)
		{
			MDIO_Error_State_SetPinValue(i,HLED_PORTA,PIN_HIGH);
			_delay_ms(250);
		}
		break  ;
		/*7- Ping Pong effect every 250 ms*/

	case switch7 :
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch7);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [7]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
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
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR>>4);
		HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
		HSEVEN_SEGMENT_VidDisplayNumber(&SEVEN_SEG1,switch8);
		HCLCD_Vid4Bits_DisplayString((u8*)"Switch No. [8]");
		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,6);
		HCLCD_Vid4Bits_DisplayString((u8*)"is Pressed");
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

