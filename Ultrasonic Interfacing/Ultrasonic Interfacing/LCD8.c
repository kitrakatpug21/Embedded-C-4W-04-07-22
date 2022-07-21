/*
 * LCD8.c
 *
 * Created: 21-07-2022 10:57:38
 * Author : kartik.iot
 */ 

#include "LCD8.h"
#define COMMAND_DDR		DDRA
#define COMMAND_PORT	PORTA
#define DATA_DDR		DDRC
#define DATA_PORT		PORTC
void send_command(uint8_t command)
{
	// Set the LCD RS pin to 0
	COMMAND_PORT = COMMAND_PORT & ~(0b00000001);
	// Load Command on the D0-D7 Pin
	DATA_PORT = command;
	// Create a positive edge at EN Pin
	COMMAND_PORT = COMMAND_PORT | (0b00000010);
	_delay_ms(100);
	COMMAND_PORT = COMMAND_PORT & ~(0b00000010);
	_delay_ms(100);
}

void send_data(char character)
{
	// Set the LCD RS pin to 1
	COMMAND_PORT = COMMAND_PORT | (0b00000001);
	// Load Command on the D0-D7 Pin
	DATA_PORT = character;
	// Create a positive edge at EN Pin
	COMMAND_PORT = COMMAND_PORT | (0b00000010);
	_delay_ms(100);
	COMMAND_PORT = COMMAND_PORT & ~(0b00000010);
	_delay_ms(100);
}

void LCD8_init()
{
	COMMAND_DDR = 0b00000011;
	DATA_DDR = 0xFF;
	// Preliminary step
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
	send_command(lcdPosition);
	while (*string != '\0')
	{
		send_data(*string);
		string++;
	}
}
