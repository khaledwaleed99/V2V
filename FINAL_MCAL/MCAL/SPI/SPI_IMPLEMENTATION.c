/*
 * SPI_IMPLEMENTATION.c
 *
 * Created: 11/27/2023 10:00:07 PM
 *  Author: khaled waleed
 */ 

#include "SPI_PROTOTYPES.h"
#include "DIO_PROTOTYPES.h"


void SPI_INT ( void )
{
	/*
	 STATING MASTER OR SLAVE  
	*/
	
	#if SPI_STATE_OF_OPERATION  ==    SPI_MASTER
	
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_MOSI_PIN , DIO_OUTPUT);
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_MISO_PIN , DIO_INPUT);
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_SS_PIN   , DIO_OUTPUT);   
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_CLK_PIN  , DIO_OUTPUT);
	
	SET_BIT (SPCR , DIO_PIN4 );
		
	#elif SPI_STATE_OF_OPERATION  ==  SPI_SLAVE
	
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_MOSI_PIN , DIO_INPUT);
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_MISO_PIN , DIO_OUTPUT);
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_SS_PIN   , DIO_INPUT);
	DIO_SET_PIN_DIREC(SPI_PORT , SPI_CLK_PIN  , DIO_INPUT);
	
	CLR_BIT (SPCR , DIO_PIN4);
	
	#endif
	
	
	#if SPI_INTERRUPT_STATE    ==   SPI_INTERRUPT_ON
	
	SET_BIT (SREG , DIO_PIN7 );
	
	SET_BIT (SPCR , DIO_PIN7 );
	
	#endif
	
	
	/*
	 ENEBLING THE SPI IN GENERAL 
	*/
	
	SET_BIT (SPCR , DIO_PIN6);
	
}


void SPI_MASTER_PRE_SCALLER(void)
{
	/*
	 STATING THE PRE_SCALLER VALUE   
	*/
	
	#if SPI_PRE_SCALLER_VALUE    ==   SPI_PRE_SCALLER_2
	
	CLR_BIT(SPCR ,DIO_PIN0);
	CLR_BIT(SPCR ,DIO_PIN1);
	SET_BIT(SPSR ,DIO_PIN0);
	
	#elif SPI_PRE_SCALLER_VALUE  ==   SPI_PRE_SCALLER_4
	
	CLR_BIT(SPCR ,DIO_PIN0);
	CLR_BIT(SPCR ,DIO_PIN1);
	CLR_BIT(SPSR ,DIO_PIN0);
	
	#elif SPI_PRE_SCALLER_VALUE  ==   SPI_PRE_SCALLER_8
	
	SET_BIT(SPCR ,DIO_PIN0);
	CLR_BIT(SPCR ,DIO_PIN1);
	SET_BIT(SPSR ,DIO_PIN0);
	
	#elif SPI_PRE_SCALLER_VALUE  ==   SPI_PRE_SCALLER_16
	
	SET_BIT(SPCR ,DIO_PIN0);
	CLR_BIT(SPCR ,DIO_PIN1);
	CLR_BIT(SPSR ,DIO_PIN0);
	
	#elif SPI_PRE_SCALLER_VALUE  ==   SPI_PRE_SCALLER_32
	
	CLR_BIT(SPCR ,DIO_PIN0);
	SET_BIT(SPCR ,DIO_PIN1);
	SET_BIT(SPSR ,DIO_PIN0);
	
	#elif SPI_PRE_SCALLER_VALUE  ==   SPI_PRE_SCALLER_64
	
	SET_BIT(SPCR ,DIO_PIN0);
	SET_BIT(SPCR ,DIO_PIN1);
	SET_BIT(SPSR ,DIO_PIN0);
	
	#elif SPI_PRE_SCALLER_VALUE  ==   SPI_PRE_SCALLER_128
	
	SET_BIT(SPCR ,DIO_PIN0);
	SET_BIT(SPCR ,DIO_PIN1);
	CLR_BIT(SPSR ,DIO_PIN0);
	
	#endif
}

void SPI_MASTER_TRANS_START (void )
{
	DIO_SET_PIN_VALUE(SPI_PORT , SPI_SS_PIN , DIO_LOW);
}


void SPI_MASTER_TRANS_STOP (void )
{
	DIO_SET_PIN_VALUE(SPI_PORT , SPI_SS_PIN , DIO_HIGH);
}


uint8 SPI_SNED_RECEIVE (uint8 DATA )
{
	uint8 DATA_RECIEVED = 0;

	SPDR = DATA ;
	
	#if SPI_POLLING_STATE  ==  SPI_POLLING_ON
	
	while (GET_BIT(SPSR , DIO_PIN7) == 0);

	DATA_RECIEVED = SPDR ;

	return DATA_RECIEVED;
	
	#elif SPI_INTERRUPT_STATE  == SPI_INTERRUPT_ON
	
	DATA_RECIEVED = SPDR ;

	return DATA_RECIEVED;
	
	#endif
}