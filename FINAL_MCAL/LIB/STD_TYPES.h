/*
 * STD_TYPES.h
 *
 * Created: 11/27/2023 7:46:52 PM
 *  Author: khaled waleed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char            uint8;
typedef signed char              sint8;
typedef unsigned short int      uint16;
typedef signed short int        sint16;
typedef unsigned long int       uint32;
typedef signed long int         sint32;
typedef unsigned long long int  uint64;
typedef signed long long int    sint64;
typedef float                   f32;
typedef double                  f64;
typedef long double             f128;

#define NULL (void *) 0

typedef enum
 {
	FALSE, 
	TRUE
 } boolean;


#endif /* STD_TYPES_H_ */