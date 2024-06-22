//// INCLUDE LIBRARIES////
#define F_CPU   1000000UL
#include <util/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "registers.h"

//// INCLUDE HAL ////
#include "SSD_config.h"
#include "SSD_interface.h"


// Array for Numbers' Values
u8 Nums[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

/*------------------------------------------------------------------------------
SSD_Init. : to initialize the Seven Segment by making its port OUTPUT.
------------------------------------------------------------------------------*/
void SSD_init(void){

    // setting Seven Segment Pins as output pins
    SSD_DATA_Direction=0xff;

    SET_BIT(SSD_ENABLE_Direction,SSD1_ENABLE_PIN);
    SET_BIT(SSD_ENABLE_Direction,SSD2_ENABLE_PIN);

    // Seven Segment initially OFF
	SSD_disable();

}


/*------------------------------------------------------------------------------
SSD_Send. : to Send data (Number) to the Seven Segment.
-------------------------------------------------------------------------------*/

void SSD_send(u8 N){

   SSD_DATA_PORT=Nums[N];
}


/*------------------------------------------------------------------------------
SSD_enable() : the 2 seven seg. are multiplexed and works with the same pins.
So, this function is to enable one and disable the other.
------------------------------------------------------------------------------*/

void SSD_enable(u8 disp){
	if(disp == 1){
        SET_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
        CLEAR_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
    }

    else if (disp == 2){
		SET_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
		CLEAR_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
	}
}


/*------------------------------------------------------------------------------
SSD_disable() : To disable the two seven segments for some special cases.
------------------------------------------------------------------------------*/

void SSD_disable(void){
    CLEAR_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
    CLEAR_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
}


/*------------------------------------------------------------------------------
SSD_turn_off() : To turn off the Seven Segment in the OFF STATE.
------------------------------------------------------------------------------*/

void SSD_turn_off(void){
	SSD_DATA_PORT=0x00;
}


/*------------------------------------------------------------------------------
SSD_write() : To calculate what to write on each of the two SSDs, and send.
------------------------------------------------------------------------------*/

void SSD_write(u8 N){
	u8 units;
	u8 tens;
	
	units = N % 10;
	tens =(int) N / 10;
	
	SSD_enable(DISP1);
	SSD_send(units);
	_delay_ms(5);
	
	SSD_enable(DISP2);
	SSD_send(tens);
	_delay_ms(5);
}