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

	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		_putchar(*str);
		numchar++;
		str++;
	}

	return (numchar);
}

