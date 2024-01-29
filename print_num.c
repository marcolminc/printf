#include "main.h"

/**
 * print_num - prints an integer, -ve, -ve or 0, return num of digits
 * @ap: the integer to print from va_arg
 * Return: number of digits, '-' sign counted
 */
int print_num(va_list ap)
{
	int num = va_arg(ap, int);
	int numchar = 0;
	int rev_num;

	if (num < 0)
	{
		_putchar('-');
		numchar++;
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		numchar++;
	}
	else
	{
		rev_num = 0;
		while (num > 0)
		{
			rev_num = rev_num * 10 + num % 10;
			num /= 10;
		}
		while (rev_num > 0)
		{
			_putchar('0' + rev_num % 10);
			numchar++;
			rev_num /= 10;
		}
	}
	return (numchar);
}

