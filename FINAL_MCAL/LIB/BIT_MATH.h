/*
 * BIT_MATH.h
 *
 * Created: 11/27/2023 7:45:51 PM
 *  Author: khaled waleed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)  (reg |=  (1<<(bit)))
#define CLR_BIT(reg,bit)  (reg &= ~(1<<(bit)))
#define TOGGLE_BIT(reg,bit) (reg ^=  (1<<(bit)))
#define TOGGLE_REG(reg)	  (reg= ~(reg))
#define GET_BIT(reg,bit)  ((reg>>(bit)) & 1)

#endif /* BIT_MATH_H_ */