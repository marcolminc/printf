#include "main.h"


/**
 * _printf - simplest implementation of custom printf std function
 * @format: the format specifier string
 *
 * Return: number of characters actually printed
 */
int _printf(const char *format, ...)
{
	int chars, i;
	va_list ap;

	if (!format)
		return (-1);
	va_start(ap, format), chars = 0;
	for (i = 0; format[i] && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'c':
					_putchar(va_arg(ap, int)) ? chars++ : chars;
					continue;
				case 's':
					chars += print_str(va_arg(ap, char *), 's');
					continue;
				case '%':
					_putchar('%') ? chars++ : chars;
					continue;
				default:
					i--;
			}
		}
		_putchar(format[i]) ? chars++ : chars;
	}
	return (chars);
}
