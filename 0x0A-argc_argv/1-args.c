#include"main.h"
#include <stdio.h>

/**
* main - Prints the number of arguments passed
* @argc: arg count
* @argv: arg vector
* Return: Always 0
*/
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d", argc - 1);
	return (0);
}
