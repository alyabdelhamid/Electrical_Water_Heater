/*
 * buttons.h
 *
 * Created: 2/20/2024 6:12:40 PM
 *  Author: alimo
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_

#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

//# define MCUCSR  (*(volatile unsigned char *)0x54)
//# define GICR  (*(volatile unsigned char *)0x5B)

//#define ISC2 6
//#define INT2 5

#define PRESSED 1
#define NOT_PRESSED 0

#define DEBOUNCE_INTERVAL 150
#define BUTTONS_PORT PORTB
#define BUTTONS_DIR DDRB


#define ON_OFF_PIN 2
#define UP_PIN 1
#define DOWN_PIN 3

// Buttons Reading Functions
void Buttons_init(void);
//void ON_OFF_EXTI(void);

u8 UP_pressed(void);
u8 DOWN_pressed(void);



#endif /* BUTTONS_H_ */