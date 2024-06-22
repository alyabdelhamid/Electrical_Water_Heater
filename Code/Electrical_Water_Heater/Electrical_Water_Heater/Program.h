/*
 * Program.h
 *
 * Created: 2/20/2024 11:06:20 PM
 *  Author: alimo
 */ 


#ifndef PROGRAM_H_
#define PROGRAM_H_

// Including All Peripherals
#define F_CPU 1000000UL
//#include <avr/io.h>
#include <util/delay.h>

#include "std_types.h"
#include "bit_math.h"
#include "registers.h"

#include "adc_config.h"
#include "adc_interface.h"
#include "adc_private.h"

#include "TIMER_CONFIG.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"

#include "SSD_config.h"
#include "SSD_interface.h"

#include "buttons.h"
#include "heating_and_cooling.h"
#include "led.h"


#include "EEPROM.h"

#include "program.h"
#include "program_config.h"

#define OFF 0
#define ON 1
#define SETTING 2

/****************************************
*               Functions               *
****************************************/

void sys_init(void);
void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void);
void add_new_temp(u16 * arr , u16 new_val);
u16 calc_avg_temp(u16 * arr);
void temp_arr_init(void);
void go_to_sleep(void);

/****************************************
*               Variables               *
****************************************/

// will add as needed

u8 Curr_state;

u16 temp_arr[NUM_OF_TEMP_MEASURES];
u16 desired_temp;
u16 actual_temp;
u16 avg_temp;

u8 temp_measure_f;
u8 temp_measure_counter;
u8 setting_counter;

u16 toggle_f;
u8 arr_counter;

u8 heat_on_f;




#endif /* PROGRAM_H_ */