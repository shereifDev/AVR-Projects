/*
 * DIO.h
 *
 * Created: 9/14/2024 10:22:13 AM
 *  Author: sherif
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_setPinDir (char port , char pin , char dir) ;
void DIO_writePin (char port , char pin , char val) ; 
void DIO_toggPin (char port , char pin);
char DIO_readPin (char port , char pin);
void DIO_setPort (char port , char dir) ;
void DIO_writePort (char port , char val);
char DIO_readPort (char port);
void DIO_toggPort(char port);
void setLowNibble (char port);
void setHighNibble (char port);
void writeLowNibble (char port , char val);
void writeHighNibble (char port , char val);

#endif /* DIO_H_ */