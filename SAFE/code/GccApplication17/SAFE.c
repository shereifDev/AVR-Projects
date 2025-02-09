/*
 *  Author: sherif
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
#include "LCD.h"
#include "keypad.h"
#include "EEPROM.h"
#include "SAFE.h"
#define NOTPRESSED 0xFF
#define START_ADRESS  0x20
#define STATUS_LOCATION 0x50
#define MAX_TRIES 3
#define GREEN_LED 1
#define RED_LED 0
#define PASSWORD_LENGTH 4




int main(void)
{
	LCD_init();
	KEYPAD_init();
	setPinDIr('D',RED_LED,1);  
	setPinDIr('D',GREEN_LED,1);
	writePIn('D',RED_LED,1);             // Turn on red LED initially
	char arr1[PASSWORD_LENGTH] , arr2[PASSWORD_LENGTH] , val, tries = MAX_TRIES , checkIdenticalFlag=1;

// set the password for the first time 
label: if(EEPROM_read(STATUS_LOCATION) == NOTPRESSED)
       {
			do 
			{
				LCD_CLR();
				LCD_moveCursor(1,3);
				LCD_sendString("set password");
				LCD_moveCursor(2,6);
				
				
			// takes four digits from the user and store it in array 
			for(char i=0 ; i<PASSWORD_LENGTH ; i++)
			{
			  do {
				   arr1[i]= KEYPAD_getKey();
				 }while (arr1[i]== NOTPRESSED);
				   LCD_sendChar(arr1[i]);
				   _delay_ms(300);
				   LCD_sendCmd(SHIFT_CUR_LEFT);
				   LCD_sendChar('*');
			}	 
			LCD_CLR();
			LCD_sendString("confirm the pass");
			LCD_moveCursor(2,6);
			
			
		     // takes four digits for the second time and store in another array 
			for(char i=0 ; i<PASSWORD_LENGTH ; i++)
			{
				do {
			 		arr2[i]= KEYPAD_getKey();
				   }while (arr2[i]== NOTPRESSED);
				LCD_sendChar(arr2[i]);
				_delay_ms(300);
				LCD_sendCmd(SHIFT_CUR_LEFT);
				LCD_sendChar('*');
			}
			
			
			// check .. if two passwords are identical then store it in EEPROM 
			for(char k=0 ; k<PASSWORD_LENGTH ; k++)
			{
				if(arr1[k]==arr2[k])
				{
					continue;
				}
				checkIdenticalFlag=0;
			}
			if(checkIdenticalFlag == 1)
			{
				for (char c=0 ; c<PASSWORD_LENGTH ; c++)         // store the password in EEPROM 
				{
					EEPROM_write(START_ADRESS+c , arr1[c]);
				}
				EEPROM_write(STATUS_LOCATION,0x00);            // write anything accept 0xFF(default val) to avoid entering set-up again 
			}
			
			else
			{
				LCD_CLR();
				LCD_moveCursor(1,2);
				LCD_sendString("not identical!");
				checkIdenticalFlag=1;
				_delay_ms(2000);	
			}
		  }while (EEPROM_read(STATUS_LOCATION)==NOTPRESSED);     //if the passwords are not identical i will stay in the loop
  }				 
	
	
	
	
	while(1)
	{
	    char flag1=1 , flag2=1; 
	    LCD_CLR();
	    LCD_moveCursor(1,2);
		LCD_sendString("enter the pass");
		LCD_moveCursor(2,6);
		
		
		// get the password from the user 
		for(char i=0 ; i<PASSWORD_LENGTH ; i++)
		{
		 do {
			   arr1[i]= KEYPAD_getKey();
			}while (arr1[i]== NOTPRESSED);
			LCD_sendChar(arr1[i]);
			_delay_ms(300);
			LCD_sendCmd(SHIFT_CUR_LEFT);
			LCD_sendChar('*');
			
		}
		
		
		// check .. if the user entered n zeros so it will go to set-up stage 
		for(char j=0 ; j<PASSWORD_LENGTH ; j++)
		{
			if(arr1[j]=='0')
			{
				continue;
			}
			flag2=0;
			
		}
		if (flag2==1)
		{
			EEPROM_write(STATUS_LOCATION,NOTPRESSED);
			goto label;
		}
		
		
		// check if the password is correct or not 	
		for(char i=0 ; i<PASSWORD_LENGTH ; i++)
		{
			
			if (arr1[i] != EEPROM_read(START_ADRESS+i))
			{
				LCD_CLR();
				LCD_moveCursor(1,3);
				LCD_sendString("wrong pass !");
				_delay_ms(1000);
				tries--;                                     // if pass is incorrect you will lose one try  
				LCD_CLR();
				LCD_moveCursor(1,3);
				LCD_sendChar(tries+48);
				LCD_sendString(" tries left");
				_delay_ms(2000);
				flag1=0;                                      // set the flag to zero to try from the beginning
				break;
				
			}
			
		}
		
		
		
		/*
		    if the flag equal one this means that the password is true 
		*/
		
		// if flag equal one the safe will open 
		if (flag1==1)
		{
			writePIn('D',RED_LED,0);               // turn off the red led 
			writePIn('D',GREEN_LED,1);             // turn on the green led
			LCD_CLR();
			LCD_moveCursor(1,4);
			LCD_sendString("verified..");
			_delay_ms(2000);
			LCD_CLR();
			LCD_moveCursor(1,3);
			LCD_sendString("safe opened");
			_delay_ms(2000);
			break;	
		}
		
		
		
		/* 
		verify that the user has not entered the pass incorrectly three times .. if the user entered it three times incorrectly 
		will wait for 9 seconds and then try again 
		*/
		
		if(tries==0)
		{
			LCD_CLR();
			LCD_moveCursor(1,7);
			LCD_sendString("wait");
			LCD_moveCursor(2,8);
			for(char i=9 ; i>0 ; i--)
			{
				LCD_sendChar(i+48);
				_delay_ms(1000);
				LCD_sendCmd(SHIFT_CUR_LEFT);
			}
			tries = MAX_TRIES;                            // reset the tries 
		}				
		
	}
}