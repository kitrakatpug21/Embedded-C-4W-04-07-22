/*
 * LCD_Pointer.c
 *
 * Created: 19-07-2022 05:27:40
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void send_command(uint8_t command)
{
	// Set the LCD RS pin to 0
	PORTC = PORTC & ~(0b00000001);
	// Load Command on the D0-D7 Pin
	PORTD = command;
	// Create a positive edge at EN Pin
	PORTC = PORTC | (0b00000010);
	_delay_ms(100);
	PORTC = PORTC & ~(0b00000010);
	_delay_ms(100);
}
void send_data(char character)
{
	// Set the LCD RS pin to 1
	PORTC = PORTC | (0b00000001);
	// Load Command on the D0-D7 Pin
	PORTD = character;
	// Create a positive edge at EN Pin
	PORTC = PORTC | (0b00000010);
	_delay_ms(100);
	PORTC = PORTC & ~(0b00000010);
	_delay_ms(100);
}

void LCD_Initialize()
{
	// Prelimary step
	_delay_ms(300);
	//1. Setup the LCD in 8-bit mode for 16 character and 2 rows
	send_command(0x38);
	//2. Setup the LCD for Left to RIght Data Shift
	send_command(0x06);
	//3. Setup the LCD Cursor
	send_command(0x0F);// cursor is solid	F- cursor blinky
	//4. Clear the Garbage values in LCD
	send_command(0x01);
	//5. Set the starting Point of the LCD
	send_command(0x80);
}

void print(uint8_t lcdPosition, char* string)
{
	int rem_char, row;
	if (lcdPosition >= 128 && lcdPosition < 144)
	{
		row = 0;
		rem_char = 144-lcdPosition;
	}
	send_command(lcdPosition);
	while (*string != '\0')
	{
		if (rem_char == 0)
		{
			if (row == 0)
			{
				row = 1;
				send_command(0xC0);
			}
			rem_char = rem_char -1;
		}
		send_data(*string);
		string++;
	}
}

int main(void)
{
	DDRC = 0b00000011;
	DDRD = 0b11111111;
	LCD_Initialize();
	while (1)
	{
		//print(0x80, "SHUBHI");
		//print(0xC0, "VASU");
		//print(0x90, "NANDINI");
		//print(0xD0, "DINESH");
		print(0x80, "HELLO THIS IS AN LCD OUTPUT");
	}
}
