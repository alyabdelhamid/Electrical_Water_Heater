#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(var,bit_number)		var|= (1<<bit_number)
#define CLEAR_BIT(var,bit_number)		var &= (~(1<<bit_number))
#define GET_BIT(var,bit_number)		((var>>bit_number)&1)
#define TOGGLE_BIT(var,bit_number)		var^= (1<<bit_number)


#endif


