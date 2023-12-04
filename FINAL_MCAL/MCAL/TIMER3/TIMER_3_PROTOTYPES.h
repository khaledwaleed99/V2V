/*
 * TIMER_3_PROTOTYPES.h
 *
 * Created: 11/28/2023 3:08:44 PM
 *  Author: khaled waleed
 */ 


#ifndef TIMER_3_PROTOTYPES_H_
#define TIMER_3_PROTOTYPES_H_

#include "TIMER_3_CONFIG.h"

/*
 STATES THE MODE OF OPERATION & INTERRUPT 
*/

void TIMER_3_INT (void);      

/*
 TO START THE TIMER .. AT WHICH U STATE THE PRE-SCALLER VALUE .. THE TIMER WORKS AUTOMATICALLY WHEN RECIVES A SIGNAL  
*/
void TIMER_3_START (void);   

void TIMER_3_STOP (void);   

/*
 THE FUNCTION AT WHICH WE STATE THE TIME NEEDED .. FOR NORMAL MODE 
 
 IN THIS FUNCTION WE CALCULATE THE FOLLWING :
 
 1) TIME FOR EACH TICK 
 2) TOTAL NUMBER OF TICKS FOR THE GIVEN TIME 
 3) STARTING TICK VALUE FOR THE GIVEN TIME ( TO REACH THE FLAG TICK AT THE GIVEN TIME ) 
 4) NUMBER OF OVER-FLOWS NEEDED
*/ 

void TIMER_3_SET_TIME (uint32 WANTED_TIME_MSEC); 
 

/*
 WHERE THE CALCULATIONS ARE MADE .. BASES ON EACH MODE
*/

void TIMER_3_SET_DUTY_CYCLE (uint8 DUTY_CYCLE); 

/*
 TO START THE DUTY CYCLE .. AT WHICH U STATE THE PRE-SCALLER VALUE .. WORKS AUTOMATICALLY WHEN RECIVES A SIGNAL  
*/
void TIMER_3_DUTY_CYCLE_START (void);


#endif /* TIMER_3_PROTOTYPES_H_ */