/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: square root number to find
 *
 * Return: the natural square root of n, or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
		{
			return (n);
		}
	else
	{
		int i = 1;

		while (i * i < n)
		{
			i++;
		}
		if (i * i == n)
		{
			return (i);
		}
		else
		{
			return (-1);
		}
	}
}
