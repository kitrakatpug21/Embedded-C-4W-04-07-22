/*
 * Seven_segment.c
 *
 * Created: 06-07-2022 11:19:26 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	DDRC = 0b01111111;
	while (1) 
    {
		PORTC = 0b00111111; _delay_ms(1000);// 0
		PORTC = 0b00000110; _delay_ms(1000);// 1
		PORTC = 0b01011011; _delay_ms(1000);// 2
		PORTC = 0b01001111; _delay_ms(1000);// 3
		PORTC = 0b01100110; _delay_ms(1000);// 4
		PORTC = 0b01101101; _delay_ms(1000);// 5
		PORTC = 0b01111101; _delay_ms(1000);// 6
		PORTC = 0b00000111; _delay_ms(1000);// 7
		PORTC = 0b01111111; _delay_ms(1000);// 8
		PORTC = 0b01101111; _delay_ms(1000);// 9
    }
}

