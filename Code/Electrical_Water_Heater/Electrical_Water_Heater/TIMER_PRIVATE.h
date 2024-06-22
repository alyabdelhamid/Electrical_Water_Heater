#ifndef _timer0_private
#define _timer0_private

#define MTIMER_TCCR0 *((volatile u8 *)0x53)

#define MTIMER_TCCR0_CS00 0
#define MTIMER_TCCR0_CS01 1
#define MTIMER_TCCR0_CS02 2
#define MTIMER_TCCR0_WGM01 3
#define MTIMER_TCCR0_COM00 4
#define MTIMER_TCCR0_COM01 5
#define MTIMER_TCCR0_WGM00 6
#define MTIMER_TCCR0_FOC0 7


#define MTIMER_TCNT0 *((volatile u8 *)0x52)

#define MTIMER_OCR0 *((volatile u8 *)0x5C)

#define MTIMER_TIFR *((volatile u8 *)0x58)

#define MTIMER_TIFR_TOV0 0
#define MTIMER_TIFR_OCF0 1
#define MTIMER_TIFR_TOV1 2
#define MTIMER_TIFR_OCF1B 3
#define MTIMER_TIFR_OCF1A 4
#define MTIMER_TIFR_ICF1 5
#define MTIMER_TIFR_TOV2 6
#define MTIMER_TIFR_OCF2 7


#define MTIMER_TIMSK *((volatile u8 *)0x59)

#define MTIMER_TIMSK_TOIE0 0
#define MTIMER_TIMSK_OCIE0 1
#define MTIMER_TIMSK_TOIE1 2
#define MTIMER_TIMSK_OCIE1B 3
#define MTIMER_TIMSK_OCIE1A 4
#define MTIMER_TIMSK_TICIE1 5
#define MTIMER_TIMSK_TOIE2 6
#define MTIMER_TIMSK_OCIE2 7


#define MTIMER_OCR1A *((volatile u16 *)0x4A)
#define MTIMER_OCR1AH *((volatile u8 *)0x4B)

#define MTIMER_ICR1 *((volatile u16 *)0x46)
#define MTIMER_ICR1H *((volatile u8 *)0x47)

#define MTIMER_OCR1B *((volatile u16 *)0x48)
#define MTIMER_OCR1BH *((volatile u8 *)0x49)

#define MTIMER_TCCR1A *((volatile u8 *)0x4F)
#define MTIMER_TCCR1B *((volatile u8 *)0x4E)

#define MTIMER_TCNT1H *((volatile u8 *)0x4D)
#define MTIMER_TCNT1L *((volatile u8 *)0x4C)

#define NORMAL_MODE 0
#define CTC_MODE 1
#define PWM_PHASE_CORRECT 2
#define FAST_PWM 3

#define PRESCALER_OFF 1
#define PRESCALER_8 2
#define PRESCALER_64 3
#define PRESCALER_256 4
#define PRESCALER_1024 5

#define ENABLE 1
#define DISABLE 0

#endif