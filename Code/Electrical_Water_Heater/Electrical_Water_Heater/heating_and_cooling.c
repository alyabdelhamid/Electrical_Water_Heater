/*
 * heating_and_cooling.c
 *
 * Created: 2/20/2024 8:31:55 PM
 *  Author: alimo
 */ 

//// INCLUDE LIBRARIES////
#include "bit_math.h"
#include "std_types.h"
#include "registers.h"


//// INCLUDE HAL ////
#include "heating_and_cooling.h"

/*------------------------------------------------------------------------------
Heater/Cooler Init. : to initialize cooler and heater pins by making them OUTPUT.
------------------------------------------------------------------------------*/

void heat_init(void){
	SET_BIT(HEAT_DIR,HEAT_PIN);
}

void cool_init(void){
	SET_BIT(COOL_DIR,COOL_PIN);
}

/*------------------------------------------------------------------------------
Heater/Cooler Start : to start the Heater OR the Cooler.
------------------------------------------------------------------------------*/

void heat_start(void){
	SET_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_start(void){
	SET_BIT(COOL_PORT,COOL_PIN);
}


/*------------------------------------------------------------------------------
Heater/Cooler Stop : to stop Heater OR Cooler from working.
------------------------------------------------------------------------------*/

void heat_stop(void){
	CLEAR_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_stop(void){
	CLEAR_BIT(COOL_PORT,COOL_PIN);
}