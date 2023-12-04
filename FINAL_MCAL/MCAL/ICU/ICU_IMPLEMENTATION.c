/*
 * ICU_IMPLEMENTATION.c
 *
 * Created: 11/28/2023 1:50:36 PM
 *  Author: khaled waleed
 */ 


#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "INTERRUPT_PROTOTYPES.h"
#include "ICU_PROTOTYPES.h"


void (*InterruptSource_voidISR[2])(void)= {NULL };
	
	
ISR( TIMER1_CAPT) {
	if (InterruptSource_voidISR[ICU1] != NULL) {
		InterruptSource_voidISR[ICU1]();
	}
}
ISR( TIMER3_CAPT) {
	if (InterruptSource_voidISR[ICU3] != NULL) {
		InterruptSource_voidISR[ICU3]();
	}
}



ErrorState_t MICU_enInit(ICU_t copy_enID) {
	ErrorState_t Local_enState = SUCCESS;
	if (copy_enID == ICU1) {
		/********************** Adjust Wave Form Generation Mode *********************/
		CLR_BIT(TCCR1B, TCCR1B_WGM13);
		CLR_BIT(TCCR1B, TCCR1B_WGM12);
		CLR_BIT(TCCR1A, TCCR1A_WGM11);
		CLR_BIT(TCCR1A, TCCR1A_WGM10);
		/********************** Adjust Wave Form Generation Mode *********************/

		/****************************** Prescaler Adjust *****************************/
		TCCR1B &= CLOCK_SELECT_MASK;
		TCCR1B |= MICU1_CLOCK_SELECT;
		/****************************** Prescaler Adjust *****************************/

		/**************************** Noise Canceler Adjust **************************/
		#if(MICU1_NOISE_CANCELER_STATUS == NOISE_CANCELER_ENABLED)
		SET_BIT(TCCR1B, TCCR1B_ICNC1);
		#elif(MICU1_NOISE_CANCELER_STATUS == NOISE_CANCELER_DISABLED)
		CLR_BIT(TCCR1B, TCCR1B_ICNC1);
		#else
		#error("Adjust ICU Noise Canceler Correctly")
		#endif
		/**************************** Noise Canceler Adjust **************************/

		/***************************** Initial Edge Trigger **************************/
		#if(MICU1_INITIAL_EDGE == RISING_EDGE)
		SET_BIT(TCCR1B, TCCR1B_ICES1);
		#elif(MICU1_INITIAL_EDGE == FALLING_EDGE)
		CLR_BIT(TCCR1B, TCCR1B_ICES1);
		#else
		#error("Select Initial Trigger Edge")
		#endif
		/***************************** Initial Edge Trigger **************************/
		} else if (copy_enID == ICU3) {
		/********************** Adjust Wave Form Generation Mode *********************/
		CLR_BIT(TCCR3B, TCCR3B_WGM33);
		CLR_BIT(TCCR3B, TCCR3B_WGM32);
		CLR_BIT(TCCR3A, TCCR3A_WGM31);
		CLR_BIT(TCCR3A, TCCR3A_WGM30);
		/********************** Adjust Wave Form Generation Mode *********************/

		/****************************** Prescaler Adjust *****************************/
		TCCR3B &= CLOCK_SELECT_MASK;
		TCCR3B |= MICU3_CLOCK_SELECT;
		/****************************** Prescaler Adjust *****************************/

		/**************************** Noise Canceler Adjust **************************/
		#if(MICU3_NOISE_CANCELER_STATUS == NOISE_CANCELER_ENABLED)
		SET_BIT(TCCR3B, TCCR3B_ICNC3);
		#elif(MICU3_NOISE_CANCELER_STATUS == NOISE_CANCELER_DISABLED)
		CLR_BIT(TCCR3B, TCCR3B_ICNC3);
		#else
		#error("Adjust ICU Noise Canceler Correctly")
		#endif
		/**************************** Noise Canceler Adjust **************************/

		/***************************** Initial Edge Trigger **************************/
		#if(MICU3_INITIAL_EDGE == RISING_EDGE)
		SET_BIT(TCCR3B, TCCR3B_ICES3);
		#elif(MICU3_INITIAL_EDGE == FALLING_EDGE)
		CLR_BIT(TCCR3B, TCCR3B_ICES3 );
		#else
		#error("Select Initial Trigger Edge")
		#endif
		/***************************** Initial Edge Trigger **************************/
		} else {
		Local_enState = OUT_OF_RANGE;
	}

	return Local_enState;
}

ErrorState_t MICU_enEdgeSelect(ICU_t copy_enID, Edge_t copy_enEdge) {
	ErrorState_t Local_enState = SUCCESS;
	if (copy_enID == ICU1) {
		if (copy_enEdge == FALLING) {
			CLR_BIT(TCCR1B, TCCR1B_ICES1);
			} else if (copy_enEdge == RISING) {
			SET_BIT(TCCR1B, TCCR1B_ICES1);
			} else {
			Local_enState = OUT_OF_RANGE;
		}
		} else if (copy_enID == ICU3) {
		if (copy_enEdge == FALLING) {
			CLR_BIT(TCCR3B, TCCR3B_ICES3);
			} else if (copy_enEdge == RISING) {
			SET_BIT(TCCR3B, TCCR3B_ICES3);
			} else {
			Local_enState = OUT_OF_RANGE;
		}
		} else {
		Local_enState = OUT_OF_RANGE;
	}

	return Local_enState;
}

ErrorState_t MICU_enInterruptEnable(ICU_t copy_enID) {
	ErrorState_t Local_enState = SUCCESS;
	if (copy_enID == ICU1) {
		SET_BIT(TIMSK, TIMSK_TICIE1);
		} else if (copy_enID == ICU3) {
		SET_BIT(ETIMSK, ETIMSK_TICIE3);
		} else {
		Local_enState = OUT_OF_RANGE;
	}
	return Local_enState;
}

ErrorState_t MICU_enInterruptDisable(ICU_t copy_enID) {
	ErrorState_t Local_enState = SUCCESS;
	if (copy_enID == ICU1) {
		CLR_BIT(TIMSK, TIMSK_TICIE1);
		} else if (copy_enID == ICU3) {
		CLR_BIT(ETIMSK, ETIMSK_TICIE3);
		} else {
		Local_enState = OUT_OF_RANGE;
	}
	return Local_enState;
}

ErrorState_t MICU_enReadICR(ICU_t copy_enID, uint16 *ptrVal) {
	ErrorState_t Local_enState = SUCCESS;
	if (ptrVal == NULL) {
		Local_enState = NULL_POINTER;
		} else {
		if (copy_enID == ICU1) {
			*ptrVal = ICR1;
			} else if (copy_enID == ICU3) {
			*ptrVal = ICR3;
			} else {
			Local_enState = OUT_OF_RANGE;
		}

	}
	return Local_enState;
}

ErrorState_t MICU_enSetCallBack(ICU_t copy_enID, void (*ptrFUN)(void)) {
	ErrorState_t Local_enState = SUCCESS;
	if (ptrFUN == NULL) {
		Local_enState = NULL_POINTER;
		} else {
		if (copy_enID == ICU1) {
			InterruptSource_voidISR[ICU1] = ptrFUN;
			} else if (copy_enID == ICU3) {
			InterruptSource_voidISR[ICU3] = ptrFUN;
			} else {
			Local_enState = OUT_OF_RANGE;
		}
	}
	return Local_enState;
}