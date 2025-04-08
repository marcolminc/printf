#include "main.h"
#include <limits.h>


/**
 * print_bin - prints a decimal integer in binary form
 * @n: the decimal integer
 *
 * Return: number of (binary) digits actually printed
 */
int print_bin(int n)
{
	int chars, i;
	unsigned int mask;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	chars = 0;
	mask = 1 << (sizeof(int) * CHAR_BIT - 1);
	i = 1;
	while ((size_t)i <= (sizeof(int) * CHAR_BIT) && ((n & mask) == 0))
		i++, n <<= 1;

	for (; (size_t)i <= (sizeof(int) * CHAR_BIT); i++)
	{
		_putchar(n & mask ? '1' : '0');
		chars++;
		n <<= 1;
	}
	return (chars);
}
