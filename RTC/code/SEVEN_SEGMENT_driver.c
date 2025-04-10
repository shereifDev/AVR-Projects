/*
 *  Author: sherif
 */ 


#include "DIO_driver.h"



void sevenSeg_init (char port)
{
	setPortDir(port,0b01111111);
}

//--------------------------------------------------------------------------------------------------------------------------------

void sevenSeg_displayNum (char port , char num)
{
	
 char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7f,0x39,0x3f,0x79,0x71};
	 writePort(port,arr[num]);
}

//--------------------------------------------------------------------------------------------------------------------------------

void BCD_init (char port , char nibble)
{
	switch(nibble)
	{
		case 'l':
		case 'L':
		setLowNibbleDir(port,0b1111);
		break;
		
		case 'h':
		case 'H':
		setHighNibbleDir(port,0b1111);
		break;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void BCD_displayNum (char port , char nipple , char num)
{
	switch(nipple)
	{
		case 'l':
		case 'L':
		writeLowNibble(port,num);
		break;
		
		case 'h':
		case 'H':
		writeHighNibble(port,num);
		break;
	}
}