#include "main.h"
#include <limits.h>


/**
 * print_bin - prints a decimal integer in binary via a buffer
 *
 * @buf: The buffer
 * @n: The decimal integer
 *
 * Return: Nothing
 */
void print_bin(Buffer *buf, int n)
{
	int i;
	unsigned int mask;

	if (n == 0)
		_putchar(buf, '0');
	mask = 1 << (sizeof(int) * CHAR_BIT - 1);
	i = 1;
	while ((size_t)i <= (sizeof(int) * CHAR_BIT) && ((n & mask) == 0))
		i++, n <<= 1;

	for (; (size_t)i <= (sizeof(int) * CHAR_BIT); i++)
		_putchar(buf, n & mask ? '1' : '0'), n <<= 1;
}
