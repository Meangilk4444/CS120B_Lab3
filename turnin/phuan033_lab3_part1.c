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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC - 0x00;

	unsigned char num1 = 0x00;
	unsigned char num2 = 0x00;
	unsigned char num3 = 0x00;
	unsigned char num4 = 0x00;
	unsigned char total = 0x00;
        unsigned char num5 = 0x00;
        unsigned char num6 = 0x00;
        unsigned char num7 = 0x00;
        unsigned char num8 = 0x00;
    /* Insert your solution below */
    while (1) {

	num1 = PINA & 0x01; //0000 00001
	num2 = (PINA & 0x02) >> 1; // 0000 0010
	num3 = (PINA & 0x04) >> 2; // 0000 0100
	num4 = (PINA & 0x08) >> 3; //0000 1000

	total = num1 + num2 + num3 + num4; 
	//upper bit
	num1 = (PINA & 0x10) >> 4;
	num2 = (PINA & 0x20) >> 5;
	num3 = (PINA & 0x40) >> 6;
	num4 = (PINA & 0x80) >> 7;

	total = total + num1 + num2 + num3 + num4;

	num5 = PINB & 0x01;
	num6 = (PINB & 0x02) >> 1;
	num7 = (PINB & 0x04) >> 2;
	num8 = (PINB & 0x08) >> 3;
	
	total = total + num5 + num6 + num7 + num8;                                          
	num5 = (PINB & 0x10) >> 4;                                                          num6 = (PINB & 0x20) >> 5;
        num7 = (PINB & 0x40) >> 6;                                                          num8 = (PINB & 0x80) >> 7;   


	total = total + num5 + num6 + num7 + num8;
	PORTC = total;
    }
    return 1;
}
