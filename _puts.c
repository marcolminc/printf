#include "main.h"

/**
 * _puts - prints a string one char at a time, followed by \n
 * @str: the string to be printed
 *
 * Return: number of printed chars
 */
int _puts(char *str)
{
	int numchar = 0;
	char null[] = "(null)";

	if (*str == NULL || *str = 0)
		str = null;
	while (*str != '\0')
	{
		_putchar(*str);
		numchar++;
		str++;
	}

	return (numchar);
}

