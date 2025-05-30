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
	chars = 0, va_start(ap, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
			switch (format[++i])
			{
				case 'c':
					_putchar(va_arg(ap, int)) ? chars++ : chars;
					continue;
				case 's': case 'r': case 'R':
					chars += print_str(va_arg(ap, char *), format[i]);
					continue;
				case '%':
					_putchar('%') ? chars++ : chars;
					continue;
				case 'd': case 'i':
					chars += print_int(va_arg(ap, int));
					continue;
				case 'b':
					chars += print_bin(va_arg(ap, int));
					continue;
				case '\0':
					return (-1);
				default:
					i--;
			}
		if (format[i])
			_putchar(format[i]) ? chars++ : chars;
	}
	return (chars);
}
