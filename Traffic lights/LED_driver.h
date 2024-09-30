/*
 * LED_driver.h
 *
 * Created: 9/19/2024 6:06:44 PM
 *  Author: sherif
 */ 


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

void LED_init (char port , char pin);
void LED_turnOn (char port , char pin);
void LED_turnOff (char port , char pin);
void LED_toggle (char port , char pin) ;
char LED_readStatus (char port , char pin);
void LED_initPort (char port) ;


#endif /* LED_DRIVER_H_ */