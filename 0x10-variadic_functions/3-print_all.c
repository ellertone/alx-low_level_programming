#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_c - prints a char
 * @args: argument list
 */
void print_c(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_i - prints an integer
 * @args: argument list
 */
void print_i(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_f - prints a float
 * @args: argument list
 */
void print_f(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_s - prints a string
 * @args: argument list
 */
void print_s(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
		s = "(nil)";
	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: format string
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *sep = "";
	typ_t types[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s},
		{NULL, NULL}
	};

	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (types[j].c != NULL)
		{
			if (*(types[j].c) == format[i])
			{
				printf("%s", sep);
				types[j].tp(args);
				sep = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}

