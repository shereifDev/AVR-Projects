/*
 *  Author: sherif
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
#include "LCD.h"
#include "switch.h"
#include "EVO.h"


int main(void)
{
	unsigned char A=0,B=0,C=0,D=0 ;
	LCD_init();
	// initialize the buttons and enable the internal pull up
	for (char i=0 ; i<5 ; i++)
	{
		switch_init('D',i);
		pullUpEnable('D',i);
	}
	LCD_sendString("welcome in EVO");
	_delay_ms(1000);
	LCD_CLR();
	LCD_sendString("press any key to");
	LCD_moveCursor(2,1);
	// shift the cursor five times
	for (char i=0 ; i<5 ; i++)
	{
		LCD_sendCmd(SHIFT_CUR_RIGHT);
	}
	LCD_sendString("start");
	//wait for any button to be pressed
	while(switch_read('D',BUTTON_A) && switch_read('D',BUTTON_B) && switch_read('D',BUTTON_C) && switch_read('D',BUTTON_D));
	LCD_CLR();
	// display initial values on screen 
	LCD_moveCursor(1,1);
	LCD_sendString("A=0");	
	LCD_moveCursor(1,13);
	LCD_sendString("B=0");
	LCD_moveCursor(2,1);
	LCD_sendString("C=0");
	LCD_moveCursor(2,13);
	LCD_sendString("D=0");
	
    while(1)
    {
		/*
		
		if any button be pressed .. its counter will be increase and display the new values on screen 
		
		*/
      
	    if (switch_read('D',BUTTON_A)==0)
	   {
		  _delay_ms(150);
		  if (switch_read('D',BUTTON_A)==0)
		  {
			    A++;
				if (A<10)
				{
					LCD_moveCursor(1,3);
					LCD_sendChar(A+48);
				}
				else if(A>=10 && A<100)
				{
					LCD_moveCursor(1,3);
					LCD_sendChar((A/10)+48);
					LCD_sendChar((A%10)+48);
				} 
			}			  
	   }
	   
	   
	   
	   if (switch_read('D',BUTTON_B)==0)
	   {
		   _delay_ms(150);
		   if (switch_read('D',BUTTON_B)==0)
		   {
			   B++;
			   if (B<10)
			   {
				   LCD_moveCursor(1,15);
				   LCD_sendChar(B+48);
			   }
			   else if(B>=10 && B<100)
			   {
				   LCD_moveCursor(1,15);
				   LCD_sendChar((B/10)+48);
				   LCD_sendChar((B%10)+48); 
			   }
		   }		   	  	   
	   }
	   
	   
	   
	   if (switch_read('D',BUTTON_C)==0)
	   {
		   _delay_ms(150);
		  if (switch_read('D',BUTTON_C)==0)
		  {
			  C++;
			  if (C<10)
			  {
				  LCD_moveCursor(2,3);
				  LCD_sendChar(C+48);
			  }
			  else if(C>=10 && C<100)
			  {
				  LCD_moveCursor(2,3);
				  LCD_sendChar((C/10)+48);
				  LCD_sendChar((C%10)+48);
			  }
		  }		  
		   
	   }
	   
	   
	   
		if (switch_read('D',BUTTON_D)==0)
		{
			 _delay_ms(150);
			if (switch_read('D',BUTTON_D)==0)
			{	
				D++;
				if (D<10)
				{
					LCD_moveCursor(2,15);
					LCD_sendChar(D+48);
				}
				else if(D>=10 && D<100)
				{
					LCD_moveCursor(2,15);
					LCD_sendChar((D/10)+48);
					LCD_sendChar((D%10)+48);		
				}
			}			
			
		}
		
		 /*   if the reset button is pressed 
		           it will reset the counters */
		
		 if (switch_read('D',RESET)==0)
		 {
			  _delay_ms(150);
			 if (switch_read('D',RESET)==0)
			 {
				A=B=C=D=0;
				LCD_moveCursor(1,3);
				LCD_sendChar(A+48);
				LCD_sendChar(0x20); 
				LCD_moveCursor(1,15);
				LCD_sendChar(B+48);
				LCD_sendChar(0x20);
				LCD_moveCursor(2,3);
				LCD_sendChar(C+48);
				LCD_sendChar(0x20);
				LCD_moveCursor(2,15);
				LCD_sendChar(D+48);
				LCD_sendChar(0x20); 
			 }	 
		 }
    }
}