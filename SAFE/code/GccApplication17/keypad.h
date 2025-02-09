/*
 *  Author: sherif
 */ 



#ifndef KEYPAD_H_
#define KEYPAD_H_


char KEYPAD_getKey(void);
void KEYPAD_init(void);

//--------------^-^--------------------

#define KEYPAD_PORT 'C'
#define KEYPAD_PIN  PINC
#define R1  0
#define R2  1
#define R3  2
#define R4  3
#define C1  4
#define C2  5
#define C3  6

#endif /* KEYPAD_H_ */