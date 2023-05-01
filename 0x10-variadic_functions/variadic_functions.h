#ifndef VARFUNC
#define VARFUNC

/**
 * File: variadic_functions.h
 * Author: <your name>
 * Desc: Header file containing prototypes for all functions
 *       used in the 0x10-variadic_functions project.
 */

#include <stdarg.h>

int _putchar(char);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct typ - Struct operators
 *
 * @c: Char
 * @tp: The function associated
 */
typedef struct typ
{
	char *c;
	void (*tp)(va_list var);
} typ_t;

#endif /* VARFUNC */

