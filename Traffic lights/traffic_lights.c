/*
 * traffic_lights.c
 *
 * Created: 28/9/2024 7:46:44 AM
 *  Author: sherif
 */ 

#include "seven_seg_bcd.h"
#include "LED_driver.h"
#define   F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	
	LED_init('C',0);
	LED_init('C',1);
	LED_init('C',2);
	LED_init('C',3);
	LED_init('C',4);
	LED_init('C',5);
	LED_init('C',6);
	LED_init('C',7);
	LED_init('D',0);
	LED_init('D',1);
	LED_init('D',2);
	LED_init('D',3);
	
    while(1)
    {
          LED_turnOn('D',0);
	  LED_turnOn('D',1);
	  _delay_ms(2000);
	  LED_turnOff('D',0);
	  LED_turnOff('D',1);
	  
	  
	  LED_turnOn('C',7);
	  LED_turnOn('D',2);
	  _delay_ms(2000);
	  LED_turnOff('C',7);
	  LED_turnOff('D',2);
	  
	  
	  LED_turnOn('C',6);
	  LED_turnOn('D',3);
	  LED_turnOff('C',5);
	  LED_turnOff('C',0);
	  _delay_ms(2000);
	
	  
   	  LED_turnOn('C',3);
	  LED_turnOn('C',2);
	  _delay_ms(2000);
	  LED_turnOff('C',3);
	  LED_turnOff('C',2);
	
	  LED_turnOn('C',4);
	  LED_turnOn('C',1);
	  _delay_ms(2000);
	  LED_turnOff('C',4);
	  LED_turnOff('C',1);
	  
	  LED_turnOn('C',5);
	  LED_turnOn('C',0);
	  LED_turnOff('C',6);
	  LED_turnOff('D',3);
	  _delay_ms(2000);
	     
    }
}
