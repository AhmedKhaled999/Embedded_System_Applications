/*
 * MSPI_Private.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MSPI_MSPI_PRIVATE_H_
#define MCAL_MSPI_MSPI_PRIVATE_H_

#define SPCR     *((volatile u8*)0x2D)
#define SPSR     *((volatile u8*)0x2E)
#define SPDR     *((volatile u8*)0x2F)


#define MSPI_DATA_ORDERED_LSB    1
#define MSPI_DATA_ORDERED_MSB    0


#define MSPI_CPOL_LEADING_RISING     1
#define MSPI_CPOL_LEADING_FALLING    2


#define MSPI_CPHA_LEADING_SAMPLE     1
#define MSPI_CPHA_LEADING_SETUP      2

#define MSPI_NO_DOUBLE_SPEED         0
#define MSPI_DOUBLE_SPEED            1

#define MSPI_CLOCK_RATE_4            0
#define MSPI_CLOCK_RATE_16           1
#define MSPI_CLOCK_RATE_64           2
#define MSPI_CLOCK_RATE_128          3

#define MSPI_SPI_INTERRUPT_ENABLE       1
#define MSPI_SPI_INTERRUPT_DISABLE      0

#define MSPI_BIT_MASKING  0xFC



#endif /* MCAL_MSPI_MSPI_PRIVATE_H_ */
