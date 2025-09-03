#ifndef MAIN_H
#define MAIN_H

/* includes */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


/* definitions */
#define BUFF_LIMIT 1024

/**
 * struct buff_t - a buffer for printing characters to stdout with write()
 *
 * @data: The (array of) characters to print
 * @pos: Current index position to add a new character at
 * @wr: Characters currently successfully written
 * @fwr: Flag for success/failure of writing to stdout
 * Description: The buffer implementation for printing characters to the stdout
 * without using too much sys calls.
 */
typedef struct buff_t
{
	char data[BUFF_LIMIT];
	size_t pos;
	size_t wr;
	size_t fwr;
} Buffer;


/**
 * struct flags_t - a flags structure
 *
 * @plus: + flag - forces sign printing for positive numbers
 * @minus: - flag -
 * @space: adds spaces for defined width
 * @hash: # flag - prepends uxX with 0 or 0x /0X
 * @zero: 0 flag - pads a number with zeros for specified width
 */
typedef struct flags_t
{
	unsigned int plus : 1;
	unsigned int minus : 1;
	unsigned int space : 1;
	unsigned int hash : 1;
	unsigned int zero : 1;
} Flags;


/* prototypes */
Buffer *buff_init();
size_t free_buff(Buffer *);
void buff_flush(Buffer *);

Flags *init_flags();
int set_flags(Flags *, char);

int place_value(__int128_t);
int _printf(const char *, ...);
void _putchar(Buffer *, char);
void print_int(Buffer *b, int, Flags *);
void print_bin(Buffer *, int);
void print_unsigned_int(Buffer *, int);
void print_unsigned_octal(Buffer *, int);
void print_unsigned_hex(Buffer *, int, int, int);
void print_num(Buffer *, int, char, Flags *);
void rot13(Buffer *, const char *);
void print_Str(Buffer *, const char *);
void print_str(Buffer *, char *, char);
void print_address(Buffer *, void *, Flags *);


#endif /* MAIN_H */
