#include "c2b.h"
#include "lcd.h"

/**
 * @brief [char to binary convertor]
 * @param c [character]
 * @return [binary]
 */
uint8_t c2b(char c)
{
	switch (c)
	{
	case '0':
	{
		return 0b00110000;
	} break;

	case '1':
	{
		return 0b00110001;
	} break;
	case '2':
	{
		return 0b00110010;

	} break;
	case '3':
	{
		return 0b00110011;

	} break;
	case '4':
	{
		return 0b00110100;

	} break;
	case '5':
	{
		return 0b00110101;

	} break;
	case '6':
	{
		return 0b00110110;

	} break;
	case '7':
	{
		return 0b00110111;

	} break;
	case '8':
	{
		return 0b00111000;

	} break;
	case '9':
	{
		return 0b00111001;

	} break;
	case ':':
	{
		return 0b00111010;

	} break;
	}
}