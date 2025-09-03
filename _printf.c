#include "main.h"



void parse_format(const char *, Buffer *, va_list, Flags *);

/**
 * _printf - simplest implementation of custom printf std function
 * @format: the format specifier string
 *
 * Return: number of characters actually printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	Buffer *buf;
	Flags *flgs;

	if (!format)
		return (-1);
	buf = buff_init(), flgs = init_flags(), va_start(ap, format);
	if (!buf || !flgs)
		return (-1);
	parse_format(format, buf, ap, flgs);
	va_end(ap);
	buff_flush(buf);
	return ((int)free_buff(buf));
}


/**
 * parse_format - parses the format specifier for flags
 *
 * @format: the format string
 * @buf: the printing buffer
 * @ap: the vararg arguments
 * @flgs: the flags data structure
 *
 * Return: Nothing
 */
void parse_format(const char *format, Buffer *buf, va_list ap, Flags *flgs)
{
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{;
			switch (set_flags(flgs, format[++i]) ? format[++i] : format[i])
			{
			case 'c':
				_putchar(buf, va_arg(ap, int));
				continue;
			case 'd': case 'i': case 'b': case 'u': case 'o': case 'x': case 'X':
				print_num(buf, va_arg(ap, int), format[i], flgs);
				continue;
			case 's': case 'r': case 'R': case 'S':
				print_str(buf, va_arg(ap, char *), format[i]);
				continue;
			case 'p':
				print_address(buf, va_arg(ap, void *), flgs);
				continue;
			case '%':
				_putchar(buf, '%');
				continue;
			case '\0':
				buf->fwr = 1;
				break;
			default:
				i--;
			}
		}
		if (format[i])
			_putchar(buf, format[i]);
	}
}
