/*
 * LED_driver.c
 *
 * Created: 9/19/2024 6:01:07 PM
 *  Author: sherif
 */ 

#include "DIO.h"



void LED_init (char port , char pin)
{
	DIO_setPinDir(port , pin , 1) ;
}

/*--------------------------------------------------------------------------------------------------------------*/

void LED_turnOn (char port , char pin)
{
	DIO_writePin(port , pin ,1 ) ;
}

/*--------------------------------------------------------------------------------------------------------------*/

void LED_turnOff (char port , char pin)
{
	DIO_writePin(port , pin ,0 ) ;
}

/*--------------------------------------------------------------------------------------------------------------*/

void LED_toggle (char port , char pin)
{
	DIO_toggPin(port , pin) ;
}

/*--------------------------------------------------------------------------------------------------------------*/

char LED_readStatus (char port , char pin)
{
	return DIO_readPin(port , pin) ;
}

/*--------------------------------------------------------------------------------------------------------------*/

void LED_initPort (char port)
{
	DIO_writePort(port ,0b11111111);
}