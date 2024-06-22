#include "bit_math.h"
#include "std_types.h"
#include <avr/interrupt.h>

#include "TIMER_CONFIG.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_INTERFACE.h"



void MTimer0_u8Init()
{
    switch (Timer0_Mode)
    {
    case NORMAL_MODE:
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM00);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM01);
        break;

    case CTC_MODE:
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM00);
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM01);
        break;
    case PWM_PHASE_CORRECT:
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM00);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM01);
        break;

    case FAST_PWM:
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM00);
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM01);
        break;

    default:
    //Treat as normal mode
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM00);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_WGM01);
        break;
    }

    switch (Timer0_Prescaler)
    {
    case PRESCALER_OFF:
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS00);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS01);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS02);
        break;

    case PRESCALER_8:
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS00);
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS01);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS02);
        break;

    case PRESCALER_64:
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS00);
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS01);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS02);
        break;

    case PRESCALER_256:
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS00);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS01);
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS02);
        break;

    case PRESCALER_1024:
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS00);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS01);
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS02);
        break;
    
    default:
    //Treat as prescaler off
        SET_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS00);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS01);
        CLEAR_BIT(MTIMER_TCCR0,MTIMER_TCCR0_CS02);
        break;
    }

    MTIMER_OCR0 = PRELOAD_OCR0_VALUE;
    MTIMER_TCNT0 = PRELOAD_TCNT0_VALUE;

    if (Timer0_INTRUPT)
    {
        sei();
        SET_BIT(MTIMER_TIMSK,MTIMER_TIMSK_OCIE0);

    }
    
}

void MTimer1_vInit(void)
{

    /// CTC Mode ///
    CLEAR_BIT(MTIMER_TCCR1A, 0);
    CLEAR_BIT(MTIMER_TCCR1A, 1);
    SET_BIT(MTIMER_TCCR1B, 3);
    CLEAR_BIT(MTIMER_TCCR1B, 4);


    /// Set OverFlow Value ///
    MTIMER_OCR1A = PRELOAD_OCR1A_VALUE;

   

    /// Prescaler 1024 ///
    SET_BIT(MTIMER_TCCR1B, 0);
    CLEAR_BIT(MTIMER_TCCR1B, 1);
    SET_BIT(MTIMER_TCCR1B, 2);
    

    sei();

}

void MTimer0_vSetOCR0Value(u8 number){

    MTIMER_OCR0=number;

}

void MTimer1_vSetOCR1Value(u16 number){

    MTIMER_OCR1A = number;


}

void timer1_INT_disable(){
	
	// Disable Interrupts when Comparing with values A
	CLEAR_BIT(MTIMER_TIMSK,MTIMER_TIMSK_OCIE1A);
	
}



void timer1_INT_enable(){
	
	// Enable Interrupts when Comparing with values A 
	SET_BIT(MTIMER_TIMSK,MTIMER_TIMSK_OCIE1A);
	
}
