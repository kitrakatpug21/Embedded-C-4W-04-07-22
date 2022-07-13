/*
 * DCMotor Switch.c
 *
 * Created: 13-07-2022 11:18:29 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11000011;	// Motor Here
	DDRD = 0b11100000;	// RGB LED here
	while (1) 
    {
		if (PINA & 0b00000001)	// FORWARD
		{
			PORTC = 0b01000001;	// both clock
			PORTD = 0b10000000;	// Blue Color
		}
		else if (PINA & 0b00001000)	// BACKWARD
		{
			PORTC = 0b10000010;	// both anti-clock
			PORTD = 0b01000000;	// Green Color
		}
		else if (PINA & 0b00000010)	// LEFT
		{
			PORTC = 0b10000001;	// M1 clock M2 anti-clock
			PORTD = 0b00100000;	// Red Color
		}
		else if (PINA & 0b00000100)	// RIGHT
		{
			PORTC = 0b01000010;	// M1 anti-clock M2 clock
			PORTD = 0b01100000;	// Yellow Color
		}
		else
		{
			PORTC = 0b00000000;	// all off
			PORTD = 0b11100000;	// White Color
		}
		_delay_ms(100);
    }
}

