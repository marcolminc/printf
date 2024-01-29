#include "main.h"


/**
 * print_binary - prints an unsigned integer in binary
 * @n: the unsigned integer to print
 * Return: the number of digits printed
 */
int print_binary(unsigned int n)
{
	int bits, digits;
	unsigned int mask;

	bits = 0, digits = 0;
	for (mask = 1; mask <= n; mask <<= 1)
	{
		if (n & mask)
			bits++;
	}
	if (bits == 0)
	{
		digits += _putchar('0');
	}
	else
		for (mask >>= 1; mask != 0; mask >>= 1)
			digits += _putchar((n & mask) ? '1' : '0');
	return (digits);
}
