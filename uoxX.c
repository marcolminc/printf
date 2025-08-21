#include "main.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

/**
 * print_unsigned - prints an integer as unsigned number
 * @n: the integer to print
 *
 * Return: number of digits actually printed
 */
int print_unsigned(const int n)
{
	unsigned int num, place;
	int chars;

	num = (unsigned int)n;
	if (num == 0)
		if (_putchar('0') != EOF)
			return (1);
	chars = 0, place = place_value(num);
	while (place > 0)
	{
		if (_putchar((int)(num / place) + '0') != EOF)
			chars++;
		num %= place, place /= 10;
	}
	return (chars);
}


/**
 * print_unsigned_octal - prints an integer as an unsigned octal number
 * @n: the integer to print
 *
 * Return: number of digits actually printed
 */
int print_unsigned_octal(const int n)
{
	unsigned int num, place;
	int chars;

	num = (unsigned int)n;
	if (num == 0)
		if (_putchar('0') != EOF)
			return (1);
	chars = 0;
	place = 1;
	while (num / place >= 8)
		place *= 8;
	while (place > 0)
	{
		if (_putchar((int)(num / place) + '0') != EOF)
			chars++;
		num %= place, place /= 8;
	}
	return (chars);
}

/**
 * print_unsigned_hex - prints an integer as an unsigned octal number
 * @n: the integer to print
 *
 * Return: number of digits actually printed
 */
int print_unsigned_hex(const int n, const int capital)
{
	unsigned int num, place;
	int chars, digit;
	const char *hex_digits;

	num = (unsigned int)n;
	if (num == 0)
		if (_putchar('0') != EOF)
			return (1);
	if (!capital)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	chars = 0;
	place = 1;
	while (num / place >= 16)
		place *= 16;
	while (place > 0)
	{
		digit = (int)(num / place);
		if (_putchar(hex_digits[digit]) != EOF)
			chars++;
		num %= place, place /= 16;
	}
	return (chars);
}
