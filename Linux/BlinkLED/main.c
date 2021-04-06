/*
 * Blink.c
 *
 * Created: 12/28/2019 3:20:09 AM
 * Author : Saeed Ghorbani
 */

#include <avr/io.h>
#include <avr/sfr_defs.h>

#define F_CPU 1000000UL
#include <util/delay.h>

#define BV(bit)			(1<<(bit))
#define sbi(reg,bit)	reg |= (BV(bit))
#define cbi(reg,bit)	reg &= ~(BV(bit))


int main()
{
    // Replace with your application code
	sbi(DDRB,1);//out LED
	cbi(DDRB,0);//input Key
	sbi(PORTB,0);//pullup

    while (1)
    {
		if(bit_is_clear(PINB,0)){
			sbi(PORTB,1);//LED on
			_delay_ms(250);
			cbi(PORTB,1);//LED off
			_delay_ms(250);
		}
    }
}

