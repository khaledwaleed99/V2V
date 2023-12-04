/*
 * TIMER_0_IMPLEMENTATION.c
 *
 * Created: 11/27/2023 9:12:58 PM
 *  Author: khaled waleed
 */ 


#include "TIMER_0_PRORTOTYPES.h"
#include "INTERRUPT_PROTOTYPES.h"
#include "DIO_PROTOTYPES.h"


/*
 GLOBAL VARIABLS WILL BE NEEDED FOR CALCULAIONS
*/

// FOR NORMAL MODE

uint32 NUM_OVER_FLOW_TIMER_0 = 0;
uint32 STARTING_TICK_VALUE_TIMER_0 = 0;

// FOR CTC MODE

uint32 COMPARE_MATCH_CTC_TIMER_0;


void TIMER_0_INT (void)
{
	/*
	 MODE OF OPERATION SELECTION
	*/
	
	#if TIMER_0_MODE_OF_OPERATION == TIMER_0_NORMAL_MODE 
	
	CLR_BIT (TCCR0 ,DIO_PIN3);
	CLR_BIT (TCCR0 ,DIO_PIN6);
	
	#elif TIMER_0_MODE_OF_OPERATION == TIMER_0_PWM_MODE
	
	SET_BIT (TCCR0 ,DIO_PIN6);
	CLR_BIT (TCCR0 ,DIO_PIN3);
	
	DIO_SET_PIN_DIREC(TIMER_0_DIO_PORT , TIMER_0_DIO_PIN , DIO_OUTPUT);
	
	
	#if TIMER_0_PWM_MODE_STATE      ==    TIMER_0_PHASE_CORRECT_PWM_MODE_NON_INVERTED
	
	CLR_BIT (TCCR0 ,DIO_PIN4);
	SET_BIT (TCCR0 ,DIO_PIN5);
	
	DIO_SET_PIN_VALUE(TIMER_0_DIO_PORT , TIMER_0_DIO_PIN ,DIO_HIGH);
	
	
	#elif TIMER_0_PWM_MODE_STATE      ==    TIMER_0_PHASE_CORRECT_PWM_MODE_INVERTED
	
	SET_BIT (TCCR0 ,DIO_PIN4);
	SET_BIT (TCCR0 ,DIO_PIN5);
	
	DIO_SET_PIN_VALUE(TIMER_0_DIO_PORT , TIMER_0_DIO_PIN , DIO_LOW);
	
	#endif
	
	#elif TIMER_0_MODE_OF_OPERATION == TIMER_0_CTC_MODE
	
	SET_BIT (TCCR0 ,DIO_PIN3);
	CLR_BIT (TCCR0 ,DIO_PIN6);
	
	#elif TIMER_0_MODE_OF_OPERATION == TIMER_0_FAST_PWM_MODE
	
	SET_BIT (TCCR0 ,DIO_PIN3);
	SET_BIT (TCCR0 ,DIO_PIN6);
	
	DIO_SET_PIN_DIREC(TIMER_0_DIO_PORT , TIMER_0_DIO_PIN , DIO_OUTPUT);
	
	
	#if  TIMER_0_FAST_PWM_STATE == TIMER_0_FAST_PWM_MODE_NON_INVERTED
	
	CLR_BIT (TCCR0 ,DIO_PIN4);
	SET_BIT (TCCR0 ,DIO_PIN5);
	
	DIO_SET_PIN_VALUE(TIMER_0_DIO_PORT , TIMER_0_DIO_PIN , DIO_HIGH);
	
	#elif TIMER_0_FAST_PWM_STATE == TIMER_0_FAST_PWM_MODE_INVERTED
	
	SET_BIT (TCCR0 ,DIO_PIN4);
	SET_BIT (TCCR0 ,DIO_PIN5);
	
	DIO_SET_PIN_VALUE(TIMER_0_DIO_PORT , TIMER_0_DIO_PIN , DIO_LOW);

	#endif
	
	#endif
	
	/*
	 INTERRUPT STATE 
	*/
	
	#if TIMER_0_INTERRUPT_STATE  == TIMER_0_INTERRUPT_ENEBLE
	
	SET_BIT (SREG , DIO_PIN7);  // GLOBAL INTERRUPT
	
	#if  TIMER_0_MODE_OF_OPERATION == TIMER_0_NORMAL_MODE
	
	SET_BIT (TIMSK ,DIO_PIN0);   
	
	#elif TIMER_0_MODE_OF_OPERATION == TIMER_0_CTC_MODE
	
	SET_BIT (TIMSK ,DIO_PIN1); 
	
	#endif
	
	#endif
	
	
}


void TIMER_0_START ()
{
	/*
	 STATING THE PRE-SCALLER VALUE 
	*/
	
	#if  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_NO 
	
	SET_BIT ( TCCR0,DIO_PIN0);
	CLR_BIT ( TCCR0,DIO_PIN1);
	CLR_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_8
	
	CLR_BIT ( TCCR0,DIO_PIN0);
	SET_BIT ( TCCR0,DIO_PIN1);
	CLR_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_64
	
	CLR_BIT ( TCCR0,DIO_PIN0);
	CLR_BIT ( TCCR0,DIO_PIN1);
	SET_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_256
	
	CLR_BIT ( TCCR0,DIO_PIN0);
	SET_BIT ( TCCR0,DIO_PIN1);
	SET_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_1024
	
	SET_BIT ( TCCR0,DIO_PIN0);
	SET_BIT ( TCCR0,DIO_PIN1);
	SET_BIT ( TCCR0,DIO_PIN2);
	
	#endif
	
}  

void TIMER_0_STOP (void)
{
	CLR_BIT ( TCCR0,DIO_PIN0);
	CLR_BIT ( TCCR0,DIO_PIN1);
	CLR_BIT ( TCCR0,DIO_PIN2);
}   


// TAKES TIME IN MILLI SEC //

void TIMER_0_SET_TIME (uint32 WANTED_TIME_MSEC)
{
	
	#if TIMER_0_MODE_OF_OPERATION == TIMER_0_NORMAL_MODE 
	
	/*
	 FNDING TIME FOR EACH TICK
	 
	 HERE WE DIVIDED BY 8 (NOT 8000000) .. JUST TO AVOID HAVING MANY ZEROS FOR NO REASON WITH UNIT8
	 
	 HERE THE VALUE WILL IN MICRO DIRCTLY
	*/
	
	uint8 TICK_TIME = ( TIMER_0_PRE_SCALLER_VALUE / 8 );   // = 128 micro sec ( pre= 1024)
	
	/*
	FINDING TOTAL NUMBER OF TICKS FOR A GIVEN TIME
	
	THE WANTED DELAY TIME IS MULTI BY 1000 TO CANGE IT FORM MILLI SECS TO MICRO
	*/
	
	uint32 TOTAL_TICKS = ( WANTED_TIME_MSEC * 1000 ) / TICK_TIME ;
	
	/*
	FINDING THE NUMBER OF OVER-FLOWS NEEDED
	
	256 -> TO REACH OVER FLOW
	*/
	
	NUM_OVER_FLOW_TIMER_0 = TOTAL_TICKS / 256 ;
	
	/*
	STARTING TICK VALUE FOR THE GIVEN TIME ( TO REACH THE FLAG TICK AT THE GIVEN TIME ) 
	*/
	
	STARTING_TICK_VALUE_TIMER_0 = 256 - ( TOTAL_TICKS % 256 );
	
	TCNT0 = STARTING_TICK_VALUE_TIMER_0 ;
	
	NUM_OVER_FLOW_TIMER_0 ++ ;
	
	
	#elif TIMER_0_MODE_OF_OPERATION == TIMER_0_CTC_MODE
	
		/*
		FNDING TIME FOR EACH TICK
		*/
		
		uint8 TICK_TIME = ( TIMER_0_PRE_SCALLER_VALUE / 8 ); // = 64 micro sec (pre = 1024)
			
		/*
		 FINDINH TOTAL NUMBER OF TICKS FOR A GIVEN TIME
		*/
		
		uint32 TOTAL_TICKS = ( WANTED_TIME_MSEC * 1000 ) / TICK_TIME ;
		
		TOTAL_TICKS = TOTAL_TICKS - 1; 
		
		OCR0 = 250;
		
		COMPARE_MATCH_CTC_TIMER_0 = TOTAL_TICKS / 256 ;
		
		#endif
		
} 

void TIMER_0_SET_DUTY_CYCLE (uint8 DUTY_CYCLE)        // JUST STATE THE % OF DUTY CYCLE WANTED
{
	
	#if TIMER_0_MODE_OF_OPERATION   == TIMER_0_FAST_PWM_MODE           
	
	#if  TIMER_0_FAST_PWM_STATE == TIMER_0_FAST_PWM_MODE_NON_INVERTED
	
	OCR0 = ((DUTY_CYCLE * 256)/100) -1 ;
	
	#elif TIMER_0_FAST_PWM_STATE == TIMER_0_FAST_PWM_MODE_INVERTED
	
	OCR0 = ((255 - (DUTY_CYCLE * 256)) / 100 ) -1;
	
	#endif
	
	#elif TIMER_0_MODE_OF_OPERATION   == TIMER_0_PWM_MODE
	
	#if TIMER_0_PWM_MODE_STATE  ==  TIMER_0_PHASE_CORRECT_PWM_MODE_NON_INVERTED 
	
	OCR0 = ( (DUTY_CYCLE * 512)) / 100 ) -1;
	
	#elif TIMER_0_PWM_MODE_STATE  ==  TIMER_0_PHASE_CORRECT_PWM_MODE_INVERTED
	
	OCR0 = ( ( (512)*(DUTY_CYCLE-1) ) / 100 ) -1;
	
	#endif
	
	#endif
}

void TIMER_0_DUTY_CYCLE_START ()

{
	/*
	 STATING THE PRE-SCALLER VALUE 
	*/
	
	#if  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_NO 
	
	SET_BIT ( TCCR0,DIO_PIN0);
	CLR_BIT ( TCCR0,DIO_PIN1);
	CLR_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_8
	
	CLR_BIT ( TCCR0,DIO_PIN0);
	SET_BIT ( TCCR0,DIO_PIN1);
	CLR_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_64
	
	CLR_BIT ( TCCR0,DIO_PIN0);
	CLR_BIT ( TCCR0,DIO_PIN1);
	SET_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_256
	
	CLR_BIT ( TCCR0,DIO_PIN0);
	SET_BIT ( TCCR0,DIO_PIN1);
	SET_BIT ( TCCR0,DIO_PIN2);
	
	#elif  TIMER_0_PRE_SCALLER_VALUE == TIMER_0_PRE_SCALLER_DIV_1024
	
	SET_BIT ( TCCR0,DIO_PIN0);
	SET_BIT ( TCCR0,DIO_PIN1);
	SET_BIT ( TCCR0,DIO_PIN2);
	
	#endif
}