/*
 * STD_macros.h
 *
 * Created: 9/16/2024 1:55:41 PM
 *  Author: sherif
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define SET_BIT(reg , bit)	reg|=(1<<bit)
#define CLR_BIT(reg , bit)	reg&=(~(1<<bit)) 
#define READ_BIT(reg , bit)    (reg>>bit)&1                         //return 1 or 0 
#define TOGG_BIT(reg , bit)	reg^=(1<<bit)

#endif /* STD_MACROS_H_ */
