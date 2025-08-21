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
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'c':
					if (_putchar(va_arg(ap, int)) != EOF)
						chars++;
					continue;
				case 's':
					chars += print_str(va_arg(ap, char *), 's');
					continue;
				case '%':
					if (_putchar('%'))
						chars++;
					continue;
				case '\0':
					return (-1);
				default:
					i--;
			}
		}
		if (format[i] && _putchar(format[i]) != EOF)
			chars++;
	}
	va_end(ap);
	return (chars);
}
