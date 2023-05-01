/**
 * is_prime_number - checks if the number is prime
 * @n: integer to be check
 * Return: 1 if prime,or 0
 */
int is_prime_number(int n)
{
	int i;

	if (n < 2)
		return (0);

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			return (0);
	}

	return (1);
}
