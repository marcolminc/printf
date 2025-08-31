#include "main.h"

/**
 * _putchar - custom putchar function using buffer
 * writes the character c to stdout
 *
 * @buf: The buffer
 * @c: The character to print
 *
 * Return: Nothing.
 */
void _putchar(Buffer *buf, const char c)
{
	if (buf->pos >= BUFF_LIMIT)
		buff_flush(buf);
	buf->data[buf->pos++] = c;
}
