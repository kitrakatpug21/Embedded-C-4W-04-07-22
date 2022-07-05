/*
 * LED.c
 *
 * Created: 04-07-2022 11:36:51 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
void delay()
{
	for (long var = 0; var <20000; var++);
}

int main(void)
{
    DDRA = 0b11111111;
	PORTA = 0x00;
	for (int count = 0; count <255 ;count = count+1)
	{
		PORTA = count;
		delay();
	}
	while (1) 
    {
    }
}

