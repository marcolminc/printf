#include "main.h"


/**
 * _printf - simplest implementation of custom printf std function
 * @format: the format specifier string
 *
 * Return: number of characters actually printed
 */
int _printf(const char *format, ...)
{
	int i;
	va_list ap;
	Buffer *buf;

	if (!format)
		return (-1);
	buf = buff_init(), va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'c':
					_putchar(buf, va_arg(ap, int));
					continue;
				case 'd': case 'i': case 'b': case 'u': case 'o': case 'x': case 'X':
					print_num(buf, va_arg(ap, int), format[i]);
					continue;
				case 's': case 'r': case 'R': case 'S':
					print_str(buf, va_arg(ap, char *), format[i]);
					continue;
				case 'p':
					print_address(buf, va_arg(ap, void *));
					continue;
				case '%':
					_putchar(buf, '%');
					continue;
				case '\0':
					return (-1);
				default:
					i--;
			}
		}
		if (format[i])
			_putchar(buf, format[i]);
	}
	va_end(ap);
	buff_flush(buf);
	return ((int)free_buff(buf));
}
