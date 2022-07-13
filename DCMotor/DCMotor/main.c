/*
 * DCMotor.c
 *
 * Created: 13-07-2022 10:48:25 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11000011;
	while (1) 
    {
		PORTC = 0b00000001;	//motor1 on (clock)
		_delay_ms(1000);
		PORTC = 0b01000000;	//motor 2 on (clock)
		_delay_ms(1000);
		PORTC = 0b00000010; // motor 1 on (anti-clock)
		_delay_ms(1000);
		PORTC = 0b10000000;	// motor 2 on (anti-clock)
		_delay_ms(1000);
		PORTC = 0b00000000;	// all off
		_delay_ms(1000);
		PORTC = 0b10000010;	// both anti-clock
		_delay_ms(1000);
		PORTC = 0b01000001;	// both anti-clock
		_delay_ms(1000);
		PORTC = 0b00000000;	// all off
		_delay_ms(1000);
    }
}

