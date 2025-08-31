#include "main.h"


/**
 * _isalpha - checks for alphabetic characters (upper-/lower-case)
 * @c: the character to check
 *
 * Return: 1 -> is alpha, 0 otherwise
 */
int _isalpha(const char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * rot13 - prints a string in rot13'ed fashion via a buffer
 *
 * @buf: The buffer
 * @str: The string to print
 *
 * Return: Nothing
 */
void rot13(Buffer *buf, const char *str)
{
	int i;
	unsigned char c, base;

	for (i = 0; str && *(str + i) != '\0'; i++)
	{
		if (!_isalpha(*(str + i)))
			_putchar(buf, *(str + i));
		else
		{
			c = *(str + i);
			base = 'A' + (c >= 'a') * ('a' - 'A');
			_putchar(buf, (((c - base) + 13) % 26) + base);
		}
	}
}
