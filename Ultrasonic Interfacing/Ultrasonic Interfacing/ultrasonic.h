/*
 * ultrasonic.h
 *
 * Created: 21-07-2022 10:57:38
 * Author : kartik.iot
 */ 

#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <avr/interrupt.h>

int TimerOverflow = 0;
ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

void ultrasonic_init()
{
	DDRB |= 0x01;				/* Make trigger pin as output */
	PORTD |= 0xFF;				/* Turn on Pull-up */
	sei();						/* Enable global interrupt */
	TIMSK = (1 << TOIE1);		/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;					/* Set all bit to zero Normal operation */
}

double get_distance()
{
	/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	PORTB |= (1 << PB0);
	_delay_us(10);
	PORTB &= ~(1 << PB0);
	
	TCNT1 = 0;				/* Clear Timer counter */
	TCCR1B = 0x41;			/* Capture on rising edge, No prescaler*/
	TIFR = 1<<ICF1;			/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;			/* Clear Timer Overflow flag */

	/*Calculate width of Echo by Input Capture (ICP) */
	while ((TIFR & (1 << ICF1)) == 0);		/* Wait for rising edge */
	TCNT1 = 0;				/* Clear Timer counter */
	TCCR1B = 0x01;			/* Capture on falling edge, No prescaler */
	TIFR = 1<<ICF1;			/* Clear ICP flag (Input Capture flag) */
	TIFR = 1<<TOV1;			/* Clear Timer Overflow flag */
	TimerOverflow = 0;		/* Clear Timer overflow count */

	while ((TIFR & (1 << ICF1)) == 0);		/* Wait for falling edge */
	long count = ICR1 + (65535 * TimerOverflow);	/* Take count */
	/* 8MHz Timer freq, sound speed =343 m/s */
	return (double)count / 466.47;
}

#endif