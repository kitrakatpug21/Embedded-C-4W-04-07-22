/*
 * Seven_Segment_Array.c
 *
 * Created: 06-07-2022 11:48:22 AM
 * Author : kartik.iot
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

uint16_t segment[10]= {0b00111111,
						0b00000110,
						0b01011011,
						0b01001111,
						0b01100110,
						0b01101101,
						0b01111101,
						0b00000111,
						0b01111111,
						0b01101111};

int main(void)
{
	DDRC = 0b01111111;
	DDRD = 0b01111111;
	while (1) 
    {
		/*for(int i = 0; i <= 9 ; i++)
		{	
			for (int j = 0; j <= 9; j++)
			{
				PORTC = segment[i];
				PORTD = segment[j];
				_delay_ms(100);
			}
		}*/
		for(int i = 9; i >= 0 ; i--)
		{
			for (int j = 9; j >= 0; j--)
			{
				PORTC = segment[i];
				PORTD = segment[j];
				_delay_ms(100);
			}
		}
    }
}

