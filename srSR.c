#include "main.h"


/**
 * reverse - prints a string in reverse order
 * @str: the string to print in reverse order
 *
 * Return: number of chars printed
 */
int reverse(char *str)
{
	int len, i, numchar;

	numchar = 0;
	len = _strlen(str);
	for (i = len - 1; i >= 0; i--)
		numchar += _putchar(str[i]);
	return (numchar);
}

/**
 * rot13 - prints a string in rot13 fashion
 * @str: provided string to encode in rot13
 *
 * Return: number of chars printed
 */
int rot13(char *str)
{
	int i, numchar;
	char c;

	numchar = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
			c = ((c - 'a') + 13) % 26 + 'a';
		else if (c >= 'A' && c <= 'Z')
			c = ((c - 'A') + 13) % 26 + 'A';
		numchar += _putchar(c);
	}
	return (numchar);
}

/**
 * non_print - prints non-printable characters from a string
 * @str: the string whose non-printable chars are printed
 * Return: number of chars printed
 */
int non_print(char *str)
{
	int i, numchar;

	numchar = 0, i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
			numchar += _putchar(str[i]);
		else
			numchar += printf("\\x%02X", str[i]);
		i++;
	}
	return (numchar);
}


/**
 * srSR - srSR
 * @ap: ap
 * @c: c
 * Return: number of chars
 */
int srSR(va_list ap, char c)
{
	int numchar;

	numchar = 0;
	switch (c)
	{
		case 's':
			numchar += _puts(va_arg(ap, char *));
			break;
		case 'r':
			numchar += reverse(va_arg(ap, char *));
			break;
		case 'R':
			numchar += rot13(va_arg(ap, char *));
			break;
		case 'S':
			numchar += non_print(va_arg(ap, char *));
			break;
		default:
			break;
	}
	return (numchar);
}
