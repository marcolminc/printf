#include "main.h"


/**
 * print_num - prints an integer in a given specifier
 * @num: the integer to print
 * @spec: the specifier on how to print the integer
 *
 * Return: number of digits actually printed
 */
int print_num(int num, const char spec)
{
	int digits;

	digits = 0;
	switch (spec)
	{
		case 'd':
		case 'i':
			digits += print_int(num);
			break;

		case 'b':
			digits += print_bin(num);
			break;
		default:
			break;
	}
	return (digits);
}
