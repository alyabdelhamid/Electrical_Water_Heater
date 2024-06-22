/*
 * led.h
 *
 * Created: 2/20/2024 5:40:34 PM
 *  Author: alimo
 */ 


#ifndef LED_H_
#define LED_H_

#define LED_DIR DDRB
#define LED_PORT PORTB
#define LED_PIN 7

void led_init(void);
void led_on(void);
void led_off(void);




#endif /* LED_H_ */