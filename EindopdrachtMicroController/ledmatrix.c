/*
 * ledmatrix.c
 *
 * Created: 20-3-2019 12:05:36
 *  Author: timvg
 */ 

#include "ledmatrix.h"

/******************************************************************/
void twi_init(void)
/*
short:			Init AVR TWI interface and set bitrate
inputs:
outputs:
notes:			TWI clock is set to 100 kHz
Version :    	DMK, Initial code
*******************************************************************/
{
	TWSR = 0;
	TWBR = 64;	 // TWI clock set to 100kHz, prescaler = 0
	// Init HT16K22. Page 32 datasheet
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x21);	// Internal osc on (page 10 HT16K33)
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0xA0);	// HT16K33 pins all output
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0xE3);	// Display Dimming 4/16 duty cycle
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0x81);	// Display OFF - Blink On
	twi_stop();
	
}

/******************************************************************/
void twi_start(void)
/*
short:			Generate TWI start condition
inputs:
outputs:
notes:
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

/******************************************************************/
void twi_stop(void)
/*
short:			Generate TWI stop condition
inputs:
outputs:
notes:
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x10 | 0x04);
}

/******************************************************************/
void twi_tx(unsigned char data)
/*
short:			transmit 8 bits data
inputs:
outputs:
notes:
Version :    	DMK, Initial code
*******************************************************************/
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while( 0 == (TWCR & 0x80) );
}

void write_data(unsigned char adress,unsigned char data)
{
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(adress);	// Address
	twi_tx(data);	// data
	twi_stop();
}