/*
 * MUSART_Config.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MUSART_MUSART_CONFIG_H_
#define MCAL_MUSART_MUSART_CONFIG_H_


/*USART Mode Options:
 * 1- USART_ASYNCHRONOUS_MODE
 * 2- USART_SYNCHRONOUS_MODE*/

#define USART_SET_MODE  USART_ASYNCHRONOUS_MODE


/*USART Parity Mode Options:
 * 1- USART_DISABLED_PARITY
 * 2- USART_EVEN_PARITY
 * 3- USART_ODD_PARITY */

#define USART_SET_PARITY_MODE  USART_DISABLED_PARITY


/*USART Stop Bit Options:
 * 1- USART_STOP_ONE_BIT
 * 2- USART_STOP_TWO_BIT */
#define  USART_SET_STOP_BIT  USART_STOP_ONE_BIT

/*USART CHR Size Options:
 * 1- USART_CHR_SIZE_5
 * 2- USART_CHR_SIZE_6
 * 3- USART_CHR_SIZE_7
 * 4- USART_CHR_SIZE_8
 * 5- USART_CHR_SIZE_9 */

#define USART_SET_CHR_SIZE  USART_CHR_SIZE_8

#endif /* MCAL_MUSART_MUSART_CONFIG_H_ */
