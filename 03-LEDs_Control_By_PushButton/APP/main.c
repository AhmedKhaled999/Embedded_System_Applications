/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task3****************************/
/*Write a C code that Control Three LEDs by one PushButton Switch without use Interrupt:
1- Toggle Blue  LED for first  pressed
2- Toggle Red   LED for second pressed
3- Toggle Green LED for Third  pressed
 */


#include"../LIB/LSTD_TYPES.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../HAL/HSWITCH/HSWITCH_Interface.h"
#define F_CPU  8000000UL
#include<util\delay.h>

/*Application define*/

#define LED1     1
#define LED2     2
#define LED3     3

/*Define 8 LEDs from PA0--->PA7*/
LED_t B_LED1 = {HLED_PORTA,PIN0};
LED_t R_LED2 = {HLED_PORTA,PIN1};
LED_t G_LED3 = {HLED_PORTA,PIN2};

/*Define Switch*/
SWITCH_t Switch_1 ={HSWITCH_PORTB,PIN7} ;

void APP_Delay_ms(u16 Copy_u16Delay_ms)
{

	u64 i  ;
	/*look at this code in Assembly and you detect That it takes 8 instructions in assembly and each instruction take 1 clock cycle
	 * so for one iteration we need 1*8 = 8 clock cycles , Fcpu = 8MHz so, tick time = 1/8MHz = 0.125 micro sec , one iteration take 8*0.125 =1 micro sec
	 * 1ms--->1000 iterations */
	for(i= (Copy_u16Delay_ms * 1000); i > 0 ; i--)
	{
		/*Do Nothing*/
	}
}
void APP_LED(u8 Copy_u8LEDNumber)
{
	static u8 Flag1 = 0 ;
	static u8 Flag2 = 0 ;
	static u8 Flag3 = 0 ;

	switch(Copy_u8LEDNumber)
	{
	case 1:
		if(Flag1 == 0)
		{
			HLED_VidLed_On(&B_LED1);
			Flag1 = 1;
		}
		else if(Flag1==1)
		{
			HLED_VidLed_Off(&B_LED1);
			Flag1 = 0;
		}
		else
		{
			/*Do Nothing*/
		}
		break ;
	case 2:
		if(Flag2 == 0)
		{
			HLED_VidLed_On(&R_LED2);
			Flag2 = 1;
		}
		else if(Flag2==1)
		{
			HLED_VidLed_Off(&R_LED2);
			Flag2 = 0;
		}
		else
		{
			/*Do Nothing*/
		}
		break ;
	case 3:
		if(Flag3 == 0)
		{
			HLED_VidLed_On(&G_LED3);
			Flag3 = 1;
		}
		else if(Flag3==1)
		{
			HLED_VidLed_Off(&G_LED3);
			Flag3 = 0;
		}
		else
		{
			/*Do Nothing*/
		}
		break ;
	default:
		/*Do Nothing*/
		break ;
	}
}

int main(void)
{

	static u8 Count  = 0 ;
	/*Initialize LEDs Positive Logic */
	HLED_VidInit(&B_LED1);
	HLED_VidInit(&R_LED2);
	HLED_VidInit(&G_LED3);
	/*Initialize Switch interface as Pull resistance */
	HSWITCH_VidInit_PullUP(&Switch_1);
	while(1)
	{
		if(PRESSED==HSWITCH_u8SwitchState(&Switch_1))
		{
			/*to Slove De-Bouncing Problem wait few ms*/
			_delay_ms(50);
			/*Check again on Switch state*/
			if(PRESSED==HSWITCH_u8SwitchState(&Switch_1))
			{
				/*for first pressed*/
				Count++;
				if(Count==1)
				{
					_delay_ms(250);
					if(PRESSED==HSWITCH_u8SwitchState(&Switch_1))
					{
						/*for second pressed*/
						Count++;
						if(Count==2)
						{
							_delay_ms(200);
							if(PRESSED==HSWITCH_u8SwitchState(&Switch_1))
							{
								/*for Third pressed*/
								Count++;
								if(Count==3)
								{
									APP_LED(LED3);
									Count = 0 ;
									_delay_ms(100);
									continue ;
								}
								else
								{
									/*Do NoThing*/
								}
							}
							else if(NOT_PRESSED==HSWITCH_u8SwitchState(&Switch_1))
							{
								APP_LED(LED2);
								Count = 0 ;
								continue ;
							}
							else
							{
								/*Do Nothing*/
							}
						}
					}
					else if(NOT_PRESSED==HSWITCH_u8SwitchState(&Switch_1))
					{
						APP_LED(LED1);
						Count = 0 ;
						continue ;
					}

				}// increment count for frist pressed
			}//check the signal if stable or not
		}//just input signal
	}//While
	return 0 ;
}
