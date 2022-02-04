/*
 * MTWI_Private.h
 *
 *  Created on: Feb 3, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MTWI_MTWI_PRIVATE_H_
#define MCAL_MTWI_MTWI_PRIVATE_H_


#define TWBR     *((volatile u8*)0x20)
#define TWCR     *((volatile u8*)0x56)
#define TWSR     *((volatile u8*)0x21)
#define TWDR     *((volatile u8*)0x23)
#define TWAR     *((volatile u8*)0x22)

#define START_ACK             0x08  // start has been sent
#define REP_START_ACK         0x10  // repeated start
#define SLAVE_ADD_AND_WR_ACK  0x18  // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define SLAVE_ADD_AND_RD_ACK  0x40  // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define MSTR_WR_BYTE_ACK      0x28  // Master transmit data and ACK has been received from Slave.
#define MSTR_RD_BYTE_ACK      0x50  // Master received data and send ACK to slave
#define MSTR_RD_BYTE_NACK     0x58  // Master received data but doesn't send ACK to slave

#endif /* MCAL_MTWI_MTWI_PRIVATE_H_ */
