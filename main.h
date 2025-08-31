#ifndef MAIN_H
#define MAIN_H

/* includes */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


/* definitions */
#define BUFF_LIMIT 1024

typedef struct
{
	char data[BUFF_LIMIT];
	size_t pos;
	size_t wr;
}Buffer;


/* prototypes */
Buffer *buff_init();
size_t free_buff(Buffer *);
void buff_flush(Buffer *);

int place_value(__int128_t);
int _printf(const char *, ...);
void _putchar(Buffer *, char);
void print_int(Buffer *buf, int n);
void print_bin(Buffer *, int);
void print_unsigned_int(Buffer *, int);
void print_unsigned_octal(Buffer *, int);
void print_unsigned_hex(Buffer *, int, int, int);
void print_num(Buffer *, int num, char spec);
void rot13(Buffer *, const char *);
void print_Str(Buffer *, const char *);
void print_str(Buffer *, char *, char);
void print_address(Buffer *, void *);
#endif /* MAIN_H */
