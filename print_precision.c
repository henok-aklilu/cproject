#include "main.h"

/**
 * get_precision - finds precision of output
 * @format: string format
 * @i: integer i
 * @args: arguments to display
 *
 * Return: output precision
 */
int get_precision(const char *format, int *i, va_list args)
{
	int curr_i = *i + 1;
	int prec = -1;

	if (format[curr_i] != '.')
		return (prec);

	prec = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			prec *= 10;
			prec += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			prec = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (prec);
}


