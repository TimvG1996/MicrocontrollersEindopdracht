/*
 * animation.c
 *
 * Created: 20-3-2019 12:20:37
 *  Author: timvg
 *
 */

 #include "animation.h"
 #include "ledmatrix.h"
 
 void show_first_animation(void);
 void show_second_animation(void);
 void reverse_second_animation(void);
 void clear(void);
 
 
 // The array which contains the data for the column of the animation
 char firstAnimationColumn[]= {0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
						   0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0c,
						   0x0A,0x08,0x06,0x04,0x02,0x00,0x00,0x00,
						   0x00,0x00,0x00,0x00,0x02,0x04,0x06,0x08,
						   0x0A,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0A,
						   0x08,0x06,0x04,0x02,0x02,0x02,0x02,0x02,
						   0x04,0x06,0x08,0x0A,0x0A,0x0A,0x0A,0x08,
						   0x06,0x04,0x04,0x04,0x06,0x08,0x08,0x06};

char secondAnimationColumn[]= {0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
							  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
							  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
							  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
							  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
							  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
							  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
							  0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E};


 // The array which contains the data for the row of the animation
 char firstAnimationRow[]= {0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
						0x60,0x70,0x78,0x7C,0x7E,0x7F,0xFF,0xC0,
						0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC1,0xC3,
						0xC7,0xCF,0xDF,0xFF,0xE0,0xE0,0xE0,0xE0,
						0xE0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0xE1,
						0xE1,0xE1,0xE1,0xE1,0xE3,0xE7,0xEF,0xFF,
						0xF1,0xF1,0xF1,0xF1,0xF9,0xFD,0xFF,0xF3,
						0xF3,0xF3,0xF7,0xFF,0xFB,0xFB,0xFF,0xFF}; 
						
char secondAnimationRow[]={0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,
						   0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,
						   0x04,0x04,0x02,0x02,0x01,0x01,0x80,0x80,
						   0x01,0x01,0x80,0x80,0x40,0x40,0x20,0x20,
						   0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,
						   0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,
						   0x04,0x04,0x02,0x02,0x01,0x01,0x80,0x80,
						   0x01,0x01,0x80,0x80,0x40,0x40,0x20,0x20};	
 
 /************************************************************************/
 /*
	This function shows the first animation on the dot matrix. 
	It uses a for loop to go through the arrays where the data for the animation is stored.
	The animation turns on all lights in a specific order.
	Thanks to the arrays the pattern is already in the right order. 
 */
 /************************************************************************/
 void show_first_animation(void)
 {
	 
	 int x;
	 for(x = 0; x < 64; x++)
	 {	 
		 write_data(firstAnimationColumn[x], firstAnimationRow[x]);
		 wait(15);		 
	 }
 }
 
 /************************************************************************/
 /*
	This function shows the second animation on the dot matrix. 
	It uses a for loop to go through the arrays where the data for the animation is stored.
	The animation turns on all lights in a specific order.
	Thanks to the arrays the pattern is already in the right order. 
 */
 /************************************************************************/
 void show_second_animation(void)
 {
	
	 int x;
	 for(x = 0; x < 64; x++)
	 {
		 write_data(secondAnimationColumn[x], secondAnimationRow[x]);
		 wait(15);	 
	 } 
 }
 
 /************************************************************************/
 /*
	This function reverses the second animation.
	It uses a for loop to go through the arrays in reverse order
	where the data for the animation is stored.
 */
 /************************************************************************/
 void reverse_second_animation(void)
 {
	 
	 int x;
	 for(x = 64; x > 0; x--)
	 {	 
		 write_data(secondAnimationColumn[x], secondAnimationRow[x]);
		 wait(15); 
	 }
 }
 
 /************************************************************************/
 /*                                                                   
	This function clears the dot matrix.    
 */
 /************************************************************************/
 void clear()
 {
	int i;
	for (i = 0; i < 8; i++ )
	{
		write_data(firstAnimationColumn[i], 0);
		wait(1/100);
	}
 }
