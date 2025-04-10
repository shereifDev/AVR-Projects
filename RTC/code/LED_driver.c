/*
 * LED_driver.c
 *
 * Created: 12/3/2024 11:27:45 PM
 *  Author: sherif
 */ 
#include "DIO_driver.h"

void LED_init(char port , char pinNum)
{
	setPinDIr(port,pinNum,1);
}

//--------------------------------------------------------------------------------------------------------------------------------

void LED_turnOn(char port,char pinNum)
{
	writePIn(port,pinNum,1);
}

//--------------------------------------------------------------------------------------------------------------------------------

void LED_turnOff(char port,char pinNum)
{
	writePIn(port,pinNum,0);
}

//--------------------------------------------------------------------------------------------------------------------------------

void LED_toggle(char port , char pin)
{
	togglePin(port,pin);
}


