/*
 * Pin_Programming.c
 *
 * Created: 11-07-2022 10:42:25 AM
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
		if (PINA & 0b00000001)
		{		PORTC = PORTC | 0b00000001;		}
		else
		{		PORTC = PORTC & 0b11111110;		}
		if (PINA & 0b00000010)
		{		PORTC = PORTC | 0b00000010;		}
		else
		{		PORTC = PORTC & 0b11111101;		}
		if (PINA & 0b00000100)
		{		PORTC = PORTC | 0b00000100;		}
		else
		{		PORTC = PORTC & 0b11111011;		}
		if (PINA & 0b00001000)
		{		PORTC = PORTC | 0b00001000;		}
		else
		{		PORTC = PORTC & 0b11110111;		}
		if (PINA & 0b00010000)
		{		PORTC = PORTC | 0b00010000;		}
		else
		{		PORTC = PORTC & 0b11101111;		}
		if (PINA & 0b00100000)
		{		PORTC = PORTC | 0b00100000;		}
		else
		{		PORTC = PORTC & 0b11011111;		}
		if (PINA & 0b01000000)
		{		PORTC = PORTC | 0b01000000;		}
		else
		{		PORTC = PORTC & 0b10111111;		}
		if (PINA & 0b10000000)
		{		PORTC = PORTC | 0b10000000;		}
		else
		{		PORTC = PORTC & 0b01111111;		}
    }
}

