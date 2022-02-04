/*
 * MUSART_Program.c
 *
 *  Created on: Jan 21, 2022
 *      Author: Ahmed Khaled Hammad
 */


#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"

#include"MUSART_Private.h"
#include"MUSART_Config.h"

//#include<util\delay.h>

/*USART Initialization*/
void MUSART_VidInit(void)
{
	u8 LOC_u8Copy_UCSRC = 0;
	/*1- Select USART Mode*/
#if USART_SET_MODE == USART_ASYNCHRONOUS_MODE
	CLR_BIT(LOC_u8Copy_UCSRC,6);
#elif USART_SET_MODE == USART_SYNCHRONOUS_MODE
	SET_BIT(LOC_u8Copy_UCSRC,6);
#else
#error "USART Mode Is not valid..."
#endif
	/*2- Select Parity Mode*/
#if USART_SET_PARITY_MODE == USART_DISABLED_PARITY
	CLR_BIT(LOC_u8Copy_UCSRC,4);
	CLR_BIT(LOC_u8Copy_UCSRC,5);
#elif USART_SET_PARITY_MODE == USART_EVEN_PARITY
	CLR_BIT(LOC_u8Copy_UCSRC,4);
	SET_BIT(LOC_u8Copy_UCSRC,5);
#elif USART_SET_PARITY_MODE == USART_ODD_PARITY
	SET_BIT(LOC_u8Copy_UCSRC,4);
	SET_BIT(LOC_u8Copy_UCSRC,5);
#else
#error "USART Parity Mode Is not valid..."
#endif
	/*3- Select USART Stop Bit Number */
#if USART_SET_STOP_BIT == USART_STOP_ONE_BIT
	CLR_BIT(LOC_u8Copy_UCSRC,3);
#elif USART_SET_STOP_BIT == USART_STOP_TWO_BIT
	SET_BIT(LOC_u8Copy_UCSRC,3);

#else
#error "USART Stop Bit Number Is not valid..."
#endif
	/*4- Select Char Size */
#if USART_SET_CHR_SIZE == USART_CHR_SIZE_5
	CLR_BIT(LOC_u8Copy_UCSRC,1);
	CLR_BIT(LOC_u8Copy_UCSRC,2);
	CLR_BIT(UCSRB,2);

#elif  USART_SET_CHR_SIZE == USART_CHR_SIZE_6
	SET_BIT(LOC_u8Copy_UCSRC,1);
	CLR_BIT(LOC_u8Copy_UCSRC,2);
	CLR_BIT(UCSRB,2);
#elif  USART_SET_CHR_SIZE == USART_CHR_SIZE_7
	CLR_BIT(LOC_u8Copy_UCSRC,1);
	SET_BIT(LOC_u8Copy_UCSRC,2);
	CLR_BIT(UCSRB,2);
#elif  USART_SET_CHR_SIZE == USART_CHR_SIZE_8
	SET_BIT(LOC_u8Copy_UCSRC,1);
	SET_BIT(LOC_u8Copy_UCSRC,2);
	CLR_BIT(UCSRB , 2);
#elif  USART_SET_CHR_SIZE == USART_CHR_SIZE_9
	SET_BIT(LOC_u8Copy_UCSRC,1);
	SET_BIT(LOC_u8Copy_UCSRC,2);
	SET_BIT(UCSRB,2);


#else
#error "USART CHR Size Is not valid..."
#endif
	/*Set LOC_u8Copy_UCSRC value in UCSRC Register
	 * and Select UCSRC Register */
	SET_BIT(LOC_u8Copy_UCSRC,7);
	UCSRC = LOC_u8Copy_UCSRC;
	/*Set BaudRate -->9600*/
	UBRRL = 103;
	/*Enable To TX and RX*/
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);
}

/*USART Send Data*/
void MUSART_VidSendChar(u8 Copy_u8Data)
{
	/*Wait until Register Empty Flag is set*/
	while(GET_BIT(UCSRA,5)==0);
	/**/
	UDR=Copy_u8Data;
}
/*USART Receive Data*/
u8 MUSART_VidReceiveData(void)
{
	/*Wait until Receive Complete Flag  is set*/
	while(GET_BIT(UCSRA,7)==0);
	return UDR;
}

/*USART Send String*/
void MUSART_VidSendString(u8 *Copy_u8Data)
{
	u8 LOC_u8CharCount= 0;
	while(Copy_u8Data[LOC_u8CharCount]!=NULL)
	{
		MUSART_VidSendChar(Copy_u8Data[LOC_u8CharCount]);
		/*Wait few ms to make anther node receive data */
		//_delay_ms(100);
		LOC_u8CharCount++;
	}
	MUSART_VidSendChar('\0');

}

/*USART Receive String*/
void MUSART_VidReceiveString(u8 *Copy_u8Data)
{
	u8 LOC_u8CharCount= 0;
	Copy_u8Data[LOC_u8CharCount]=MUSART_VidReceiveData();

	while(Copy_u8Data[LOC_u8CharCount]!=NULL)
	{
		LOC_u8CharCount++;
		Copy_u8Data[LOC_u8CharCount]=MUSART_VidReceiveData();
	}
	Copy_u8Data[LOC_u8CharCount] = '\0';
}
