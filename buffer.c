#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * buff_init - initializes a buffer data structure for printing to stdout
 *
 * Return: buffer, if successful, NULL otherwise.
 */
Buffer *buff_init()
{
	Buffer *buf;

	buf = malloc(sizeof(Buffer));
	if (buf)
		buf->pos = buf->wr = 0;
	return (buf);
}


/**
 * buff_flush - flushes the buffer incase full
 *
 * @buf: The buffer to possibly flush
 *
 * Return: Nothing
 */
void buff_flush(Buffer *buf)
{
	if (buf->pos > 0)
	{
		write(STDOUT_FILENO, buf->data, buf->pos);
		buf->wr += buf->pos;
		buf->pos = 0;
	}
}


/**
 * free_buff - frees a buffer when no longer needed (_printf closes)
 *
 * @buf: The buffer
 *
 * Return: number of characters so far printed
 */
size_t free_buff(Buffer *buf)
{
	size_t chars_wr;

	chars_wr = buf->wr;
	free(buf);
	return (chars_wr);
}

