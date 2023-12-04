/*
 * FINAL_MCAL.c
 *
 * Created: 11/27/2023 7:41:00 PM
 * Author : khaled waleed
 */ 

#define  F_CPU  8000000

#include "DIO_PROTOTYPES.h"
#include "TIMER_0_PRORTOTYPES.h"
#include "TIMER_1_PROTOTYPES.h"
#include "TIMER_2_PROTOTYPES.h"
#include "TIMER_3_PROTOTYPES.h"
#include "INTERRUPT_PROTOTYPES.h"
//#include "ICU_PROTOTYPES.h"
#include <util/delay.h>
#include <avr/interrupt.h>

extern uint32 NUM_OVER_FLOW_TIMER_0 ;

extern uint32 STARTING_TICK_VALUE_TIMER_0;

extern uint32 COMPARE_MATCH_CTC_TIMER_0;

volatile uint32 Counter_COMPARE_MATCH_TIMER_0 = 0;

volatile uint32 Counter_OVERFLOW_TIMER_0 = 0;

//////////////////////////////////////////////////

extern uint32 NUM_OVER_FLOW_TIMER_1;

extern uint32 STARTING_TICK_VALUE_TIMER_1;

extern uint32 COMPARE_MATCH_CTC_TIMER_1;

volatile uint32 Counter_COMPARE_MATCH_TIMER_1 = 0;

volatile uint32 Counter_OVERFLOW_TIMER_1 = 0;

//////////////////////////////////////////////////////

extern uint32 NUM_OVER_FLOW_TIMER_3;

extern uint32 STARTING_TICK_VALUE_TIMER_3;

extern uint32 COMPARE_MATCH_CTC_TIMER_3;

volatile uint32 Counter_COMPARE_MATCH_TIMER_3 = 0;

volatile uint32 Counter_OVERFLOW_TIMER_3 = 0;

//////////////////////////////////////////////////////

extern uint32 NUM_OVER_FLOW_TIMER_2;

extern uint32 STARTING_TICK_VALUE_TIMER_2;

extern uint32 COMPARE_MATCH_CTC_TIMER_2;

volatile uint32 Counter_COMPARE_MATCH_TIMER_2 = 0;

volatile uint32 Counter_OVERFLOW_TIMER_2 = 0;

int main(void)
{
	// ENABLE
	
	DIO_SET_PIN_DIREC(DIO_PORTF , DIO_PIN1 ,DIO_OUTPUT);
	DIO_SET_PIN_VALUE(DIO_PORTF , DIO_PIN1 , DIO_HIGH);
	
	DIO_SET_PIN_DIREC(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
	DIO_SET_PIN_DIREC(DIO_PORTA , DIO_PIN7 , DIO_OUTPUT);
	
	DIO_SET_PIN_VALUE(DIO_PORTA,DIO_PIN0,DIO_LOW);
	
	DIO_SET_PIN_VALUE(DIO_PORTA,DIO_PIN7,DIO_LOW);
	
	//TIMER_2_INT();
		  
	//TIMER_2_SET_TIME(1000);
	
	//TIMER_0_INT();
	
	//TIMER_0_SET_TIME(9000);
	
	//TIMER_0_START();
	
	//TIMER_2_START();
	
	//TIMER_1_INT();
	
	//TIMER_1_SET_TIME(15);

	//TIMER_1_START();
	
	TIMER_3_INT();
		  
	//TIMER_3_SET_TIME(20);
		  
	//TIMER_3_START();
	
	uint8 i;
	
    /* Replace with your application code */
    while (1) 
    {
		
		
       for (i =0 ; i < 100 ; i++)
	   {
		   TIMER_3_SET_DUTY_CYCLE(i);
		   TIMER_3_DUTY_CYCLE_START ();
		   _delay_ms(200);
	   }
	   
    }
}


ISR (TIMER2_OVF_vect)
{	
	Counter_OVERFLOW_TIMER_2 ++;
	
	if (Counter_OVERFLOW_TIMER_2 == NUM_OVER_FLOW_TIMER_2)
	{
		Counter_OVERFLOW_TIMER_2 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN7);
		TCNT2 = STARTING_TICK_VALUE_TIMER_2;
	}
}


ISR (TIMER2_COMP_vect)
{
	
	//DIO_TOOGLE_PIN(DIO_PORTA,DIO_PIN0);
	
	Counter_COMPARE_MATCH_TIMER_2 ++;

	if (Counter_COMPARE_MATCH_TIMER_2 == COMPARE_MATCH_CTC_TIMER_2)
	{
		Counter_COMPARE_MATCH_TIMER_2 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN7);
		
	}

}


ISR (TIMER0_OVF_vect)
{
	Counter_OVERFLOW_TIMER_0 ++;
	
	if (Counter_OVERFLOW_TIMER_0 == NUM_OVER_FLOW_TIMER_0)
	{
		Counter_OVERFLOW_TIMER_0 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN0);
		TCNT0 = STARTING_TICK_VALUE_TIMER_0;
	}
}


ISR (TIMER0_COMP_vect)
{
	
	//DIO_TOOGLE_PIN(DIO_PORTA,DIO_PIN0);
	
	Counter_COMPARE_MATCH_TIMER_0 ++;

	if (Counter_COMPARE_MATCH_TIMER_0 == COMPARE_MATCH_CTC_TIMER_0)
	{
		Counter_COMPARE_MATCH_TIMER_0 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN0);
		
	}

}



ISR (TIMER1_OVF_vect)
{
	Counter_OVERFLOW_TIMER_1 ++;
	
	if (Counter_OVERFLOW_TIMER_1 == NUM_OVER_FLOW_TIMER_1)
	{
		Counter_OVERFLOW_TIMER_1 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN0);
		TCNT1L = STARTING_TICK_VALUE_TIMER_1;
	}
}


ISR (TIMER1_COMPA_vect)
{
	
	//DIO_TOOGLE_PIN(DIO_PORTA,DIO_PIN0);
	
	Counter_COMPARE_MATCH_TIMER_1 ++;

	if (Counter_COMPARE_MATCH_TIMER_1 == COMPARE_MATCH_CTC_TIMER_1)
	{
		Counter_COMPARE_MATCH_TIMER_1 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN0);
		
	}

}


ISR (TIMER3_OVF_vect)
{
	Counter_OVERFLOW_TIMER_3 ++;
	
	if (Counter_OVERFLOW_TIMER_3 == NUM_OVER_FLOW_TIMER_3)
	{
		Counter_OVERFLOW_TIMER_3 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN0);
		TCNT3L = STARTING_TICK_VALUE_TIMER_3;
	}
}


ISR (TIMER3_COMPA_vect)
{
	
	//DIO_TOOGLE_PIN(DIO_PORTA,DIO_PIN0);
	
	Counter_COMPARE_MATCH_TIMER_3 ++;

	if (Counter_COMPARE_MATCH_TIMER_3 == COMPARE_MATCH_CTC_TIMER_3)
	{
		Counter_COMPARE_MATCH_TIMER_3 = 0;
		DIO_TOOGLE_PIN(DIO_PORTA , DIO_PIN0);
		
	}

}