/*
 *  Author: sherif
 */ 


#include <avr/io.h>
#include "std_macros.h"


void EEPROM_write (short address , char data)
{
	EEAR = address ;
	EEDR = data ;
	CLR_BIT(SREG,7);
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	SET_BIT(SREG,7);
	while(READ_BIT(EECR,EEWE));
}

//--------------------------------------------------------------------------------------------------------------------------------

char EEPROM_read (short address)
{
	EEAR = address;
	SET_BIT(EECR,EERE);
	return EEDR ;
}


