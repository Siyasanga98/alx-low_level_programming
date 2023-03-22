#include "main.h"

/**
 * Write a function that prints the last digit of a number
 * @n: The number to be reated 
 * Return: value of the last digit of number
 * */
int int print_last_digit(int);
{
	int last

	last = n % 10;
	if (last < 0)
	{
	last = last *-1;
	}
	putchar(last + '0');
	return (last);
}
