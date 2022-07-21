/*
 * Ultrasonic Interfacing.c
 *
 * Created: 21-07-2022 10:57:38
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "ultrasonic.h"
#include "LCD8.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char string[10];
	double distance;
	LCD8_init();
	ultrasonic_init();
	while (1) 
    {
		distance = get_distance();
		dtostrf(distance, 2, 2, string);	/* distance to string */
		strcat(string, " cm   ");			/* Concat unit i.e.cm */
		print(0x80,"ULTRASONIC DATA");
		print(0xC0,string);
		_delay_ms(200);
    }
}

