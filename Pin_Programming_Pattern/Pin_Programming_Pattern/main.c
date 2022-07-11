/*
 * Pin_Programming_Pattern.c
 *
 * Created: 11-07-2022 11:12:56 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11111111;
	DDRD = 0b11100000;
	while (1) 
    {
		// Pattern-1
		PORTC = 0x00;
		if (PINB & 0b10000000)
		{	PORTD |= 0b10000000;	}
		else
		{	PORTD &= ~(0b10000000);	}
		if (PINB & 0b01000000)
		{	PORTD |= 0b01000000;	}
		else
		{	PORTD &= ~(0b01000000);	}
		if (PINB & 0b00100000)
		{	PORTD |= 0b00100000;	}
		else
		{	PORTD &= ~(0b00100000);	}
		if (PINA & 0b00000001)
		{
			for (int i = 0; i < 8; i = i+1)
			{
				PORTC = PORTC | (0b00000001 << i);
				_delay_ms(50);
			}
			// Pattern-3
			PORTC = 0xFF;
			for (int i = 0; i < 8; i = i+1)
			{
				PORTC = PORTC & ~(0b00000001 << i);
				_delay_ms(50);
			}
		}
		if (PINA & 0b00000010)
		{
			// Pattern-2
			PORTC = 0x00;
			for (int i = 7; i >= 0; i = i-1)
			{
				PORTC = PORTC | (0b00000001 << i);
				_delay_ms(50);
			}
			//Pattern-4
			PORTC = 0xFF;
			for (int i = 7; i >= 0; i = i-1)
			{
				PORTC = PORTC & ~(0b00000001 << i);
				_delay_ms(50);
			}
		}
    }
}

