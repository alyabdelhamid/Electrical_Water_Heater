/*
 * heating_and_cooling.h
 *
 * Created: 2/20/2024 8:33:08 PM
 *  Author: alimo
 */ 


#ifndef HEATING_AND_COOLING_H_
#define HEATING_AND_COOLING_H_

#define HEAT_DIR DDRB
#define HEAT_PORT PORTB
#define HEAT_PIN 4

#define COOL_DIR DDRB
#define COOL_PORT PORTB
#define COOL_PIN 5

void heat_init(void);
void heat_start(void);
void heat_stop(void);

void cool_init(void);
void cool_start(void);
void cool_stop(void);



#endif /* HEATING_AND_COOLING_H_ */