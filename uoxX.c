#include "main.h"

/**
 * octal - prints an integer in octal
 * @n: supplied decimal number
 *
 * Return: number of digits(chars) printed
 */
int octal(unsigned int n)
{
	int numchar;

	numchar = 0;
	if (n >= 8)
		octal(n / 8);
	numchar += _putchar((n % 8) + '0');
	return (numchar);
}


/**
 * hex - prints a decimal number in hex
 * @n: the given decimal number
 * @capital: boolean for whether capital leter or not
 * Return: number of digits printed
 */
int hex(unsigned int n, unsigned int capital)
{
	int numchar;

	numchar = 0;
	if (n >= 16)
		hex((n / 16), capital);
	if (n % 16 < 10)
		numchar += _putchar((n % 16) + '0');
	else
		numchar += _putchar((n % 16) - 10 + ((capital == 1) ? 'A' : 'a'));
	return (numchar);
}


/**
 * uoxX - prints string portion according to specified format specifier
 * @ap: the chars
 * @c: the char for choice
 *
 * Return: number of chars printed
 */
int uoxX(va_list ap, char c)
{
	int numchar;

	numchar = 0;
	switch (c)
	{
		case 'u':
			numchar += print_num(ap);
			break;
		case 'o':
			numchar += octal(va_arg(ap, int));
			break;
		case 'x':
			numchar += hex(va_arg(ap, int), 0);
			break;
		case 'X':
			numchar += hex(va_arg(ap, int), 1);
			break;
		default:
			break;
	}
	return (numchar);
}
