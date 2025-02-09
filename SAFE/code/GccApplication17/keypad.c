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
	setLowNibbleDir(KEYPAD_PORT, 0b1111);
	setPinDIr(KEYPAD_PORT,C1,0);
	setPinDIr(KEYPAD_PORT,C2,0);
	setPinDIr(KEYPAD_PORT,C3,0);
	pullUpEnable(KEYPAD_PORT,C1);
	pullUpEnable(KEYPAD_PORT,C2);
	pullUpEnable(KEYPAD_PORT,C3);	
}

//----------------------------------------------------------------------------------------------------------

char KEYPAD_getKey(void)
{
	    _delay_ms(200);
		
		writePIn(KEYPAD_PORT,R1,0);
		writePIn(KEYPAD_PORT,R2,1);
		writePIn(KEYPAD_PORT,R3,1);
		writePIn(KEYPAD_PORT,R4,1);
		if(READ_BIT(KEYPAD_PIN,C1)==0)
		{
			return '1';
		}
		if(READ_BIT(KEYPAD_PIN,C2)==0)
		{
			return '2';
		}
		if(READ_BIT(KEYPAD_PIN,C3)==0)
		{
			return '3';
		}
		
		
		writePIn(KEYPAD_PORT,R1,1);
		writePIn(KEYPAD_PORT,R2,0);
		writePIn(KEYPAD_PORT,R3,1);
		writePIn(KEYPAD_PORT,R4,1);
		if(READ_BIT(KEYPAD_PIN,C1)==0)
		{
			return '4';
		}
		if(READ_BIT(KEYPAD_PIN,C2)==0)
		{
			return '5';
		}
		if(READ_BIT(KEYPAD_PIN,C3)==0)
		{
			return '6';
		}
	
		
		writePIn(KEYPAD_PORT,R1,1);
		writePIn(KEYPAD_PORT,R2,1);
		writePIn(KEYPAD_PORT,R3,0);
		writePIn(KEYPAD_PORT,R4,1);
		if(READ_BIT(KEYPAD_PIN,C1)==0)
		{
			return '7';
		}
		if(READ_BIT(KEYPAD_PIN,C2)==0)
		{
			return '8';
		}
		if(READ_BIT(KEYPAD_PIN,C3)==0)
		{
			return '9';
		}
		
			
		writePIn(KEYPAD_PORT,R1,1);
		writePIn(KEYPAD_PORT,R2,1);
		writePIn(KEYPAD_PORT,R3,1);
		writePIn(KEYPAD_PORT,R4,0);
		if(READ_BIT(KEYPAD_PIN,C1)==0)
		{
			return '*';
		}
		if(READ_BIT(KEYPAD_PIN,C2)==0)
		{
			return '0';
		}
		if(READ_BIT(KEYPAD_PIN,C3)==0)
		{
			return '#';
		}
	
		return 0xFF;						
}