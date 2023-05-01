#include "main.h"
#include <stdio.h>

/**
 * _print_rev_recursion - reverse print a string
 * @s: The string to be printed.
 *
 * Return: void.
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;
	_print_rev_recursion(s + 1);
	_putchar(*s);
}
