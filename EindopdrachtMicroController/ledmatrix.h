/*
 * ledmatrix.h
 *
 * Created: 20-3-2019 12:06:44
 *  Author: timvg
 */ 


#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_


#include <avr/io.h>

void twi_start(void);
void twi_stop(void);
void twi_tx(unsigned char data);
void twi_init(void);
void write_data(unsigned char,unsigned char);
char getRowAddress(int);


#endif /* LEDMATRIX_H_ */