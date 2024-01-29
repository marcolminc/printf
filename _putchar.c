#include "main.h"
#include<unistd.h>


/**
 * _putchar - prints a char to std output
 * @c: the char to be printed
 *
 * Return: integer value for success or failure of writing
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

