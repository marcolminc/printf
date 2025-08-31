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
		buf->pos = buf->wr = buf->fwr = 0;
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
	if (!buf->fwr && buf->pos > 0)
	{
		if (write(STDOUT_FILENO, buf->data, buf->pos) != EOF)
			buf->wr += buf->pos, buf->pos = 0;
		else
			buf->fwr = 1;
	}

}


/**
 * free_buff - frees a buffer when no longer needed (_printf closes)
 *
 * @buf: The buffer
 *
 * Return: number of characters so far printed, -1 otherwise
 */
size_t free_buff(Buffer *buf)
{
	size_t res;

	if (!buf->fwr)
		res = buf->wr;
	else
		res = -1;
	free(buf);
	return (res);
}
