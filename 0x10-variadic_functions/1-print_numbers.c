#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

/**
* print_numbers - Prints given numbers
* @separator: The string to be printed
* @n: The numbers passed
* @...: number of arguments to be printed
* Return: void
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	
	va_start(args, n);
	
	for (i = 0; i < n; i++)
	{
	printf("%d", va_arg(args, int));

	if (separator != NULL && i != n - 1)
	printf("%s", separator);
	}

	va_end(args);

	printf("\n");
}
