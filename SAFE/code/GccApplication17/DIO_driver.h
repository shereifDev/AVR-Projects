/*
 *  Author: sherif
 */ 


#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

void setPinDIr(char port , char pin , char dir);
void writePIn (char port , char pin , char value);
char readPin (char port , char pin);
void togglePin (char port , char pin);
void setPortDir(char port , char dir);
void writePort(char port , char value);
char readPort (char port);
void setLowNibbleDir (char port , char dir );
void setHighNibbleDir (char port , char dir );
void writeLowNibble(char port , char val);
void writeHighNibble(char port , char val);
void pullUpEnable (char port , char pin);


#endif /* DIO_DRIVER_H_ */