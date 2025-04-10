/*
 * APP.c
 *
 * Created: 3/30/2025 12:08:22 AM
 *  Author: sherif
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "DIO_driver.h"
#include "SEVEN_SEGMENT_driver.h"




void displayTime(uint8_t hours , uint8_t minutes , uint8_t seconds)
{
		// display the seconds
		writePIn('C',PC0,0);
		writePIn('C',PC1,1);
		writePIn('C',PC2,1);
		writePIn('C',PC3,1);
		writePIn('C',PC4,1);
		writePIn('C',PC5,1);
		sevenSeg_displayNum('B',seconds%10);
		_delay_ms(5);
		
		writePIn('C',PC0,1);
		writePIn('C',PC1,0);
		writePIn('C',PC2,1);
		writePIn('C',PC3,1);
		writePIn('C',PC4,1);
		writePIn('C',PC5,1);
		sevenSeg_displayNum('B',seconds/10);
		_delay_ms(5);
		
		// display the minutes
		writePIn('C',PC0,1);
		writePIn('C',PC1,1);
		writePIn('C',PC2,0);
		writePIn('C',PC3,1);
		writePIn('C',PC4,1);
		writePIn('C',PC5,1);
		sevenSeg_displayNum('B',minutes%10);
		_delay_ms(5);
		
		writePIn('C',PC0,1);
		writePIn('C',PC1,1);
		writePIn('C',PC2,1);
		writePIn('C',PC3,0);
		writePIn('C',PC4,1);
		writePIn('C',PC5,1);
		sevenSeg_displayNum('B',minutes/10);
		_delay_ms(5);
		
		
		// display the hours
		writePIn('C',PC0,1);
		writePIn('C',PC1,1);
		writePIn('C',PC2,1);
		writePIn('C',PC3,1);
		writePIn('C',PC4,0);
		writePIn('C',PC5,1);
		sevenSeg_displayNum('B', hours%10);
		_delay_ms(5);
		
		writePIn('C',PC0,1);
		writePIn('C',PC1,1);
		writePIn('C',PC2,1);
		writePIn('C',PC3,1);
		writePIn('C',PC4,1);
		writePIn('C',PC5,0);
		sevenSeg_displayNum('B', hours/10);
		_delay_ms(5);
		
}