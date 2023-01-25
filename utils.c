#include "main.h"

/**
 * is_printable - checks for printable character
 * @c: the char to check printability
 *
 * Return: 1 for printable, 0 for non printable
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - appends hexadecimal code
 * @buffer: character array
 * @i: the starting point of appending
 * @ascii_code: code in ASSCI format
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a character is a number
 * @c: character to check
 *
 * Return: 1 if number, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= 48 && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - converts size
 * @num: number to convert
 * @size: the size of the converted
 *
 * Return: converted number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - converts size
 * @num: number to convert
 * @size: size of the converted
 *
 * Return: converted number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
