/*
 * BlinkLED.c
 *
 * Created: 4/6/2021 10:55:23 AM
 * Author : Saeed Ghorbani
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define BV(bit)			(1<<(bit))
#define cbi(reg,bit)	reg &= ~(BV(bit))
#define sbi(reg,bit)	reg |= (BV(bit))

int main(void)
{
    /* Replace with your application code */
	
	cbi(DDRB,0);	//PushButton
	sbi(DDRB,1);    //LED
	sbi(PORTB,0);	//Enable PullUp
	cbi(PORTB,1);	//LED Off
	
    while (1) 
    {
		if(bit_is_clear(PINB,0))
		{
			sbi(PORTB,1);	//LED On
			_delay_ms(250); //Wait 250ms
			cbi(PORTB,1);	//LED Off
			_delay_ms(250);	//Wait 250ms
		}
			
    }
}

