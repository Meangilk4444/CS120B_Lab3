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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTC = 0x00;
	DDRC = 0xFF; PORTC - 0x00;

	unsigned char upperA = 0x00;
	unsigned char lowerA = 0x00;
	unsigned char lowerB = 0x00;
	unsigned char upperC = 0x00;
    /* Insert your solution below */
    while (1) {
	upperA = (PINA & 0xFF) >> 4;
	lowerA = PINA & 0x0F;

	//upper goes to lower PORTB
	lowerB = upperA;
	PORTB = lowerB;

	//lower goes to upper PORTC
	upperC = (lowerA << 4);
	PORTC = upperC;
    }
    return 1;
}
