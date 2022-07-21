/*
 * SensorInterfacing-1.c
 *
 * Created: 20-07-2022 05:33:16
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

uint16_t ADC_GetResult()
{
	ADCSRA = ADCSRA | 0b01000000; // ADSC = 1
	while ((ADCSRA & (0b00010000))==0); // until ADIF is zero, wait here and let the result generate
	// once ADCSRA-> ADIF == 1, loop will break and now we can use the result;
	return ADC;
}


int main(void)
{
	DDRC = 0b11111111;
	DDRD = 0b00000011;
    // Analog to Digital Conversion
	ADMUX = 0b01000000; // REF=01, LAR=0, MUX=00000
	ADCSRA = 0b10000110; // ADEN=1, ADSC=0, ADATE=0, ADIF=0, ADIE=0, PS2-0=110 (/64)
    while (1) 
    {
		uint16_t result = ADC_GetResult();
		PORTC = result;
		PORTD = result>>8;
    }
}

