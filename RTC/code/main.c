/*
 * main.c
 *
 * Created: 3/30/2025 12:08:22 AM
 *  Author: sherif
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "DIO_driver.h"
#include "SEVEN_SEGMENT_driver.h"
#include "timer.h"
#include "keypad.h"
#include "APP.h"
#include "LED_driver.h"




// clock mode var
volatile uint8_t sec_cnt=0 , min_cnt=0 , hour_cnt=12  ;
uint8_t clock_mode = 1;
// stop watch mode var 
volatile uint8_t sw_sec=0 , sw_min=0 , sw_hour=0 ;
volatile uint8_t sw_mode = 0;      // 0=clock/timer..1=stopwatch
volatile uint8_t sw_running = 0;   // 0=stopped..1=running
// timer mode var
volatile uint8_t timer_sec=0 , timer_min=0 , timer_hour=0 ;
volatile uint8_t timer_mode = 0;   // 0=clock/SW..1=timer


int main(){
	
	/* declare two variables to store the 1st digit and the 2nd digit while setting the clock */
	
	uint8_t _1stDigit , _2ndDigit ;
	
	
	/*________CONFIGURATIONS _______*/
	
	//set clock button 
	setPinDIr('A',PA7,0);
	pullUpEnable('A',PA7);
	//set stop watch mode button
	setPinDIr('A',PA6,0);
	pullUpEnable('A',PA6);
	//set clock mode button 
	setPinDIr('A',PA5,0);
	pullUpEnable('A',PA5);
	// set pause_resume button
	setPinDIr('A',PA4,0);
	pullUpEnable('A',PA4);
	// set timer mode button
	setPinDIr('A',PA3,0);
	pullUpEnable('A',PA3);
	// set the buzzer 
	setPinDIr('A',PA2,1);
	//set seven segments enable buttons
	setPinDIr('C',PC0,1);
	setPinDIr('C',PC1,1);
	setPinDIr('C',PC2,1);
	setPinDIr('C',PC3,1);
	setPinDIr('C',PC4,1);
	setPinDIr('C',PC5,1);
	//initialize the sevenSegment,timer2 and keypad 
	sevenSeg_init('B');
	timer2_OVF_init_interrupt();
	KEYPAD_init();
	// led initialize 
	LED_init('A',PA0);
	LED_init('A',PA1);
	
	
	
while(1){
		
	
		/* CHECK IF SET CLOCK BUTTON IS PRESSED */
		
		if(readPin('A',PA7)==0){
			_delay_ms(50);
			if(readPin('A',PA7)==0){
				if(sw_mode==0 && timer_mode == 0 ){         // make sure it is not working in stop watch/timer mode 
					
			    //get the hours....
				
				do
				{
					_1stDigit = KEYPAD_getKey();
			
				} while (_1stDigit==NOTPRESSED);
				writePIn('C',PC0,1);
				writePIn('C',PC1,1);
				writePIn('C',PC2,1);
				writePIn('C',PC3,1);
				writePIn('C',PC4,1);
				writePIn('C',PC5,0);
				sevenSeg_displayNum('B',(_1stDigit-'0'));
				_delay_ms(50);
				do
				{
					_2ndDigit = KEYPAD_getKey();
			
				} while (_2ndDigit==NOTPRESSED);
				writePIn('C',PC0,1);
				writePIn('C',PC1,1);
				writePIn('C',PC2,1);
				writePIn('C',PC3,1);
				writePIn('C',PC4,0);
				writePIn('C',PC5,1);
				sevenSeg_displayNum('B',(_2ndDigit-'0'));
				_delay_ms(50);
				hour_cnt=((_1stDigit-'0')*10)+(_2ndDigit-'0') ;
				if(hour_cnt>=24) hour_cnt=0;        // make sure the hours is not greater than 24 hour 
		
				//get the minutes.....
		
				do
				{
					_1stDigit = KEYPAD_getKey();
				
				} while (_1stDigit==NOTPRESSED);
				writePIn('C',PC0,1);
				writePIn('C',PC1,1);
				writePIn('C',PC2,1);
				writePIn('C',PC3,0);
				writePIn('C',PC4,1);
				writePIn('C',PC5,1);
				sevenSeg_displayNum('B',(_1stDigit-'0'));
				_delay_ms(50);
				do
				{
					_2ndDigit = KEYPAD_getKey();
				
				} while (_2ndDigit==NOTPRESSED);
				writePIn('C',PC0,1);
				writePIn('C',PC1,1);
				writePIn('C',PC2,0);
				writePIn('C',PC3,1);
				writePIn('C',PC4,1);
				writePIn('C',PC5,1);
				sevenSeg_displayNum('B',(_2ndDigit-'0'));
				_delay_ms(50);
				min_cnt=((_1stDigit-'0')*10)+(_2ndDigit-'0') ;
				if(min_cnt>=60) min_cnt=0;        // make sure the minutes is not greater than 60 min 
			
				//get the seconds.....
			
				do
				{
					_1stDigit = KEYPAD_getKey();
					
				} while (_1stDigit==NOTPRESSED);
				writePIn('C',PC0,1);
				writePIn('C',PC1,0);
				writePIn('C',PC2,1);
				writePIn('C',PC3,1);
				writePIn('C',PC4,1);
				writePIn('C',PC5,1);
				sevenSeg_displayNum('B',(_1stDigit-'0'));
				_delay_ms(50);
				do
				{
					_2ndDigit = KEYPAD_getKey();
					
				} while (_2ndDigit==NOTPRESSED);
				writePIn('C',PC0,0);
				writePIn('C',PC1,1);
				writePIn('C',PC2,1);
				writePIn('C',PC3,1);
				writePIn('C',PC4,1);
				writePIn('C',PC5,1);
				sevenSeg_displayNum('B',(_2ndDigit-'0'));
				_delay_ms(50);
				sec_cnt=((_1stDigit-'0')*10)+(_2ndDigit-'0') ;
				if(sec_cnt>=60) sec_cnt=0;	   // make sure the seconds is not greater than 60 sec  
		}			
	}			
}			
	
	//---------------------------------------------------------------------
	
		// GO INTO STOP WATCH MODE 
		
		if(readPin('A',PA6)==0){
			_delay_ms(50);
			if(readPin('A',PA6)==0){
				sw_mode=1 ;
				sw_running=1;
				timer_mode=0;
				clock_mode=0;
				sw_hour=0;
				sw_min=0;
				sw_sec=0;
			}
					
		}
		
	//---------------------------------------------------------------------		
		
		//GO INTO CLOCK MODE 
		if(readPin('A',PA5)==0){
			_delay_ms(50);
			if(readPin('A',PA5)==0){
				sw_mode=0 ;	
				timer_mode=0;
				clock_mode=1;
			}
		}
				
	//---------------------------------------------------------------------			
						
		// PAUSE AND RESUME STOP WATCH 
		
		if(readPin('A',PA4)==0){
			_delay_ms(80);
			if(readPin('A',PA4)==0){
				sw_running = !sw_running;		// toggle  											
			}				
		}
			
	//---------------------------------------------------------------------	
	
		//GO INTO TIMER MODE
		if(readPin('A',PA3)==0){
			_delay_ms(50);
			if(readPin('A',PA3)==0){
				
				sw_mode=0;
				clock_mode=0;
				
				 //get the hours.....
				 
				 do
				 {
					 _1stDigit = KEYPAD_getKey();
					 
				 } while (_1stDigit==NOTPRESSED);
				 writePIn('C',PC0,1);
				 writePIn('C',PC1,1);
				 writePIn('C',PC2,1);
				 writePIn('C',PC3,1);
				 writePIn('C',PC4,1);
				 writePIn('C',PC5,0);
				 sevenSeg_displayNum('B',(_1stDigit-'0'));
				 _delay_ms(50);
				 do
				 {
					 _2ndDigit = KEYPAD_getKey();
					 
				 } while (_2ndDigit==NOTPRESSED);
				 writePIn('C',PC0,1);
				 writePIn('C',PC1,1);
				 writePIn('C',PC2,1);
				 writePIn('C',PC3,1);
				 writePIn('C',PC4,0);
				 writePIn('C',PC5,1);
				 sevenSeg_displayNum('B',(_2ndDigit-'0'));
				 _delay_ms(50);
				 timer_hour=((_1stDigit-'0')*10)+(_2ndDigit-'0') ;
				 if(timer_hour>=24) timer_min=0;        // make sure the hours is not greater than 24 hour
				 
				 //get the minutes.....
				 
				 do
				 {
					 _1stDigit = KEYPAD_getKey();
					 
				 } while (_1stDigit==NOTPRESSED);
				 writePIn('C',PC0,1);
				 writePIn('C',PC1,1);
				 writePIn('C',PC2,1);
				 writePIn('C',PC3,0);
				 writePIn('C',PC4,1);
				 writePIn('C',PC5,1);
				 sevenSeg_displayNum('B',(_1stDigit-'0'));
				 _delay_ms(50);
				 do
				 {
					 _2ndDigit = KEYPAD_getKey();
					 
				 } while (_2ndDigit==NOTPRESSED);
				 writePIn('C',PC0,1);
				 writePIn('C',PC1,1);
				 writePIn('C',PC2,0);
				 writePIn('C',PC3,1);
				 writePIn('C',PC4,1);
				 writePIn('C',PC5,1);
				 sevenSeg_displayNum('B',(_2ndDigit-'0'));
				 _delay_ms(50);
				 timer_min=((_1stDigit-'0')*10)+(_2ndDigit-'0') ;
				 if(timer_min>=60) timer_min=0;        // make sure the minutes is not greater than 60 min
				 
				 //get the seconds.....
				 
				 do
				 {
					 _1stDigit = KEYPAD_getKey();
					 
				 } while (_1stDigit==NOTPRESSED);
				 writePIn('C',PC0,1);
				 writePIn('C',PC1,0);
				 writePIn('C',PC2,1);
				 writePIn('C',PC3,1);
				 writePIn('C',PC4,1);
				 writePIn('C',PC5,1);
				 sevenSeg_displayNum('B',(_1stDigit-'0'));
				 _delay_ms(50);
				 do
				 {
					 _2ndDigit = KEYPAD_getKey();
					 
				 } while (_2ndDigit==NOTPRESSED);
				 writePIn('C',PC0,0);
				 writePIn('C',PC1,1);
				 writePIn('C',PC2,1);
				 writePIn('C',PC3,1);
				 writePIn('C',PC4,1);
				 writePIn('C',PC5,1);
				 sevenSeg_displayNum('B',(_2ndDigit-'0'));
				 _delay_ms(50);
				 timer_sec=((_1stDigit-'0')*10)+(_2ndDigit-'0') ;
				 if(sec_cnt>=60) timer_sec=0;	   // make sure the seconds is not greater than 60 sec
			 }
			     timer_mode=1;               // turn on timer mode 
				
			}
		
	//---------------------------------------------------------------------
	
		if (timer_mode == 0){
		 writePIn('A',PA2,0);       // turn off the buzzer 	
		}			
	
	//---------------------------------------------------------------------
	                           /* LEDS CONTROL*/
		if(clock_mode==1){
			LED_turnOff('A',PA1);
			LED_turnOff('A',PA0);
		
		}
		if(timer_mode==1){
			LED_turnOff('A',PA0);
			LED_turnOn('A',PA1);
		
		}
		if(sw_mode==1){
			LED_turnOn('A',PA0);
			LED_turnOff('A',PA1);
			
		}
				
	//---------------------------------------------------------------------			
				
		// DISPLAY CURRENT MODE 	
		if(sw_mode==1){
			displayTime(sw_hour,sw_min,sw_sec);
		}else if(timer_mode==1){
			displayTime(timer_hour,timer_min,timer_sec);
		}else {
			displayTime(hour_cnt,min_cnt,sec_cnt);
		}
			
}	
		
}


ISR(TIMER2_OVF_vect)
{
	// for clock mode 
	if (++sec_cnt >= 60){
		sec_cnt=0 ;
		if(++min_cnt >= 60){
			min_cnt=0 ;
			if(++hour_cnt >= 24){
				hour_cnt=0;
			}
		}
	}
	
	//for stop watch mode 
	if(sw_mode==1 && sw_running==1){
		if (++sw_sec >= 60){
			sw_sec=0 ;
			if(++sw_min >= 60){
				sw_min=0 ;
		     	if(++sw_hour >= 24){
					sw_hour=0;
				}
			}
		}
	}		

    //for timer mode 
	    if(timer_mode==1) {
			if(timer_hour>0 || timer_min>0 || timer_sec>0){
				if(timer_sec > 0) {
					timer_sec--;
				}else {
					if(timer_min > 0) {
						timer_min--;
						timer_sec = 59;
					}else {
						if(timer_hour > 0) {
							timer_hour--;
							timer_min = 59;
							timer_sec = 59;
						}
					}
				}
        }else {
	        
	        togglePin('A', PA2);        //toggle the buzzer and led
        }
    }
}