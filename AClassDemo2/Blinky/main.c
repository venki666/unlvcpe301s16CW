/*
 * Blinky.c
 *
 * Created: 2/2/2016 9:15:48 AM
 * Author : venkim
 */ 

#define F_CPU 10000000UL

#include <util/delay.h>
#include <avr/io.h>


int main() {
	// Set the pin 5 at port B as output
	DDRB	|= (1<<DDB5);						// PB5 As Output pin
	PORTB	|= (1<<DDB5);						// PB5 Activate internal pullUp resistor

	// Set the pin 7 at port B as input
	DDRB	&= ~(1<<DDB7);						// PB1 As Input pin
	PORTB	|= 1<<DDB7;							// PB1 Activate internal pullUp resistor
	
	while(1){
		if(PINB & (1<<DDB7) )
		PORTB ^=(1<<DDB5);
		_delay_ms(500);
	}
}