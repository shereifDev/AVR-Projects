/*
 *  Author: sherif
 */ 



#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define SET_BIT(reg , bit)	reg|=(1<<bit)
#define CLR_BIT(reg , bit)	reg&=(~(1<<bit)) 
#define READ_BIT(reg , bit)   (reg&(1<<bit))>>bit                        //return 1 or 0 
#define TOGG_BIT(reg , bit)	reg^=(1<<bit)

#endif /* STD_MACROS_H_ */