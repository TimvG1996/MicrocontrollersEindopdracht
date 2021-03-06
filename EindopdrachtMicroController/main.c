/*
 * EindopdrachtMicroController.c
 *
 * Created: 20-3-2019 09:59:35
 * Author : timvg
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "animation.h"
#include "ledmatrix.h"

void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/*
	initMatrix()

	This will initialize the matrix for writing text on the matrix display
*/
void initMatrix(void){
	twi_init();

	
	DDRA = 0b11111111;

	EICRB |= 0b11000000; //set INT7 faling edge
	EIMSK |= 0b10000000; //enable INT&
	//enable global interrupt system
	sei();
}

/*
	main()

	Method that will be called on start-up. With a forever loop that will show the text and scrolls it
*/
int main(void)
{
	initMatrix();
	wait(500);

	clear();	
	
	for (;;)
	{
		show_first_animation();
		wait(20);
		clear();
		wait(20);
		show_second_animation();
		wait(20);
		clear();
		wait(20);
		reverse_second_animation();
		wait(20);
		clear();
	}
}

