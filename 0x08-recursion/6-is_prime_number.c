#include "main.h"
#include <stdio.h>
/**
 * check_prime - checks if a number is a prime number
 * @n: the number to check
 * @i: the current divisor to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int check_prime(int n, int i)
{
	if (n <= 2)
	{
		return (n == 2);
	}
	else if (n % i == 0)
	{
		return (0);
	}
	else if (i * i > n)
	{
		return (1);
	}
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if an input integer is a prime number
 * @n: the integer to check
 *
 * Return: 1 if the integer is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (check_prime(n, 2));
}
