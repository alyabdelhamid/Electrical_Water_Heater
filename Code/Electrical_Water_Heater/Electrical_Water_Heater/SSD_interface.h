#ifndef SSD_INTERFACE
#define SSD_INTERFACE

void SSD_init(void);
void SSD_send(u8 N);
void SSD_enable(u8 disp);
void SSD_disable(void);
void SSD_turn_off(void);
void SSD_write(u8 N);


#endif /* SSD_INTERFACE */
