/*
 * Seven Segment using switch (Debouncing).c
 *
 * Created: 12-07-2022 11:15:57 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

uint8_t segment[10]= {0b00111111,0b00000110,0b01011011,0b01001111,
						0b01100110,0b01101101,0b01111101,0b00000111,
						0b01111111,0b01101111};

int main(void)
{
	DDRC = 0b01111111;
	int count = 0, wait = 0;
	while (1) 
    {
		wait = 0;
		if (PINA & 0b00000001)
		{
			// debouncer statement
			while (PINA & 0b00000001)
			{
				wait = wait + 1;
				_delay_ms(300);
			}
			if(wait < 3)
			{
				if (count == 9)
				{	count = 0;	}
				else
				{	count = count + 1;	}
			}
			else
			{
				if (count == 0)
				{	count = 9;	}
				else
				{	count = count - 1;	}
			}
		}
		
		PORTC= segment[count];
	}
}
