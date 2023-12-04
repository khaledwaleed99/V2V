/*
 * DIO_IMPELEMENTATION.c
 *
 * Created: 11/27/2023 7:58:45 PM
 *  Author: khaled waleed
 */ 


#include "DIO_PROTOTYPES.h"


void  DIO_SET_PORT_DIREC  (DIO_PORT_ID PORT , DIO_DIRECTION DIREC)
{
	if(DIREC == DIO_OUTPUT)
	{
		switch(PORT)
		{
			case DIO_PORTA:
			
			DDRA = 0xFF;
			
			break;
			
			case DIO_PORTB:
			
			DDRB = 0xFF;
			
			break;
			
			case DIO_PORTC:
			
			DDRC = 0xFF;
			
			break;
			
			case DIO_PORTD:
			
			DDRD = 0xFF;
			
			break;
			
			
			case DIO_PORTE:
			
			DDRE = 0xFF;
			
			break;
			
			case DIO_PORTF:
			
			DDRF = 0xFF;
			
			break;
			
			case DIO_PORTG:
			
			DDRG = 0xFF;
			
			break;
			default:
			break;
			
		}
	}
	if(DIREC == DIO_INPUT)
	{
		switch(PORT)
		{
			case DIO_PORTA:
			
			DDRA = 0x00;
			
			break;
			
			case DIO_PORTB:
			
			DDRB = 0x00;
			
			break;
			
			case DIO_PORTC:
			
			DDRC = 0x00;
			
			break;
			
			case DIO_PORTD:
			
			DDRD = 0x00;
			
			break;
			
			
			case DIO_PORTE:
			
			DDRE = 0x00;
			
			break;
			
			case DIO_PORTF:
			
			DDRF = 0x00;
			
			break;
			
			case DIO_PORTG:
			
			DDRG = 0x00;
			
			break;
			default:
			break;
			
		}
	}
}


void  DIO_SET_PIN_DIREC   (DIO_PORT_ID PORT , DIO_PIN_ID PIN , DIO_DIRECTION DIREC)
{
	switch( DIREC )
	{
		case DIO_OUTPUT:
		switch (PORT)
		{
			case DIO_PORTA:
			
			SET_BIT (DDRA,PIN);
			
			break;
			
			case DIO_PORTB:
			
			SET_BIT(DDRB,PIN);
			
			break;
			
			case DIO_PORTC:
			
			SET_BIT(DDRC,PIN);
			
			break;
			
			case DIO_PORTD:
			
			SET_BIT(DDRD,PIN);
			
			break;
			case DIO_PORTE:
			
			SET_BIT(DDRE,PIN);
			
			break;
			case DIO_PORTF:
			
			SET_BIT(DDRF,PIN);
			
			break;
			case DIO_PORTG:
			
			SET_BIT(DDRG,PIN);
			
			break;
			default:
			break;
		}
		
		break;
		
		case DIO_INPUT:
		
		switch(PORT)
		
		{
			case DIO_PORTA:
			
			CLR_BIT(DDRA,PIN);
			
			break;
			
			case DIO_PORTB:
			
			CLR_BIT(DDRB,PIN);
			
			break;
			
			case DIO_PORTC:
			
			CLR_BIT(DDRC,PIN);
			
			break;
			
			case DIO_PORTD:
			
			CLR_BIT(DDRD,PIN);
			
			break;
			case DIO_PORTE:
			
			CLR_BIT(DDRE,PIN);
			
			break;
			case DIO_PORTF:
			
			CLR_BIT(DDRF,PIN);
			
			break;
			case DIO_PORTG:
			
			CLR_BIT(DDRG,PIN);
			
			break;
			
			default:
			break;
		}
		
		break;
		
		
		default:
		break;
		
	}
}

void DIO_SET_PORT_VALUE   (DIO_PORT_ID PORT , uint8 VALUE )
{
	switch(PORT)
	{
		case DIO_PORTA:
		
		PORTA = VALUE;
		
		break;
		
		case DIO_PORTB:
		
		PORTB = VALUE;
		
		break;
		
		case DIO_PORTC:
		
		PORTC = VALUE;
		
		break;
		
		case DIO_PORTD:
		
		PORTD = VALUE;
		
		break;
		case DIO_PORTE:
		
		PORTE = VALUE;
		
		break;
		case DIO_PORTF:
		
		PORTF = VALUE;
		
		break;
		case DIO_PORTG:
		
		PORTG = VALUE;
		
		break;
		
		default:
		break;
	}
}

void DIO_SET_PIN_VALUE    (DIO_PORT_ID PORT , DIO_PIN_ID PIN , DIO_VALUE VALUE )
{
	switch( VALUE )
	{
		case DIO_HIGH:
		
		switch (PORT)
		{
			case DIO_PORTA:
			
			SET_BIT (PORTA,PIN);
			
			break;
			
			case DIO_PORTB:
			
			SET_BIT(PORTB,PIN);
			
			break;
			
			case DIO_PORTC:
			
			SET_BIT(PORTC,PIN);
			
			break;
			
			case DIO_PORTD:
			
			SET_BIT(PORTD,PIN);
			
			break;
			
			case DIO_PORTE:
			
			SET_BIT(PORTE,PIN);
			
			break;
			
			case DIO_PORTF:
			
			SET_BIT(PORTF,PIN);
			
			break;
			
			case DIO_PORTG:
			
			SET_BIT(PORTG,PIN);
			
			break;
			default:
			break;
		}
		
		break;
		
		case DIO_LOW:
		
		switch(PORT)
		
		{
			case DIO_PORTA:
			
			CLR_BIT (PORTA,PIN);
			
			break;
			
			case DIO_PORTB:
			
			CLR_BIT(PORTB,PIN);
			
			break;
			
			case DIO_PORTC:
			
			CLR_BIT(PORTC,PIN);
			
			break;
			
			case DIO_PORTD:
			
			CLR_BIT(PORTD,PIN);
			
			
			break;
			
			default:
			break;
			
			
		}
	}
}


void DIO_READ_PORT       (DIO_PORT_ID PORT , uint8*VALUE )
{
	switch(PORT)
	{
		case DIO_PORTA:
		
		*VALUE = PINA;
		
		break;
		
		case DIO_PORTB:
		
		*VALUE = PINB;
		
		break;
		
		case DIO_PORTC:
		
		*VALUE = PINC;
		
		break;
		
		case DIO_PORTD:
		
		*VALUE = PIND;
		
		break;
		
		case DIO_PORTE:
		
		*VALUE = PINE;
		
		break;
		
		case DIO_PORTF:
		
		*VALUE = PINF;
		
		break;
		
		case DIO_PORTG:
		
		*VALUE = PING;
		
		break;
		
		default:
		break;
	}
}


void DIO_READ_PIN        (DIO_PORT_ID PORT , DIO_PIN_ID PIN , uint8*VALUE )
{
	switch(PORT)
	{
		case DIO_PORTA:
		
		*VALUE = GET_BIT(PINA,PIN);
		
		break;
		
		case DIO_PORTB:
		
		*VALUE = GET_BIT(PINB,PIN);
		
		break;
		
		case DIO_PORTC:
		
		*VALUE = GET_BIT(PINC,PIN);
		
		break;
		
		case DIO_PORTD:
		
		*VALUE = GET_BIT(PIND,PIN);
		
		break;
		
		case DIO_PORTE:
		
		*VALUE = GET_BIT(PINE,PIN);
		
		break;
		
		case DIO_PORTF:
		
		*VALUE = GET_BIT(PINF,PIN);
		
		break;
		
		case DIO_PORTG:
		
		*VALUE = GET_BIT(PING,PIN);
		
		break;
		
		default:
		break;
	}
}

void DIO_TOOGLE_PIN (DIO_PORT_ID PORT ,DIO_PIN_ID PIN)
{
	switch (PORT)
	{
		
		case DIO_PORTA:
		
		TOGGLE_BIT (PORTA , PIN);
		
		break;
		
		case DIO_PORTB:
		
		TOGGLE_BIT (PORTB , PIN);
		
		break;
		
		case DIO_PORTC:
		
		TOGGLE_BIT (PORTC ,PIN);
		
		break;
		
		case DIO_PORTD:
		
		TOGGLE_BIT (PORTD , PIN);
		
		break;
		
		case DIO_PORTE:
		
		TOGGLE_BIT (PORTE , PIN);
		
		break;
		
		case DIO_PORTF:
		
		TOGGLE_BIT (PORTF , PIN);
		
		break;
		
		case DIO_PORTG:
		
		TOGGLE_BIT (PORTG , PIN);
		
		break;
		
		default:
		break;
	}
}


