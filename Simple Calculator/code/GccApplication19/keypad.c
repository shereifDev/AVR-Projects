/*
*  Author: sherif
*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "DIO_driver.h"
#include "STD_macros.h"
#include "keypad.h"


void KEYPAD_init(void)
{
	setLowNibbleDir(KEYPAD_PORT, 0b1111);    // set low nibble as input pins
	setHighNibbleDir(KEYPAD_PORT,0b0000);    // set low nibble as output pins
	// enable the internal pull up at high nibble   
	pullUpEnable(KEYPAD_PORT,C1);
	pullUpEnable(KEYPAD_PORT,C2);
	pullUpEnable(KEYPAD_PORT,C3);
	pullUpEnable(KEYPAD_PORT,C4);
}

//----------------------------------------------------------------------------------------------------------

char KEYPAD_getKey(void)
{
	_delay_ms(200);                 
char arr[4][4]={{'7','8','9','/'},
				{'4','5','6','*'},
				{'1','2','3','-'},
				{'A','0','=','+'}};
										 
	for (char row=0 ; row<4 ; row++)
	{
        writeLowNibble(KEYPAD_PORT, 0b1111);
		writePIn(KEYPAD_PORT,row,0);
		for(char col=0 ; col<4 ; col++)
		{
			if(readPin(KEYPAD_PORT,(col+4))==0)
			{
				return  arr[row][col];
			}
		}
	}
	return NOTPRESSED ;
}