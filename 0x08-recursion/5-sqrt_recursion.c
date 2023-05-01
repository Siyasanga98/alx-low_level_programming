#include "main.h"
#include <stdio.h>

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: square root of no to find
 *
 * Return: Natural square root of n, or -1
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	{
		int square = i * i;

	if (square == n)
		return (i);
	else if (square > n)
		break;
	}

	return (_sqrt_recursion(n - (i - 1)));
}
