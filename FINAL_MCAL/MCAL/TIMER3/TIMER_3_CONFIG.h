/*
 * TIMER_3_CONFIG.h
 *
 * Created: 11/28/2023 3:09:23 PM
 *  Author: khaled waleed
 */ 


#ifndef TIMER_3_CONFIG_H_
#define TIMER_3_CONFIG_H_

#include "ATMEGA_128_REGS.h"
#include "BIT_MATH.h"

/*
MACROS FOR THE TIMER'S MODES OF OPERATION 
*/

#define TIMER_3_NORMAL_MODE                             0
#define TIMER_3_PWM_PHASE_CORRET_8_BIT_MODE             1
#define TIMER_3_PWM_PHASE_CORRET_9_BIT_MODE             2
#define TIMER_3_PWM_PHASE_CORRET_10_BIT_MODE            3
#define TIMER_3_CTC_MODE_OCR3A                          4
#define TIMER_3_FAST_PWM_8_BIT_MODE                     5  
#define TIMER_3_FAST_PWM_9_BIT_MODE                     6  
#define TIMER_3_FAST_PWM_10_BIT_MODE                    7  
#define TIMER_3_PWM_PHASE_FREQU_CORRECT_ICR3            8  
#define TIMER_3_PWM_PHASE_FREQU_CORRECT_OCR3A           9   
#define TIMER_3_PWM_PHASE_CORRECT_ICR3                 10  
#define TIMER_3_PWM_PHASE_CORRECT_OCR3A                11  
#define TIMER_3_CTC_MODE_ICR3                          12
#define TIMER_3_REVERSED_MODE                          13
#define TIMER_3_FAST_PWM_MODE_ICR3                     14   // TO PUT WHATEVER VALUE NEEDED IN THE ICR1 REG ( TOP VALUE .. TO HAVE DIFF FREQU VALUES) 
#define TIMER_3_FAST_PWM_MODE_OCR3A                    15



/*
 THE VALUES BY WHICH THE PRE-SCALLER WILL DIVIDE THE CLOCK FREQU. IN ORDER TO HAVE A LARGER TIME RANGE
*/

#define TIMER_3_PRE_SCALLER_DIV_NO       0
#define TIMER_3_PRE_SCALLER_DIV_8        8
#define TIMER_3_PRE_SCALLER_DIV_64       64
#define TIMER_3_PRE_SCALLER_DIV_256      256
#define TIMER_3_PRE_SCALLER_DIV_1024     1024

/*
FOR STATING THE STATE OF TIMER_3 INTERRUPT
*/

#define   TIMER_3_INTERRUPT_DISABLE     0
#define   TIMER_3_INTERRUPT_ENEBLE      1

/*
  CHOOSE WHICH INTERRUPT NEEDED
 */

#define   TIMER_3_OVER_FLOW_INTERRUPT            0
#define   TIMER_3_COMPARE_MATCH_A_INTERRUPT      1
#define   TIMER_3_COMPARE_MATCH_B_INTERRUPT      2
#define   TIMER_3_ICU_INTERRUPT                  3

/*
 CHOOSE INVERTED OR NON INVERTED FOR FAST_PWM_MODE 
 */

#define TIMER_3_FAST_PWM_MODE_NON_INVERTED           0
#define TIMER_3_FAST_PWM_MODE_INVERTED               1


// PWM PIN

#define TIMER_3_DIO_PORT                                DIO_PORTE
#define TIMER_3_DIO_PIN_OC3A                            DIO_PIN3
#define TIMER_3_DIO_PIN_OC3B                            DIO_PIN4
			  
#define TIMER_3_MODE_OF_OPERATION                   TIMER_3_FAST_PWM_MODE_ICR3 
			  											  
#define TIMER_3_PRE_SCALLER_VALUE                   TIMER_3_PRE_SCALLER_DIV_1024 
			  											  
#define TIMER_3_INTERRUPT_STATE                     TIMER_3_INTERRUPT_ENEBLE
			  											  
#define TIMER_3_FAST_PWM_STATE                      TIMER_3_FAST_PWM_MODE_NON_INVERTED
  			  											  
#define TIMER_3_WANTED_INTERRUPT                    TIMER_3_COMPARE_MATCH_A_INTERRUPT
			  
			  

#endif /* TIMER_3_CONFIG_H_ */