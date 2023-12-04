/*
 * I2C_CONFIG.h
 *
 * Created: 11/27/2023 10:31:20 PM
 *  Author: khaled waleed
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_


#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"



#define TWI_DATA_RX_ACK					0
#define TWI_DATA_RX_NACK				1


#define TWI_START_COND_ACK						0x08
#define TWI_REP_START_COND_ACK					0x10
#define TWI_SLA_WRITE_ACK						0x18
#define TWI_SLA_READ_ACK						0x40
#define TWI_MASTER_DATA_TX_ACK					0x28
#define TWI_MASTER_DATA_RX_ACK					0x50
#define TWI_MASTER_DATA_RX_NACK					0x58


/* TWCR Register */
#define TWIE				0
#define TWEN				2
#define TWWC				3
#define TWSTO				4
#define TWSTA				5
#define TWEA				6
#define TWINT				7

/* TWSR Register */
#define TWPS0				0
#define TWPS1				1

#define TWI_STATUS_VALUE						(TWSR & 0xF8)





#endif /* I2C_CONFIG_H_ */