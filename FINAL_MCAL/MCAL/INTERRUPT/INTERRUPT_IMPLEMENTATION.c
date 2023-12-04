/*
 * INTERRUPT_IMPLEMENTATION.c
 *
 * Created: 11/27/2023 8:15:36 PM
 *  Author: khaled waleed
 */ 


#include "INTERRUPT_PROTOTYPES.h"

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
static void (*MEXTI_voidISR[8])(void) = {NULL };
/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
ISR(INT0_vect) {
	if (MEXTI_voidISR[0] != NULL) {
		MEXTI_voidISR[0]();
	}
}

ISR(INT1_vect) {
	if (MEXTI_voidISR[1] != NULL) {
		MEXTI_voidISR[1]();
	}
}

ISR(INT2_vect) {
	if (MEXTI_voidISR[2] != NULL) {
		MEXTI_voidISR[2]();
	}
}

ISR(INT3_vect) {
	if (MEXTI_voidISR[3] != NULL) {
		MEXTI_voidISR[3]();
	}
}

ISR(INT4_vect) {
	if (MEXTI_voidISR[4] != NULL) {
		MEXTI_voidISR[4]();
	}
}

ISR(INT5_vect) {
	if (MEXTI_voidISR[5] != NULL) {
		MEXTI_voidISR[5]();
	}
}

ISR(INT6_vect) {
	if (MEXTI_voidISR[6] != NULL) {
		MEXTI_voidISR[6]();
	}
}

ISR(INT7_vect) {
	if (MEXTI_voidISR[7] != NULL) {
		MEXTI_voidISR[7]();
	}
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
ErrorState_t MEXTI_enEnable(InterruptID_t copy_enINT, Interrupt_signal copy_enSC) {
	ErrorState_t Local_enState = SUCCESS;
	/** Adjust Sense Control **/
	switch (copy_enINT) {
	case INT0_ID:
		// 1- Apply Mask
		EICRA &= INT_0_4_SC_MASK;
		// 2- Set Value
		EICRA |= copy_enSC;
		break;
	case INT1_ID:
		// 1- Apply Mask
		EICRA &= INT_1_5_SC_MASK;
		// 2- Set Value
		EICRA |= copy_enSC << SHIFT_BY_2;
		break;
	case INT2_ID:
		// 1- Apply Mask
		EICRA &= INT_2_6_SC_MASK;
		// 2- Set Value
		EICRA |= copy_enSC << SHIFT_BY_4;
		break;
	case INT3_ID:
		// 1- Apply Mask
		EICRA &= INT_3_7_SC_MASK;
		// 2- Set Value
		EICRA |= copy_enSC << SHIFT_BY_6;
		break;
	case INT4_ID:
		// 1- Apply Mask
		EICRB &= INT_0_4_SC_MASK;
		// 2- Set Value
		EICRB |= copy_enSC;
		break;
	case INT5_ID:
		// 1- Apply Mask
		EICRB &= INT_1_5_SC_MASK;
		// 2- Set Value
		EICRB |= copy_enSC << SHIFT_BY_2;
		break;
	case INT6_ID:
		// 1- Apply Mask
		EICRB &= INT_2_6_SC_MASK;
		// 2- Set Value
		EICRB |= copy_enSC << SHIFT_BY_4;
		break;
	case INT7_ID:
		// 1- Apply Mask
		EICRB &= INT_3_7_SC_MASK;
		// 2- Set Value
		EICRB |= copy_enSC << SHIFT_BY_6;
		break;
	default:
		Local_enState = OUT_OF_RANGE;
		break;
	}
	/** Enable SIE **/
	SET_BIT(EIMSK, copy_enINT);
	return Local_enState;
}

ErrorState_t MEXTI_enDisable(InterruptID_t copy_enINT) {
	CLR_BIT(EIMSK, copy_enINT);
	return SUCCESS;
}

ErrorState_t MEXTI_enSetCallBack(InterruptID_t copy_enINT, void (*ptrFn)(void)) {
	ErrorState_t Local_enState = SUCCESS;
	if (ptrFn == NULL) {
		Local_enState = NULL_POINTER;
	} else {
		switch (copy_enINT) {
		case INT0_ID:
			MEXTI_voidISR[0] = ptrFn;
			break;
		case INT1_ID:
			MEXTI_voidISR[1] = ptrFn;
			break;
		case INT2_ID:
			MEXTI_voidISR[2] = ptrFn;
			break;
		case INT3_ID:
			MEXTI_voidISR[3] = ptrFn;
			break;
		case INT4_ID:
			MEXTI_voidISR[4] = ptrFn;
			break;
		case INT5_ID:
			MEXTI_voidISR[5] = ptrFn;
			break;
		case INT6_ID:
			MEXTI_voidISR[6] = ptrFn;
			break;
		case INT7_ID:
			MEXTI_voidISR[7] = ptrFn;
			break;
		default:
			Local_enState = OUT_OF_RANGE;
			break;
		}
	}
	return Local_enState;
}
