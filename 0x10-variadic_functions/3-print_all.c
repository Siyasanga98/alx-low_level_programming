#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
* print_all - Prints anything
* @format: list of types of arguments passed
* @...:  no of arguments to be printed
*
* Return: void
*/
void print_all(const char * const format, ...)
{
	va_list args;
	char *str, *sep = "";
	int i = 0;
	char c;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
	c = format[i];

	switch (c)
	{
		case 'c':
	printf("%s%c", sep, va_arg(args, int));
	break;
		case 'i':
	printf("%s%d", sep, va_arg(args, int));
	break;
		case 'f':
	printf("%s%f", sep, va_arg(args, double));
	break;
		case 's':
	str = va_arg(args, char *);
	if (str == NULL)
	str = "(nil)";
	printf("%s%s", sep, str);
	break;
	default:
	i++;
	continue;
	}

	sep = ", ";
	i++;
	}

	va_end(args);

	printf("\n");
}
