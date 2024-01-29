#ifndef MAIN_H
#define MAIN_H


#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_num(va_list ap);
int print_binary(unsigned int n);
int srSR(va_list ap, char c);
int uoxX(va_list ap, char c);


#endif
