/*
 * buttons.c
 *
 * Created: 2/20/2024 6:12:08 PM
 *  Author: alimo
 */ 

//// INCLUDE LIBRARIES////
#include "bit_math.h"
#include "std_types.h"



//// INCLUDE HAL ////
#include "Buttons.h"

/*------------------------------------------------------------------------------
Buttons_init() : to initialize Buttons by making their pins as INPUT pins,
enabling the internal pull-up resistor, and enabling the external interrupt
for the ON/OFF button.
------------------------------------------------------------------------------*/

void Buttons_init(void){
	// Setting the pins as INPUT pins
	CLEAR_BIT(BUTTONS_DIR,ON_OFF_PIN);
	CLEAR_BIT(BUTTONS_DIR,UP_PIN);
	CLEAR_BIT(BUTTONS_DIR,DOWN_PIN);
	
	// Enable internal Pull-Up Resistor
	
	SET_BIT(BUTTONS_PORT,ON_OFF_PIN);
	SET_BIT(BUTTONS_PORT,UP_PIN);
	SET_BIT(BUTTONS_PORT,DOWN_PIN);
	
	
	// This Following Section is for the external interrupt
	// assigned to the ON/OFF Button.
	
	// Enable Global Interrupt bit
	sei();
	
	// Trigger with Rising Edge
	SET_BIT(MCUCSR,ISC2);
	
	// Enable INT2 (External Interrupt)
	SET_BIT(GICR,INT2);
}


/*------------------------------------------------------------------------------
UP_pressed() : Check if UP button is pressed or not and return the result.
------------------------------------------------------------------------------*/

u8 UP_pressed(void){
	// Check if pressed for the first time
	if(!(GET_BIT(PINB,UP_PIN))){
		// wait for 150 ms to make sure it's pressed (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check one more time
		if (!(GET_BIT(PINB,UP_PIN))){
			
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}

/*------------------------------------------------------------------------------
DOWN_pressed() : Check if DOWN button is pressed or not and return the result.
------------------------------------------------------------------------------*/

u8 DOWN_pressed(void){
	// Check if pressed for the first time
	if(!(GET_BIT(PINB,DOWN_PIN))){
		// wait for 150 ms to make sure it's pressed (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// check one more time
		if (!(GET_BIT(PINB,DOWN_PIN))){
			
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}