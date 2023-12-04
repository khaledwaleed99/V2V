/*
 * DIO_CONFIG.h
 *
 * Created: 11/27/2023 7:57:44 PM
 *  Author: khaled waleed
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"

// STATING BOTH THE PORTS & PINS

typedef enum
{
	DIO_PORTA ,
	DIO_PORTB ,
	DIO_PORTC ,
	DIO_PORTD ,
	DIO_PORTE ,
	DIO_PORTF ,
	DIO_PORTG
}DIO_PORT_ID;

typedef enum
{
	DIO_PIN0 ,
	DIO_PIN1 ,
	DIO_PIN2 ,
	DIO_PIN3 ,
	DIO_PIN4 ,
	DIO_PIN5 ,
	DIO_PIN6 ,
	DIO_PIN7
}DIO_PIN_ID;


// DIRECTION FOR THE PINS


typedef enum
{
	DIO_INPUT ,
	DIO_OUTPUT
}DIO_DIRECTION;


// DIRECTION FOR THE PORTS

typedef enum
{
	
	 DIO_PORT_INPUT   =    0x00,
     DIO_PORT_OUTPUT  =    0XFF
	
}DIO_PORT_DIRECTION;


// VALUE OF THE VOLTAGE FOR A PIN ( 5 OR 0 )
typedef enum
{
	DIO_LOW ,
	DIO_HIGH
	
}DIO_VALUE;


// VALUE FOR THE VOLATGE FOR A PORT ( 5 OR 0 )

typedef enum
{
	DIO_PORT_HIGH    = 0xFF,
	DIO_PORT_LOW     = 0x00
}DIO_PORT_VALUES;






#endif /* DIO_CONFIG_H_ */