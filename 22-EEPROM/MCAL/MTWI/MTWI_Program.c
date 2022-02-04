/*
 * MTWI_Program.c
 *
 *  Created on: Feb 3, 2022
 *      Author: Ahmed Khaled Hammad
 */


#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\LIB\LBIT_MATH.h"
#include"MTWI_Private.h"
#include"MTWI_Config.h"
#include"MTWI_Interface.h"


void MTWI_VidInitMaster(void)
{
	/* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */

	TWBR = 0x02;
	TWSR = 0x00;

	/* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
	          General Call Recognition: Off */
	TWAR = 0b00000010; // my address = 0x01 :)

	TWCR = (1<<2); /* enable TWI */

}
void MTWI_SendStartCondition(void)
{
	/*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << 7) | (1 << 5) | (1 << 2);

	/* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	while(GET_BIT(TWCR,7)==0);
}
void MTWI_SendStopCondition(void)
{
	/*
		 * Clear the TWINT flag before sending the stop bit TWINT=1
		 * send the stop bit by TWSTO=1
		 * Enable TWI Module TWEN=1
		 * ----------------------------------------
		 *  Enable TWI Module TWEN=1 ---> //SET_BIT(TWCR,2);
	        Sent stop condition on the bus ---> //SET_BIT(TWCR,4);
	        Clear the interrupt flag To start the previous operation
	         //SET_BIT(TWCR,7);
		 */
		TWCR = (1 << 7) | (1 << 4) | (1 << 2);
}
void MTWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	/* Put data On TWI data Register */
	    TWDR = Copy_u8DataByte;
	    /*
		 * Clear the TWINT flag before sending the data TWINT=1
		 * Enable TWI Module TWEN=1
		 */
	    TWCR = (1 << 7) | (1 << 2);
	    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
		while(GET_BIT(TWCR,7)==0);
}
u8 MTWI_MasterReadDataByteWith_ACK(void)           //read with send Ack
{

	/*
		 * Clear the TWINT flag before reading the data TWINT=1
		 * Enable sending ACK after reading or receiving data TWEA=1
		 * Enable TWI Module TWEN=1
		 * --------------------------------------------
		 *     Enable Acknowledge bit --> //SET_BIT(TWCR,6);
		 *     Clear the interrupt flag To start the previous operation --> //SET_BIT(TWCR,7);
	     *     Enable TWI Module TWEN=1 -->//SET_BIT(TWCR,2);
		 */
	    TWCR = (1 << 7) | (1 << 2) | (1 << 6);
	    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
		while(GET_BIT(TWCR,7)==0);
	    /* Read Data */
	    return TWDR;



}
u8 MTWI_MasterReadDataByteWith_NACK(void)         //read without send Ack
{
	/*
		 * Clear the TWINT flag before reading the data TWINT=1
		 * Enable TWI Module TWEN=1
		 * -------------------------------------------
		 * 	 * Disable Acknowledge bit --> //CLR_BIT(TWCR,6);
		 *     Clear the interrupt flag To start the previous operation --> //SET_BIT(TWCR,7);
	     *     Enable TWI Module TWEN=1 -->//SET_BIT(TWCR,2);
		 */
	    TWCR = (1 << 7) | (1 << 2);
	    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
		while(GET_BIT(TWCR,7)==0);
	    /* Read Data */
	    return TWDR;

}

u8 MTWI_MASTERGetStatus(void)
{
	 u8 status;
	    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	    status = TWSR & 0xF8;
	    return status;

}

