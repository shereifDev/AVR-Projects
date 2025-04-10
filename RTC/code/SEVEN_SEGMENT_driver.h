/*
 *  Author: sherif
 */ 


#ifndef SEVEN_SEGMENT_DRIVER_H_
#define SEVEN_SEGMENT_DRIVER_H_

void sevenSeg_init (char port);
void sevenSeg_displayNum (char port , char num);
void BCD_init (char port , char nibble);
void BCD_displayNum (char port , char nipple , char num);


#endif /* 7SEGMENT_DRIVER_H_ */