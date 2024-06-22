/*
 * EEPROM.c
 *
 * Created: 2/20/2024 10:32:05 PM
 *  Author: alimo
 */ 

#include <avr/io.h>
#include "std_types.h"
#include "bit_math.h"
#include "EEPROM.h"


/*----------------------------------------------------------------------------*-
EEPROM_read() : To read the data from the EEPROM given the Address.
-*----------------------------------------------------------------------------*/

unsigned char EEPROM_read(const unsigned short addr){
	// Setup Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// Start Reading
	SET_BIT(EECR,EERE);
	
	// Return Data
	return EEDR;
}

/*----------------------------------------------------------------------------*-
EEPROM_write() : to write data in the EEPROM given the address and the data.
-*----------------------------------------------------------------------------*/

void EEPROM_write(const unsigned short addr, unsigned char data){
	unsigned char INT_EN=0;
	
	// Setup Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// Put Data in Data Register
	EEDR = data;
	
	// Disable Interrupts to work fine
	if(((SREG&(1<<7))>>7)==1){
		INT_EN = 1;
		CLEAR_BIT(SREG,7);
	}
	
	// Start Writing
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	// Back
	if (INT_EN==1)
	{
		SET_BIT(SREG,7);
	}
	
}