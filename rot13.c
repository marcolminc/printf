#include "main.h"


/**
 * _isalpha - checks for alphabetic characters (upper-/lower-case)
 * @c: the character to check
 *
 * Return: 1 -> is alpha, 0 otherwise
 */
int _isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * rot13 - prints a string in rot13'ed fashion
 * @str: the string to print
 *
 * Return: actual number of characters printed
 */
int rot13(char *str)
{
	int i, chars;
	unsigned char c, base;

	chars = 0;
	for (i = 0; str && *(str + i) != '\0'; i++)
	{
		if (!_isalpha(*(str + i)))
		{
			_putchar(*(str + i));
			chars++;
		}
		else
		{
			c = *(str + i);
			base = 'A' + (c >= 'a') * ('a' - 'A');
			_putchar((((c - base) + 13) % 26) + base);
			chars++;
		}
	}
	return (chars);
}
