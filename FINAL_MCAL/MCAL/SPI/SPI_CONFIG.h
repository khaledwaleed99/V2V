/*
 * SPI_CONFIG.h
 *
 * Created: 11/27/2023 10:02:39 PM
 *  Author: khaled waleed
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"


#define SPI_MASTER            0
#define SPI_SLAVE             1


#define SPI_PRE_SCALLER_2     0
#define SPI_PRE_SCALLER_4     1
#define SPI_PRE_SCALLER_8     2
#define SPI_PRE_SCALLER_16    3
#define SPI_PRE_SCALLER_32    4
#define SPI_PRE_SCALLER_64    5
#define SPI_PRE_SCALLER_128   6


#define SPI_INTERRUPT_ON          1
#define SPI_INTERRUPT_OFF         0

#define SPI_POLLING_ON            1
#define SPI_POLLING_OFF           0


// PINS LAYOUT

#define SPI_PORT             DIO_PORTB

#define SPI_MOSI_PIN         DIO_PIN2
#define SPI_MISO_PIN         DIO_PIN3
#define SPI_SS_PIN           DIO_PIN0
#define SPI_CLK_PIN          DIO_PIN1

// REG NEEDED BITS 

#define SPIE  DIO_PIN7
#define SPE	  DIO_PIN6
#define DORD  DIO_PIN5
#define MSTR  DIO_PIN4
#define CPOL  DIO_PIN3
#define CPHA  DIO_PIN2
#define SPR1  DIO_PIN1
#define SPR0  DIO_PIN0

#define SPIF  DIO_PIN7



// THE POLARITY & THE PHASE WERE KEPT AS DEFULT


#define SPI_STATE_OF_OPERATION    SPI_MASTER
#define SPI_PRE_SCALLER_VALUE     SPI_PRE_SCALLER_128
#define SPI_INTERRUPT_STATE       SPI_INTERRUPT_ON
#define SPI_POLLING_STATE         SPI_POLLING_OFF



#endif /* SPI_CONFIG_H_ */