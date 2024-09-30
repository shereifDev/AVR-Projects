/*
 * DIO.c
 *
 * Created: 9/14/2024 10:22:00 AM
 *  Author: sherif
 */ 
#include "STD_macros.h"
#include "DIO.h"
#include <avr/io.h>


/*---------------------------------------------------PIN------------------------------------------------------*/
void DIO_setPinDir (char port , char pin , char dir)
{
	switch (port)
	{
		case 'a':
		case 'A':
		if (dir == 1)
		{
		    SET_BIT(DDRA , pin);
		} 
		else 
		{
		    CLR_BIT(DDRA , pin);	
		}	
		break ;	
		
		case 'b':
		case 'B':
		if (dir == 1)
		{ 
		    SET_BIT(DDRB , pin);
		}
		else
		{
		    CLR_BIT(DDRB , pin);	
		}
		break ;
		
		
		case 'c':
		case 'C':
		if (dir == 1)
		{
		   SET_BIT(DDRC , pin);
		}
		else
		{
		   CLR_BIT(DDRC , pin);	
		}		
		break ;
		
		case 'd':
		case 'D':
		if (dir == 1)
		{
		   SET_BIT(DDRD , pin);
		}
		else
		{
	       CLR_BIT(DDRD , pin);	
		}
		break ;
			
	}
}

/*--------------------------------------------------------------------------------------------------------------*/

void DIO_writePin (char port , char pin , char val)
{
	switch(port)
	{
	case 'a':
	case 'A':
	if (val == 1)
	{
		 SET_BIT(PORTA , pin);
	}
	else
	{
		 CLR_BIT(PORTA , pin);	
	}
    break ;	

	case 'b':
	case 'B':
	if (val == 1)
	{
	     SET_BIT(PORTB , pin);
	}
	else
	{
		 CLR_BIT(PORTB , pin);	
	}
	break ;
		
	case 'c':
	case 'C':
	if (val == 1)
	{
	     SET_BIT(PORTC , pin);
	}
	else
	{
		 CLR_BIT(PORTC , pin);	
	}
	break ;
			
	case 'd':
	case 'D':
	if (val == 1)
	{
		 SET_BIT(PORTD , pin);
	}
	else
	{
		 CLR_BIT(PORTD , pin);	
	}
	break ;
	
}
}

/*--------------------------------------------------------------------------------------------------------------*/

void DIO_toggPin (char port , char pin)
{
	switch (port)
	{
		case 'a':
		case 'A':
		TOGG_BIT(PORTA , pin);
		break;
		
		case 'b':
		case 'B':
		TOGG_BIT(PORTB , pin);
		break;
		
		case 'c':
		case 'C':
		TOGG_BIT(PORTC , pin);
		break;
		
		case 'd':
		case 'D':
	    TOGG_BIT(PORTD , pin);
		break;
	}
	
}

/*--------------------------------------------------------------------------------------------------------------*/

char DIO_readPin (char port , char pin)
{
	char x ;
	switch(port)
	{
		case 'a':
		case 'A':
		x= READ_BIT(PINA , pin) ;
		break ;
		
		case 'b':
		case 'B':
		x= READ_BIT(PINB , pin) ;
		break ;
		
		case 'c':
		case 'C':
		x= READ_BIT(PINC , pin) ;
		break ;
		
		case 'd':
		case 'D':
		x= READ_BIT(PIND , pin) ;
		break ;		
	}
	
	return x ;
}

/*---------------------------------------------------PORT---------------------------------------------------------*/

void DIO_setPort (char port , char dir)
{
	switch(port)
	{
		case'a':
		case'A':
		DDRA = dir ;
		break;
		
		case'b':
		case'B':
		DDRB = dir ;
		break;
		
		case'c':
		case'C':
		DDRC = dir ;
		break;
		
		case'd':
		case'D':
		DDRD = dir ;
		break;
	}
}

/*--------------------------------------------------------------------------------------------------------------*/

void DIO_writePort (char port , char val)
{
	switch(port)
	{
		case'a':
		case'A':
		PORTA = val ;
		break;
		
		case'b':
		case'B':
		PORTB = val ;
		break;
		
		case'c':
		case'C':
		PORTC = val ;
		break;
		
		case'd':
		case'D':
		PORTD = val ;
		break;
	}
}

/*--------------------------------------------------------------------------------------------------------------*/

char DIO_readPort (char port)
{
	char x ;
	switch(port)
	{
		case'a':
		case'A':
		x=PINA ;
		break;
		
		case'b':
		case'B':
		x=PINB ;
		break;
		
		case'c':
		case'C':
		x=PINC ;
		break;
		
		case'd':
		case'D':
		x=PIND ;
		break;
    }
	return x;
}

/*--------------------------------------------------------------------------------------------------------------*/
void DIO_toggPort(char port)
{
	switch(port)
	{
		case'a':
		case'A':
		PORTA = ~PORTA ;
		break;
		
		case'b':
		case'B':
		PORTB = ~PORTB ;
		break;
		
		case'c':
		case'C':
		PORTC = ~PORTC ;
		break;
		
		case'd':
		case'D':
		PORTD = ~PORTD ;
		break;
	
	}
}

/*------------------------------------------NIBBLE--------------------------------------------------------------*/

void setLowNibble (char port)
{	
  DIO_setPinDir(port, 0,1) ;
  DIO_setPinDir(port, 1,1) ;
  DIO_setPinDir(port, 2,1) ;
  DIO_setPinDir(port, 3,1) ;	
}

/*--------------------------------------------------------------------------------------------------------------*/

void setHighNibble (char port)
{
	DIO_setPinDir(port, 4,1) ;
	DIO_setPinDir(port, 5,1) ;
	DIO_setPinDir(port, 6,1) ;
	DIO_setPinDir(port, 7,1) ;	
}

/*-------------------------------------------------------------------------------------------------------*/

void writeLowNibble (char port , char val)
{
    DIO_writePin(port,0,READ_BIT(val,0)) ;
    DIO_writePin(port,1,READ_BIT(val,1)) ;
	DIO_writePin(port,2,READ_BIT(val,2)) ;
	DIO_writePin(port,3,READ_BIT(val,3)) ;
}

/*--------------------------------------------------------------------------------------------------------------*/

void writeHighNibble (char port , char val)
{
	DIO_writePin(port,4,READ_BIT(val,0)) ;
	DIO_writePin(port,5,READ_BIT(val,1)) ;
	DIO_writePin(port,6,READ_BIT(val,2)) ;
	DIO_writePin(port,7,READ_BIT(val,3)) ;
}
