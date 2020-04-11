/*	Author: phuan033
 *  Partner(s) Name: Karen Gonzalez
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0xEF;

	unsigned char tmpD = 0x00;
	unsigned char tmpB0 = 0x00;
	unsigned char sum = 0x00;
	unsigned char final = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpD = PIND;
	tmpB0 = PINB & 0x01;

	sum = tmpD + tmpB0;

	if((tmpD == 0xFF) && (tmpB0 == 0x01))
	{
		final = 0x02;
	}
	else if(sum >= 70)
	{
		final = 0x02;
	
	}
	else if((sum < 70) && (sum > 5))
	{
		final = 0x04;
	}
	else if(sum < 5)
	{
		final = 0x00;
	}
	else
	{
		final =0x00;
	}

	PORTB = final;	
    }
    return 1;
}
