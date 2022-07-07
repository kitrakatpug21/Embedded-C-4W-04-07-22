/*
 * LED_Pattern.c
 *
 * Created: 06-07-2022 11:04:22 AM
 * Author : kartik.iot
 */ 

// CORE Library
#include <avr/io.h>
// Define the operating frequency of the micro-controller (def-1MHZ internal)
#define F_CPU 8000000UL
// include the delay library
#include <util/delay.h>

// Activity
int main(void)
{
    DDRA = 0b11111111;  
	DDRD = 0b11111111;
	while (1) 
    {
		PORTA = 0b10000001; PORTD = 0b11100111;
		_delay_ms(100);
		PORTA = 0b11000011; PORTD = 0b11000011;
		_delay_ms(100);
		PORTA = 0b11100111; PORTD = 0b10000001;
		_delay_ms(100);
		PORTA = 0b11111111; PORTD = 0b00000000;
		_delay_ms(100);
		PORTA = 0b01111110; PORTD = 0b00011000;
		_delay_ms(100);
		PORTA = 0b00111100; PORTD = 0b00111100;
		_delay_ms(100);
		PORTA = 0b00011000; PORTD = 0b01111110;
		_delay_ms(100);
		PORTA = 0b00000000; PORTD = 0b11111111;
		_delay_ms(100);
    }
}



