/*
 * Switch.c
 * Created: 07-07-2022 10:41:18 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
   DDRC = 0b11111111;
   DDRA = 0b00000000;
   while (1) 
    {
		if (PINA == 0b00000001)
		{
			PORTC = 0b00000001;
		}
		else if (PINA == 0b00000010)
		{
			PORTC = 0b00000010;
		}
		else if (PINA == 0b00000100)
		{
			PORTC = 0b00000100;
		}
		else if (PINA == 0b00001000)
		{
			PORTC = 0b00001000;
		}
		else if (PINA == 0b00010000)
		{
			PORTC = 0b00010000;
		}
		else if (PINA == 0b00100000)
		{
			PORTC = 0b00100000;
		}
		else if (PINA == 0b01000000)
		{
			PORTC = 0b01000000;
		}
		else if (PINA == 0b10000000)
		{
			PORTC = 0b10000000;
		}
		else
		{
			PORTC = 0b00000000;
		}
    }
}

