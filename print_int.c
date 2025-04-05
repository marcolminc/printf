#include "main.h"

/**
 * place_value - finds max place value of a decimal number
 * @n: given number to evaluate
 *
 * Return: the maximum place value of n
 */
int place_value(__int128_t n)
{
	int weight = 1;

	if (n >= 1000000000)
		weight = 1000000000;
	else if (n >= 100000000)
		weight = 100000000;
	else if (n >= 10000000)
		weight = 10000000;
	else if (n >= 1000000)
		weight = 1000000;
	else if (n >= 100000)
		weight = 100000;
	else if (n >= 10000)
		weight = 10000;
	else if (n >= 1000)
		weight = 1000;
	else if (n >= 100)
		weight = 100;
	else if (n >= 10)
		weight = 10;
	else
		weight = 1;

	return (weight);
}


/**
 * print_int - prints the decimal integer n
 * @n: the decimal number to print
 *
 * Return: number of digits (characters) printed
 */
int print_int(int n)
{
	__int128_t num;
	int place, digit, chars;

	chars = 0, num = n;
	if (num < 0)
		_putchar('-'), chars++, num *= -1;
	place = place_value(num);
	while (place > 0)
	{
		digit = num / place;
		_putchar(digit + '0'), chars++;
		num %= place, place /= 10;
	}
	return (chars);
}
