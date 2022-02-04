/*
 * MSPI_Interface.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MSPI_MSPI_INTERFACE_H_
#define MCAL_MSPI_MSPI_INTERFACE_H_

/*SPI Master Initialization*/
void MSPI_VidMaster_Init(void);
/*SPI Slave Initialization*/
void MSPI_VidSlave_Init(void);
/*SPI Send and Receive Char*/
u8 MSPI_u8Send_Receive_Char(u8 Copy_u8Char);


void MSPI_u8Send_Char(u8 Copy_u8Char);

u8 MSPI_Receive_Char(void);

void MSPI_u8Send_String(const u8 *Str);


void MSPI_Receive_String(s8 *Str);

#endif /* MCAL_MSPI_MSPI_INTERFACE_H_ */
