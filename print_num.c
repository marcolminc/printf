#include "main.h"


/**
 * print_num - prints an integer in a given specifier via a buffer
 *
 * @buf: The buffer
 * @num: The integer to print
 * @spec: The specifier on how to print the integer
 *
 * Return: Nothing
 */
void print_num(Buffer *buf, const int num, const char spec)
{
	switch (spec)
	{
		case 'd':
		case 'i':
			print_int(buf, num);
			break;
		case 'b':
			print_bin(buf, num);
			break;
		case 'u':
			print_unsigned_int(buf, num);
			break;
		case 'o':
			print_unsigned_octal(buf, num);
			break;
		case 'x':
			print_unsigned_hex(buf, num, 0, 0);
			break;
		case 'X':
			print_unsigned_hex(buf, num, 1, 0);
			break;
		default:
			break;
	}
}
