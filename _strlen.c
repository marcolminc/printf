#include "main.h"

/**
 * _strlen - computes length of a string
 * @s: the string whose length is required
 *
 * Return: string length (number of counted chars)
 */
int _strlen(char *s)
{
	int i, count;

	count = 0;
	for (i = 0; *(s + i) != '\0'; i++)
	{
		count++;
	}
	return (count);
}
