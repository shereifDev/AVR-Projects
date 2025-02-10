/*
*  Author: sherif
*/


#include <avr/io.h>
#define  F_CPU 8000000UL
#include<util/delay.h>
#include "keypad.h"
#include "LCD.h"

int main(void)
{
	LCD_init();
	KEYPAD_init();
	LCD_sendString("ELECTRONIC CALC");
	_delay_ms(1000);
	LCD_moveCursor(2,1);
	LCD_sendString(" made by sherif");
	_delay_ms(1500);
	label :LCD_init();
char arr[7]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED};
char cnt=0;
short res;

while(1)
{
	// get the first number from the user
	do
	{
		arr[cnt] = KEYPAD_getKey();
	} while (arr[cnt] == NOTPRESSED);
	
	if(arr[cnt]=='A' || arr[cnt]=='=' || arr[cnt]=='+' || arr[cnt]=='-' || arr[cnt]=='/' || arr[cnt]=='*')
	{
		goto label;
	}
	else
	{
		LCD_sendChar(arr[cnt]);
		cnt ++ ;
	}
	
	// get the second number
	do
	{
		arr[cnt] = KEYPAD_getKey();
	} while (arr[cnt] == NOTPRESSED);
	
	if(arr[cnt]=='A' || arr[cnt]=='=' || arr[cnt]=='+' || arr[cnt]=='-' || arr[cnt]=='/' || arr[cnt]=='*')
	{
		goto label;
	}
	else
	{
		LCD_sendChar(arr[cnt]);
		cnt ++ ;
	}
	
	// get the operator
	do
	{
		arr[cnt] = KEYPAD_getKey();
	} while (arr[cnt] == NOTPRESSED);
	
	if(arr[cnt]=='A' || arr[cnt]=='=')
	{
		goto label;
	}
	else
	{
		LCD_sendChar(arr[cnt]);
		cnt ++ ;
	}
	
	
	//get the third number
	do
	{
		arr[cnt] = KEYPAD_getKey();
	} while (arr[cnt] == NOTPRESSED);
	
	if(arr[cnt]=='A' || arr[cnt]=='=' || arr[cnt]=='+' || arr[cnt]=='-' || arr[cnt]=='/' || arr[cnt]=='*')
	{
		goto label;
	}
	else
	{
		LCD_sendChar(arr[cnt]);
		cnt ++ ;
	}
	
	// get the fourth number
	do
	{
		arr[cnt] = KEYPAD_getKey();
	} while (arr[cnt] == NOTPRESSED);
	
	if(arr[cnt]=='A' || arr[cnt]=='=' || arr[cnt]=='+' || arr[cnt]=='-' || arr[cnt]=='/' || arr[cnt]=='*')
	{
		goto label;
	}
	else
	{
		LCD_sendChar(arr[cnt]);
		cnt ++ ;
	}
	
	// get the equal operator
	do
	{
		arr[cnt] = KEYPAD_getKey();
	} while (arr[cnt] == NOTPRESSED);
	
	if( arr[cnt]=='=' )
	{
		LCD_moveCursor(2,1);
		LCD_sendChar(arr[cnt]);
		
		// do the suitable operation depend on the entered operator and display the result
		switch(arr[2])
		{
			case '+':
			{
				res = ((arr[1]-48)+((arr[0]-48)*10)) + ((arr[4]-48)+((arr[3]-48)*10));
				if(res>=100 && res<1000)
				{
					LCD_sendChar((res/100)+48);
					LCD_sendChar(((res/10)%10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_sendChar((res/10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if(res<10)
				{
					LCD_sendChar(res+48);
				}
				break;
			}
			
			case '-':
			{
				res = ((arr[1]-48)+((arr[0]-48)*10)) - ((arr[4]-48)+((arr[3]-48)*10));
				if(res>=100 && res<1000)
				{
					LCD_sendChar((res/100)+48);
					LCD_sendChar(((res/10)%10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_sendChar((res/10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if(res<10)
				{
					LCD_sendChar(res+48);
				}
				break;
			}
			
			
			case '*':
			{
				res = ((arr[1]-48)+((arr[0]-48)*10)) * ((arr[4]-48)+((arr[3]-48)*10));
				if(res>=100 && res<1000)
				{
					LCD_sendChar((res/100)+48);
					LCD_sendChar(((res/10)%10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_sendChar((res/10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if(res<10)
				{
					LCD_sendChar(res+48);
				}
				break;
			}
			
			case '/':
			{
				res = ((arr[1]-48)+((arr[0]-48)*10)) / ((arr[4]-48)+((arr[3]-48)*10));
				if(res>=100 && res<1000)
				{
					LCD_sendChar((res/100)+48);
					LCD_sendChar(((res/10)%10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if (res>=10&&res<100)
				{
					LCD_sendChar((res/10)+48);
					LCD_sendChar((res%10)+48);
				}
				else if(res<10)
				{
					LCD_sendChar(res+48);
				}
				break;
			}
		}
	}
	else
	{
		goto label;
	}
	
	// wait until any key is pressed
	do
	{
		arr[cnt] = KEYPAD_getKey();
	} while (arr[cnt]==NOTPRESSED);
	goto label ;
}
    }