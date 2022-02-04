/*
 * MUSART_Private.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MUSART_MUSART_PRIVATE_H_
#define MCAL_MUSART_MUSART_PRIVATE_H_

#define UDR     *((volatile u8*)0x2C)
#define UCSRA   *((volatile u8*)0x2B)
#define UCSRB   *((volatile u8*)0x2A)
#define UCSRC   *((volatile u8*)0x40)
#define UBRRL   *((volatile u8*)0x29)
#define UBRRH   *((volatile u8*)0x40)


/*USART Mode Options:*/
#define  USART_ASYNCHRONOUS_MODE     0
#define  USART_SYNCHRONOUS_MODE      1

/*USART Parity Mode Options:*/
#define USART_DISABLED_PARITY        0
#define USART_EVEN_PARITY            1
#define USART_ODD_PARITY             2

/*USART Stop Bit Options:*/
#define USART_STOP_ONE_BIT           1
#define USART_STOP_TWO_BIT           2

/*USART CHR Size Options:*/
#define USART_CHR_SIZE_5             5
#define USART_CHR_SIZE_6 			 6
#define USART_CHR_SIZE_7             7
#define USART_CHR_SIZE_8             8
#define USART_CHR_SIZE_9             9


#endif /* MCAL_MUSART_MUSART_PRIVATE_H_ */
