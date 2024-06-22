#include "bit_math.h"
#include "std_types.h"
#include "registers.h"
#include "adc_config.h"
#include "adc_interface.h"
#include "adc_private.h"

u8 MADC_u8init(u8 MADC_ChannelNum)
{

    u8 Lu8stateerror = std_ok;
    if ((MADC_ChannelNum <= 31))
    {
        MADC_ADMUX &= 0XE0;
        MADC_ADMUX |= MADC_ChannelNum;

        #if MADC_REFVOLTAGE == MADC_AREF
                CLEAR_BIT(MADC_ADMUX, 6);
                CLEAR_BIT(MADC_ADMUX, 7);

        #elif MADC_REFVOLTAGE == MADC_AVCC
                SET_BIT(MADC_ADMUX, 6);
                CLEAR_BIT(MADC_ADMUX, 7);

        #elif MADC_REFVOLTAGE == MADC_INTERNAL
                SET_BIT(MADC_ADMUX, 6);
                SET_BIT(MADC_ADMUX, 7);

        #endif

        MADC_ADMUX |= (MADC_ISLEFTADJUST << 5);

        SET_BIT(MADC_ADCSRA, 7); // ENABLE ADC

        // CHOOSE PRESCALER OF 128 AS CPU_FREQUANCY IS 16 MHZ//

        SET_BIT(MADC_ADCSRA, 0);
        SET_BIT(MADC_ADCSRA, 1);
        SET_BIT(MADC_ADCSRA, 2);

        ////////////////////////////////////////////////////
    }
    else
    {
        Lu8stateerror = std_notok;
    }

    return Lu8stateerror;
}

u8 MADC_u8Read(u16 *ADC_Read)
{

    u8 Lu8ErroreState = std_ok;

    if (ADC_Read != NULL)
    {
        SET_BIT(MADC_ADCSRA, 6);

        while (GET_BIT(MADC_ADCSRA, 4) == 0);

        *ADC_Read=MADC_ADCRead;


    }

    else
    {

        Lu8ErroreState = std_notok;
    }

    return Lu8ErroreState;
}