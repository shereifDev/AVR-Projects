/*
 *  Author: sherif
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void timer_CTC_init_interrupt(void);

void timer_wave_nonPWM(void);

void timer_wave_fastPWM(void);

void timer_wave_phasecorrectPWM(void);

void timer2_OVF_init_interrupt(void);

#endif /* TIMER_H_ */