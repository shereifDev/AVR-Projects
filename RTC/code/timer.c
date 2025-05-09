/*
 *  Author: sherif
 */ 
 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"


void timer_CTC_init_interrupt(void)
{
	// select CTC mode
	SET_BIT(TCCR0,WGM01);
	// load a value in OCR0 
	OCR0=78;
	// select timer clock 
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// enable interrupt
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,OCIE0);
	 
}


void timer_wave_nonPWM(void)
{
	// set OC0 as output pin 
	SET_BIT(DDRB,3);
	// select CTC mode
	SET_BIT(TCCR0,WGM01);
	// load a value in OCR0 
	OCR0=64;
	// select timer clock 
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// toggle OC0 on compare match
	SET_BIT(TCCR0,COM00);
}

void timer_wave_fastPWM(void)
{
	// set OC0 as output pin 
	SET_BIT(DDRB,3);
	// select fast PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	// load a value in OCR0 
	OCR0=255;
	// select timer clock 
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	// Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void timer_wave_phasecorrectPWM(void)
{
	// set OC0 as output pin 
	SET_BIT(DDRB,3);
	// select phase correct PWM mode
	SET_BIT(TCCR0,WGM00);
	// load a value in OCR0 
	OCR0=64;
	// select timer clock 
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void timer2_OVF_init_interrupt(void)
{
	// clocked from a crystal oscillator
	SET_BIT(ASSR,AS2);
	// select prescaler 128 
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	// enable interrupt 
	SET_BIT(TIMSK,TOIE2);
	sei();
}
