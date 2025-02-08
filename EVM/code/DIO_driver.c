/*
 *  Author: sherif
 */ 


#include <avr/io.h>
#include "STD_macros.h"


void setPinDIr(char port , char pin , char dir)
{
	switch (port)
	{
		case 'A':
		case 'a':
		if (dir==1)
		{
			SET_BIT(DDRA,pin) ;
		}
		else 
		{
			CLR_BIT(DDRA,pin);
		}
		break;
		
		case 'B':
		case 'b':
		if (dir==1)
		{
			SET_BIT(DDRB,pin) ;
		}
		else
		{
			CLR_BIT(DDRB,pin);
		}
		break;
		
		
		case 'C':
		case 'c':
		if (dir==1)
		{
			SET_BIT(DDRC,pin) ;
		}
		else
		{
			CLR_BIT(DDRC,pin);
		}
		break;
		
		
		case 'D':
		case 'd':
		if (dir==1)
		{
			SET_BIT(DDRD,pin) ;
		}
		else
		{
			CLR_BIT(DDRD,pin);
		}
		break;	
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void writePIn (char port , char pin , char value)
{
	switch (port)
	{
		case 'A':
		case 'a':
		if (value==1)
		{
			SET_BIT(PORTA,pin) ;
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		
		case 'B':
		case 'b':
		if (value==1)
		{
			SET_BIT(PORTB,pin) ;
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;
		
		
		case 'C':
		case 'c':
		if (value==1)
		{
			SET_BIT(PORTC,pin) ;
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;
		
		
		case 'D':
		case 'd':
		if (value==1)
		{
			SET_BIT(PORTD,pin) ;
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

char readPin (char port , char pin)
{
	char x=0 ;
	switch(port)
	{
		case 'A':
		case 'a':
		x = READ_BIT(PINA,pin);
		break;
		
		case 'B':
		case 'b':
		x = READ_BIT(PINB,pin);
		break;
		
		case 'C':
		case 'c':
		x = READ_BIT(PINC,pin);
		break;
		
		case 'D':
		case 'd':
		x = READ_BIT(PIND,pin);
		break;	
	}
	
	return x;
}

//--------------------------------------------------------------------------------------------------------------------------------

void togglePin (char port , char pin)
{
	switch(port)
	{
		case 'A':
		case 'a':
		TOGG_BIT(PORTA,pin);
		break;
		
		case 'B':
		case 'b':
		TOGG_BIT(PORTB,pin);
		break;
		
		case 'C':
		case 'c':
		TOGG_BIT(PORTC,pin);
		break;
		
		case 'D':
		case 'd':
		TOGG_BIT(PORTD,pin);
		break;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void setPortDir(char port , char dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		DDRA = dir;
		break;
		
		case 'B':
		case 'b':
		DDRB = dir;
		break;
		
		case 'C':
		case 'c':
		DDRC = dir;
		break;
		
		case 'D':
		case 'd':
		DDRD = dir;
		break;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void writePort(char port , char value)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA = value;
		break;
		
		case 'B':
		case 'b':
		PORTB = value;
		break;
		
		case 'C':
		case 'c':
		PORTC = value;
		break;
		
		case 'D':
		case 'd':
		PORTD = value;
		break;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

char readPort (char port)
{
	char x=0 ;
	switch(port)
	{
		case 'A':
		case 'a':
		x = PINA;
		break;
		
		case 'B':
		case 'b':
	    x = PINB;
		break;
		
		case 'C':
		case 'c':
	    x = PINC;
		break;
		
		case 'D':
		case 'd':
	    x = PIND;
		break;
	}
	
	return x;
}


//--------------------------------------------------------------------------------------------------------------------------------


void setLowNibbleDir (char port , char dir )
{
		
	setPinDIr(port,0,READ_BIT(dir,0));
	setPinDIr(port,1,READ_BIT(dir,1));	
	setPinDIr(port,2,READ_BIT(dir,2));			
	setPinDIr(port,3,READ_BIT(dir,3));					
}

//--------------------------------------------------------------------------------------------------------------------------------

void setHighNibbleDir (char port , char dir )
{
	
	setPinDIr(port,4,READ_BIT(dir,0));
	setPinDIr(port,5,READ_BIT(dir,1));
	setPinDIr(port,6,READ_BIT(dir,2));
	setPinDIr(port,7,READ_BIT(dir,3));
}


//--------------------------------------------------------------------------------------------------------------------------------

void writeLowNibble(char port , char val)
{
	writePIn(port,0,READ_BIT(val,0));
	writePIn(port,1,READ_BIT(val,1));
	writePIn(port,2,READ_BIT(val,2));
	writePIn(port,3,READ_BIT(val,3));

}

//--------------------------------------------------------------------------------------------------------------------------------

void writeHighNibble(char port , char val)
{
	writePIn(port,4,READ_BIT(val,0));
	writePIn(port,5,READ_BIT(val,1));
	writePIn(port,6,READ_BIT(val,2));
	writePIn(port,7,READ_BIT(val,3));

}

//--------------------------------------------------------------------------------------------------------------------------------

void pullUpEnable (char port , char pin)
{
	switch(port)
	{
		case'A':
		case'a':
		SET_BIT(PORTA,pin) ;
		break;
		
		case'B':
		case'b':
		SET_BIT(PORTB,pin) ;
		break;
		
		case'C':
		case'c':
		SET_BIT(PORTC,pin) ;
		break;
		
		case'D':
		case'd':
		SET_BIT(PORTD,pin) ;
		break;
		
	}
}