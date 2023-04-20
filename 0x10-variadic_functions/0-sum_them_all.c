#include "variadic_functions.h"
#include <stdarg.h>

/**
* sum_them_all - calculate  the sum of all its parameters
* @n: The no of parameters
* @...: rguments to be summed
* Return: The sum
*/
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum = 0;
	unsigned int i;

	if (n == 0)
	return (0);

	va_start(args, n);

	for (i = 0; i < n; i++)
	sum += va_arg(args, int);

	va_end(args);

	return (sum);
}
