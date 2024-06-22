/*
 * EEPROM.h
 *
 * Created: 2/20/2024 10:31:46 PM
 *  Author: alimo
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


//#define SREG  (*(volatile unsigned char *)0x5F)

void EEPROM_write(const u16 addr, u8 data);
u8 EEPROM_read(const u16 addr);


#endif /* EEPROM_H_ */