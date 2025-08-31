#include "main.h"
#include <stddef.h>

/* prototypes */
void print_normal(Buffer *, char *);
void print_reverse(Buffer *, char *);


/**
 * print_str - prints a string, as specified by a specifier character
 * via a buffer
 *
 * @buf: The buffer
 * @str: The string to print
 * @spec: The specifier character
 *
 * Return: Nothing.
 */
void print_str(Buffer *buf, char *str, const char spec)
{
	switch (spec)
	{
		case 's':
			print_normal(buf, str);
			break;
		case 'r':
			print_reverse(buf, str);
			break;
		case 'R':
			rot13(buf, str);
			break;
		case 'S':
			print_Str(buf, str);
			break;
		default:
			break;
	}
}


/**
 * print_normal - prints a string in a normal fashion via a buffer
 *
 * @buf: The buffer
 * @str: String to print
 *
 * Return: Nothing
 */
void print_normal(Buffer *buf, char *str)
{
	if (!str)
		str = "(null)";
	while (str && *str != '\0')
		_putchar(buf, *str++);
}


/**
 * print_reverse - prints a string in reverse order (fashion)
 * via a buffer
 *
 * @buf: The buffer
 * @str: The string to print (in reverse)
 *
 * Return: Nothing
 */
void print_reverse(Buffer *buf, char *str)
{
	size_t len;

	len = 0;
	if (str)
	{
		while (*str != '\0')
			str++, len++;
		str--;
		while (len > 0)
			_putchar(buf, *str--), len--;
	}
}


/**
 * print_Str - prints a string while rendering non-printable characters
 * as their 0-padded hex values, via a buffer
 *
 * @buf: The buffer
 * @str: The string to print
 *
 * Return: Nothing
 */
void print_Str(Buffer *buf, const char *str)
{
	char c;

	while (str && *str != '\0')
	{
		c = *str++;
		if ((c > 0 && c < 32) || c >= 127)
		{
			print_normal(buf, "\\x");
			print_unsigned_hex(buf, c, 1, 1);
		}
		else
			_putchar(buf, c);
	}
}
