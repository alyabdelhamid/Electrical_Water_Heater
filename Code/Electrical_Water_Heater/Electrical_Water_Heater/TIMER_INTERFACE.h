#ifndef _timer0_interface
#define _timer0_interface

void MTimer0_u8Init();
void MTimer0_vSetOCR0Value(u8 number);

void MTimer1_vInit(void);
void MTimer1_vSetOCR1Value(u16 number);

void timer1_INT_disable(void);
void timer1_INT_enable(void);


#endif