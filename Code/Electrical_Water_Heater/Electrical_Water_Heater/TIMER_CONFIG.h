#ifndef _timer0_config
#define _timer0_config

/***************************** TIMER MODES **********************************
 * NORMAL_MODE
 * CTC_MODE
 * PWM_PHASE_CORRECT
 * FAST_PWM
*****************************************************************************/
#define   Timer0_Mode   CTC_MODE
#define   Timer1_Mode   CTC_MODE

/***************************** TIMER PRESCALERS *****************************
 * PRESCALER_OFF
 * PRESCALER_8
 * PRESCALER_64
 * PRESCALER_256
 * PRESCALER_1024
*****************************************************************************/

#define   Timer0_Prescaler PRESCALER_1024
#define   Timer1_Prescaler 

/***************************** TIMER INTRUPT *****************************
 * ENABLE
 * DISABLE
*****************************************************************************/
#define Timer0_INTRUPT ENABLE
#define Timer1_INTRUPT ENABLE

#define PRELOAD_TCNT0_VALUE 0
#define PRELOAD_OCR0_VALUE 250

#define PRELOAD_OCR1A_VALUE 98

#endif