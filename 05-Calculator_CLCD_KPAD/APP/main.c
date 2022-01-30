/*
 * main.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*******************************Task5****************************/
/*

 */

#define F_CPU  8000000UL

#include"../LIB/LSTD_TYPES.h"
#include"../LIB/LBIT_MATH.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HLED/HLED_Interface.h"
#include"../HAL/HSWITCH/HSWITCH_Interface.h"
#include"../HAL/HSEVEN_SEGMENT/HSEVEN_SEGMENT_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"
#include"../HAL/HKPD/HKPD_Interface.h"
#include"Conversion.h"

#include<util\delay.h>


void calculate(s8 num1[], s8 num2[], s8 operator);



int main(void)
{

	u8 Symbole=0 ,flag=1;
	HKPD_VidInit();
	HCLCD_Vid4Bits_Init();
	HCLCD_Vid4Bits_ClearScreen();
	while(1)
	{
		s8 num1[7], num2[7], operator=0;
		u8 i=0;
		Symbole =HKPD_U8GetKeyPressed();
		if ((flag==0)&&(Symbole=='O'))
		{
			flag=1;
			HCLCD_Vid4Bits_ClearScreen();
			HCLCD_Vid4Bits_SetPosition(1,2);
			HCLCD_Vid4Bits_DisplayString("WELCOME TO");

			HCLCD_Vid4Bits_SetPosition(2,3);
			HCLCD_Vid4Bits_DisplayString("CALCULATOR");//press OFF then ON
			_delay_ms(1000);
			HCLCD_Vid4Bits_ClearScreen();
		}
		else if((flag==1)&&(Symbole=='O'))
		{
			flag=0;
			HCLCD_Vid4Bits_ClearScreen();
			HCLCD_Vid4Bits_SetPosition(1,4);
			HCLCD_Vid4Bits_DisplayString("GOOD BAY");
			HCLCD_Vid4Bits_SetPosition(2,3);
			HCLCD_Vid4Bits_DisplayString("CALCULATOR"); //press OFF then ON
			_delay_ms(1000);
			HCLCD_Vid4Bits_ClearScreen();
		}
		else
		{
			/*something wrong*/
			num1[i] = Symbole;

					HCLCD_Vid4Bits_DisplayCharacter(num1[i]);
					i++;
					while(1){


						num1[i] = HKPD_U8GetKeyPressed();
						HCLCD_Vid4Bits_DisplayCharacter(num1[i]);

						if(num1[i] == '+')
						{
							operator = '+';
							num1[i] = '\0';
							break;
						}
						else if(num1[i] == '-')
						{
							operator = '-';
							num1[i] = '\0';
							break;
						}
						else if(num1[i] == '/')
						{
							operator = '/';
							num1[i] = '\0';
							break;
						}
						else if(num1[i] == '*')
						{
							operator = '*';
							num1[i] = '\0';
							break;
						}
						else if(num1[i] == 'O')
						{
							break;
						}
						i++;
					}

					i = 0;

					num2[i] = HKPD_U8GetKeyPressed();
					HCLCD_Vid4Bits_DisplayCharacter(num2[i]);
					i++;
					while(1){
						num2[i] = HKPD_U8GetKeyPressed();
						HCLCD_Vid4Bits_DisplayCharacter(num2[i]);
						if(num2[i] == '='){
							num2[i] = '\0';
							break;
						}else if(num2[i] == 'O')
						{
							break;
						}


						i++;
					}
					calculate(num1,num2,operator);
		}

	}
	return 0 ;
}

/*************************************************************************Calculation function***********************************/
void calculate(s8 num1[], s8 num2[], s8 operator)
{
	s32  operand1, operand2, result=0;
	s8 buffer[10];

	operand1 = convert_To_Int(num1);
	operand2 = convert_To_Int(num2);

	switch(operator)
	{
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '/':
		result = operand1 / operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	}

	convert_To_String(buffer,result);
	HCLCD_Vid4Bits_SetPosition(2,2);
	HCLCD_Vid4Bits_DisplayString(buffer);
}

