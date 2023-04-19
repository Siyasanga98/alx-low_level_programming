#include "function_pointers.h"
/**
 * print_name - prints a name
 * @name: pointer to the name to print
 * @f: function pointer to use for printing
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	  if (array == NULL || action == NULL)
	return;

	f(name);
}
