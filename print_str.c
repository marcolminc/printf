#include "main.h"


/**
 * print_str - prints a string
 * @str: the string to print
 *
 * Return: number of characters actually printed
 */
int print_str(char *str)
{
	int chars;

	chars = 0;
	if (!str)
		str = "(null)";
	while (str && *str != '\0')
		_putchar(*str++) ? chars++ : chars;
	return (chars);
}
