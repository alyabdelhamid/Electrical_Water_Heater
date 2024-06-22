#ifndef ADC_PRIVATE_
#define ADC_PRIVATE_

#define MADC_ADMUX     *((u8 volatile *)0x27 )
#define MADC_ADCL      *((u8 volatile *)0x24 )
#define MADC_ADCH      *((u8 volatile *)0x25 )
#define MADC_ADCSRA    *((u8 volatile *)0x26 )
#define MADC_SFIOR     *((u8 volatile *)0x50 )

#define MADC_ADCRead   *((u16 volatile *)0x24)

#define MADC_AREF           0
#define MADC_AVCC           1
#define MADC_INTERNAL       2

#endif