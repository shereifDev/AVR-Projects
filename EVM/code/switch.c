/*
 *  Author: sherif
 */ 

#include "DIO_driver.h"


void switch_init (char port , char pin)
{
	setPinDIr(port,pin,0);
}

//--------------------------------------------------------------------------------------------------------------------------------

unsigned char switch_read(char port , char pin)
{
   return readPin(port,pin);	
}

