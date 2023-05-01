#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_i - prints integer
 * @list: argument of list
 * @s: separator
 *
 * Return: nothing
 */
void print_i(va_list list, char *s)
{
	printf("%s%d", s, va_arg(list, int));
}

/**
 * print_c - prints character
 * @list: argument of character
 * @sep: separator
 *
 * Return: nothing
 */
void print_c(va_list list, char *sep)
{
	printf("%s%c", sep, va_arg(list, int));
}

/**
 * print_s - prints string
 * @list: argument of string
 * @sep: separator
 *
 * Return: nothing
 */
void print_s(va_list list, char *sep)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(nil)";
	printf("%s%s", sep, s);
}

/**
 * print_f - prints float
 * @list: argument of float
 * @sep: separator
 *
 * Return: nothing
 */
void print_f(va_list list, char *sep)
{
	printf("%s%f", sep, va_arg(list, double));
}

/**
 * print_all - prints all arguments
 * @format: format is a list of types of arguments
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list list;
	char *sep;
	int i, j;
	typ_t fm[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s},
		{NULL, NULL}
	};

	va_start(list, format);
	i = 0;
	sep = "";
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == *(fm[j]).fm)
			{
				fm[j].p(list, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(list);
}

