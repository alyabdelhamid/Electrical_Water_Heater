/*
 * led.c
 *
 * Created: 2/20/2024 5:42:35 PM
 *  Author: alimo
 */ 

//// INCLUDE LIBRARIES////
#include "bit_math.h"
#include "std_types.h"
#include "registers.h"


//// INCLUDE HAL ////
#include "led.h"



/*------------------------------------------------------------------------------
led_init() : to init. heating element indication led by making it an output pin.
------------------------------------------------------------------------------*/

void led_init(void){
	
	// Setting the PIN as an output pin
	// the LED pin is initially off
	
	SET_BIT(LED_DIR,LED_PIN);
	CLEAR_BIT(LED_PORT,LED_PIN);
}


/*----------------------------------------------------------------------------*-
LED control : to turn on/off or toggle the LED.
-*----------------------------------------------------------------------------*/

void led_on(void){
	SET_BIT(LED_PORT,LED_PIN);
}

void led_off(void){
	CLEAR_BIT(LED_PORT,LED_PIN);
}