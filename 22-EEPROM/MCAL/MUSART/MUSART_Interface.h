/*
 * MUSART_Interface.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MUSART_MUSART_INTERFACE_H_
#define MCAL_MUSART_MUSART_INTERFACE_H_

/*USART Initialization*/
void MUSART_VidInit(void);
/*USART Send Data*/
void MUSART_VidSendChar(u8 Copy_u8Data);
/*USART Receive Data*/
u8 MUSART_VidReceiveData(void);
/*USART Send String*/
void MUSART_VidSendString(u8 *Copy_u8Data);
/*USART Receive String*/
void MUSART_VidReceiveString(u8 *Copy_u8Data);
#endif /* MCAL_MUSART_MUSART_INTERFACE_H_ */
