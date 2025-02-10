/*
 *  Author: sherif
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_driver.h"
#include "LCD.h"


void LCD_init(void)
{
	#ifdef eight_bit_mode
	 _delay_ms(200);
	 setPortDir(LCD_DATA_PORT ,0xFF);
	 setPinDIr(LCD_CONTROL_PORT,RS,1);
	 setPinDIr(LCD_CONTROL_PORT,RW,1);
	 setPinDIr(LCD_CONTROL_PORT,EN,1);
	 writePIn(LCD_CONTROL_PORT,RW,0);
	 LCD_sendCmd(EIGHT_BITS);     
	 _delay_ms(1);
	 LCD_sendCmd(DISP_ON_CUR_OFF);    
	 _delay_ms(1);
	 LCD_CLR();            
	 LCD_sendCmd(ENTRY_MODE);     
	 _delay_ms(1);
	 
	#else
	_delay_ms(200);
	setLowNibbleDir(LCD_DATA_PORT ,0xF);
	setPinDIr(LCD_CONTROL_PORT,RS,1);
	setPinDIr(LCD_CONTROL_PORT,RW,1);
	setPinDIr(LCD_CONTROL_PORT,EN,1);
	writePIn(LCD_CONTROL_PORT,RW,0);
	LCD_sendCmd(HOME);      
	_delay_ms(1);
	LCD_sendCmd(FOUR_BITS);    
	_delay_ms(1);           
	LCD_sendCmd(DISP_ON_CUR_OFF);     
	_delay_ms(1);
	LCD_CLR();          
	LCD_sendCmd(ENTRY_MODE);    
	_delay_ms(1);
	#endif
}

//--------------------------------------------------------------------------------------------------------------------------------

void LCD_sendChar (char data)
{
	#ifdef eight_bit_mode
	writePort(LCD_DATA_PORT ,data);
	writePIn(LCD_CONTROL_PORT,RS,1);
	LCD_pulseEnable();
	
	#else
	writeLowNibble(LCD_DATA_PORT ,data>>4);
	writePIn(LCD_CONTROL_PORT,RS,1);
	LCD_pulseEnable();
	writeLowNibble(LCD_DATA_PORT ,data);
	writePIn(LCD_CONTROL_PORT,RS,1);
	LCD_pulseEnable();
	#endif
}

//--------------------------------------------------------------------------------------------------------------------------------

void LCD_sendCmd (char cmd)
{
	#ifdef eight_bit_mode
	 writePort(LCD_DATA_PORT ,cmd);
	 writePIn(LCD_CONTROL_PORT,RS,0);
	 LCD_pulseEnable();
	 
	#else
	writeLowNibble(LCD_DATA_PORT ,cmd>>4);
	writePIn(LCD_CONTROL_PORT,RS,0);
	LCD_pulseEnable();
	writeLowNibble(LCD_DATA_PORT ,cmd);
	writePIn(LCD_CONTROL_PORT,RS,0);
	LCD_pulseEnable();
	#endif
}

//--------------------------------------------------------------------------------------------------------------------------------

void LCD_sendString(char* str)
{
	int i=0;
	while (str[i]!='\0')
	{
		LCD_sendChar(str[i]);
		i++;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void LCD_pulseEnable (void)
{
	writePIn(LCD_CONTROL_PORT,EN,1);
	_delay_ms(2);
	writePIn(LCD_CONTROL_PORT,EN,0);
	_delay_ms(2);
}

//--------------------------------------------------------------------------------------------------------------------------------

void LCD_moveCursor (char row , char col)
{
	if (row == 1)
	{
		LCD_sendCmd(0x80+(col-1));
	}
	else if (row==2)
	{
		LCD_sendCmd(0xC0+(col-1));
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void LCD_CLR(void)
{
	LCD_sendCmd(CLRSCR);
	_delay_ms(10);
}

//--------------------------------------------------------------------------------------------------------------------------------




