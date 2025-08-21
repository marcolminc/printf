#ifndef MAIN_H
#define MAIN_H

/* includes */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* prototypes */
int _putchar(char);
int _printf(const char *format, ...);
int print_str(char *, char);
int print_int(int);
int print_bin(int);
int print_num(int, char);
int place_value(__int128_t);
int print_unsigned_int(int);
int print_unsigned_octal(int);
int print_unsigned_hex(int, int);
int rot13(const char *);


#endif /* MAIN_H */
