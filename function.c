#include "main.h"

/**
 * print_char - prints a single character
 * @args: List of arguments
 * @buffer: stores the Buffer
 * @flags: finds the flags
 * @width: stores the field width
 * @prec: precision of the output
 * @size: size of the output
 *
 * Return: the length of the output
 */
int print_char(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	char c;

	c = va_arg(args, int);
	return (handle_write_char(c, buffer, flags, width, prec, size));
}


/**
 * print_string - prints string of characters
 * @args: a list containing all arguments
 * @buffer: stores the buffer
 * @flags: finds the flag specifiers
 * @width: the field width
 * @prec: precision if the output
 * @size: size of the output
 *
 * Return: length of output
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prec >= 0 && prec < length)
		length = prec;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}


/**
 * print_percent - displays the percent sign
 * @args: contains all arguments
 * @buffer: stores the buffer
 * @flags: flag specifications
 * @width: field width of output
 * @prec: precision of the output
 * @size: output size
 *
 * Return: output length
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	return (write(1, "%%", 1));
}


/**
 * print_int - prints integer number
 * @args: argument list of va_list
 * @buffer: stores the buffer
 * @flags: output flag
 * @width: width of output
 * @prec: output precision
 * @size: size of output
 *
 * Return: output length
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, prec, size));
}


/**
 * print_binary - displays u_int number in binary format
 * @args: argument list
 * @buffer: stores the buffer array
 * @flags: output flags
 * @width: field width
 * @prec: output precision
 * @size: output size
 *
 * Return: length of output that got printed.
 */
int print_binary(va_list args, char buffer[],
	int flags, int width, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	n = va_arg(args, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
