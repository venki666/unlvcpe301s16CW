/*
 * ReadInput.c
 *
 * Created: 2/1/2016 9:45:11 PM
 * Author : venkim
 */ 

#define F_CPU 8000000UL    //This says to the compiler at what frequency our Atmega is running, in this case its 16Mhz

#include <avr/io.h>        //This is our usual include
#include <util/delay.h>        //The delay functions/routines

uint8_t readButton(void);    //Declaration of the readButton function

int main(void){
	DDRB &= ~(1<<PB7);    //Configure PORTB pin 7 as an input
	PORTB |= (1<<PB7);    //Activate pull-ups in PORTB pin 7
	DDRB |= (1<<PB5);    //Configure PORTB pin 5 an output
	
	while(1){                //Infinite loop
		if(readButton()==1){        //Verify the button state
			PORTB ^=(1<<PB5);    //This is the above mentioned XOR that toggles the led
		}
		_delay_ms(25);            //Delay between consecutive button presses
	}
}

uint8_t readButton(void){
	if((PINB & (1<<PB7)) == 0){        //If the button was pressed
	_delay_ms(25); }        //Debounce the read value
	if((PINB & (1<<PB7)) == 0){        //Verify that the value is the same that what was read
	return 1; }            //If it is still 0 its because we had a button press
	else{                    //If the value is different the press is invalid
	return 0; }
	
}