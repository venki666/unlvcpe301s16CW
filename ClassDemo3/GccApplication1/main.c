/*
 * GccApplication1.c
 *
 * Created: 2/1/2016 4:49:47 PM
 * Author : venkim
 */ 

//#include <avr/io.h>


/*
 * blinky.c
 *
 * Created: 12/17/2013 11:52:46 PM
 *  Author: venkim
 */ 


#define F_CPU 800000UL

#include <avr/io.h>
#include <util/delay.h>

/*
int main(void){
	DDRC|= (1<<5); // set PC5 as output

	while(1){
		PORTC ^= (1<<5); // toggle the pin

	}
}
*/

/*
// Lesson 2 on 

int main (void)
{
	// set all pins of PORTB for output
	DDRD = 0xFF;

	while (1) {
		// set all pins of PORTB high 
		PORTD = 0xFF;
		_delay_ms(5000);

		// set all pins of PORTB low 
		PORTD = 0x00;
		_delay_ms(5000);
	}
	return 0;
}

*/
		
/*		Lesson 3 
		int main (void)
		{
			// set PORTB for output
			DDRD = 0xFF;
			// set PORTD for input
			DDRB &= 0xFB;
			PORTB |= 0x04;

			while (1) {
				if (PINB & 0x04)
				PORTD &= ~0x20;
				else
				PORTD |= 0x20;
			}
			return 0;
		}

*/


#include <util/delay.h>
#include <avr/io.h>

int main() {
	// Set the pin 5 at port B as output
	DDRB |= (1<<PB5);

	while(1) {
		// Turn led on by setting corresponding bit high in the PORTB register.
		PORTB |= (1<<PB5);

		_delay_ms(10);

		// Turn led off by setting corresponding bit low in the PORTB register.
		PORTB &= ~(1<<PB5);

		_delay_ms(10);

	}
}



/*

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
*/