#include "main.h"


/* some prototypes */
int print_normal(char *);
int print_reverse(char *);


/**
 * print_str - prints a string, as specified by a specifier character
 * @str: the string to print
 * @spec: the specifier character
 *
 * Return: number of characters actually printed
 */
int print_str(char *str, const char spec)
{
	int chars;

	chars = 0;
	switch (spec)
	{
		case 's':
			chars += print_normal(str);
			break;
		case 'r':
			chars += print_reverse(str);
			break;
		case 'R':
			chars += rot13(str);
			break;
		default:
			break;
	}
	return (chars);
}


/**
 * print_normal - prints a string in a normal fashion
 * @str: string to print
 *
 * Return: number of characters actually printed
 */
int print_normal(char *str)
{
	int chars;

	chars = 0;
	if (!str)
		str = "(null)";
	while (str && *str != '\0')
		_putchar(*str++) ? chars++ : chars;
	return (chars);
}


/**
 * print_reverse - prints a string in reverse order (fashion)
 * @str: the string to print (in reverse)
 *
 * Return: number of chars actually printed
 */
int print_reverse(char *str)
{
	int chars;
	size_t len;

	chars = 0, len = 0;
	if (str)
	{
		while (*str != '\0')
			str++, len++;
		str--;
		while (len > 0)
			_putchar(*str--), chars++, len--;
	}
	return (chars);
}
