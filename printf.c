#include "main.h"


/**
 * _printf - prints a string according to provided format specifiers
 * @format: the format for printing
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int numchar, i;
	va_list ap;
	char c;

	numchar = 0, va_start(ap, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++, c = format[i];
			if (c == 'd' || c == 'i')
				numchar += print_num(ap);
			else if (c == 'c')
				numchar += _putchar(va_arg(ap, int));
			else if (c == 'b')
				numchar += print_binary(va_arg(ap, unsigned int));
			else if (c == 's' || c == 'r' || c == 'R' || c == 'S')
				numchar += srSR(ap, format[i]);
			else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'p')
				numchar += uoxX(ap, format[i]);
			else if (c == '%')
				numchar += _putchar('%');
			else if (c == '\0')
				return (numchar);
			else
			{
				numchar += _putchar('%');
				numchar += _putchar(format[i]);
			}
		}
		else
			numchar += _putchar(format[i]);
	}
	va_end(ap);
	return (numchar);
}
