/*
 * LED_driver.h
 *
 * Created: 12/3/2024 11:28:10 PM
 *  Author: sherif
 */ 


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_
void LED_init(char port , char pinNum);
void LED_turnOn(char port,char pinNum);
void LED_turnOff(char port,char pinNum);
void LED_toggle(char port , char pin);

#endif /* LED_DRIVER_H_ */