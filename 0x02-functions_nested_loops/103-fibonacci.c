#include <stdio.h>

/**
 * main - sum of the even-valued terms, followed by a new line.
 *
 * Return: Always 0
 */
int main(void)
{
	int counter = 0;
	long int a = 1;
	long int b = a;
	long int c = a + b;

	while (counter < 4000000)
	{
		if (c % 2 == 0)
		{
			counter += c;
		}
		a = b;
		b = c;
		c = a + b;
	}
	printf("%d\n", counter);
	return (0);
}
