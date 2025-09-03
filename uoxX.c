#include "main.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

/**
 * print_unsigned_int - prints an integer as unsigned number via a buffer
 *
 * @buf: The buffer
 * @n: The integer to print
 *
 * Return: Nothing
 */
void print_unsigned_int(Buffer *buf, const int n)
{
	unsigned int num, place;

	num = (unsigned int)n;
	if (num == 0)
	{
		_putchar(buf, '0');
		return;
	}
	place = place_value(num);
	while (place > 0)
	{
		_putchar(buf, (int)(num / place) + '0');
		num %= place, place /= 10;
	}
}


/**
 * print_unsigned_octal - prints an integer as an unsigned octal number
 * via a buffer
 *
 * @buf: The buffer
 * @n: The integer to print
 *
 * Return: Nothing.
 */
void print_unsigned_octal(Buffer *buf, const int n)
{
	unsigned int num, place;

	num = (unsigned int)n;
	if (num == 0)
	{
		_putchar(buf, '0');
		return;
	}
	place = 1;
	while (num / place >= 8)
		place *= 8;
	while (place > 0)
	{
		_putchar(buf, (int)(num / place) + '0');
		num %= place, place /= 8;
	}
}

/**
 * print_unsigned_hex - prints an integer as an unsigned octal number
 * via a buffer
 *
 * @buf: The buffer
 * @n: The integer to print
 * @capital: Specifies whether to capitalize letter digits
 * @pad: Specifies whether to pad with 0 numbers with less than 2 digits
 *
 * Return: Nothing
 */
void print_unsigned_hex(Buffer *buf, const int n, const int capital,
		const int pad)
{
	unsigned int num, place;
	int digit;
	const char *hex_digits;

	num = (unsigned int)n;
	if (num == 0)
	{
		_putchar(buf, '0');
		return;
	}
	if (!capital)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	place = 1;
	while (num / place >= 16)
		place *= 16;
	if (pad && place < 16)
		_putchar(buf, '0');
	while (place > 0)
	{
		digit = (int)(num / place);
		_putchar(buf, hex_digits[digit]);
		num %= place, place /= 16;
	}
}


/**
 * print_address- prints an address in lowercase hex via a buffer
 *
 * @buf: The buffer
 * @addr: The address to print
 * @flgs: The flags object
 *
 * Return: Nothing
 */
void print_address(Buffer *buf, void *addr, Flags *flgs)
{
	int digit;
	const char *hex_digits;
	unsigned long int num, place;

	if (!addr)
	{
		print_str(buf, "(nil)", 's');
		return;
	}
	num = (unsigned long int)addr;
	hex_digits = "0123456789abcdef";
	place = 1;
	if (flgs->plus)
		_putchar(buf, '+');
	print_str(buf, "0x", 's');
	while (num / place >= 16)
		place *= 16;
	while (place > 0)
	{
		digit = (int)(num / place);
		_putchar(buf, hex_digits[digit]);
		num %= place, place /= 16;
	}
}
