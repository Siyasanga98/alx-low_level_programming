#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
*main: - prints the multiplication of two args number
*@argc: argument count
*@argv: argument vector
*Return: Always 0
*/

int main(int argc, char *argv[])
{
	int num1 = 0, num2 = 0;

	if (argc != 3)
	{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	printf("%d\n", num1 * num2);

	return (0);
}
