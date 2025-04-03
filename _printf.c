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
	char *str;

	if (!format)
		return (-1);
	chars = 0, va_start(ap, format), str = NULL;
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'c':
					_putchar(va_arg(ap, int)) ? chars++ : chars;
					continue;
				case 's':
					str = va_arg(ap, char *);
					str = str ? str : "(null)";
					while (str && *str != '\0')
						_putchar(*str++) ? chars++ : chars;
					continue;
				case '%':
					_putchar('%') ? chars++ : chars;
					continue;
				case '\0':
					return (-1);
				default:
					i--;
					break;
			}
		}
		if (format[i])
			_putchar(format[i]) ? chars++ : chars;
	}
	return (chars);
}

