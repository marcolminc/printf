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
		case 'd': case 'i':
			digits += print_int(num);
			break;

		case 'b':
			digits += print_bin(num);
			break;
		case 'u':
			digits += print_unsigned_int(num);
			break;
		case 'o':
			digits += print_unsigned_octal(num);
			break;
		case 'x':
			digits += print_unsigned_hex(num, 0, 0);
			break;
		case 'X':
			digits += print_unsigned_hex(num, 1, 0);
		default:
			break;
	}
	return (digits);
}
