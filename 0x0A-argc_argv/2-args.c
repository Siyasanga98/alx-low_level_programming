#include <stdio.h>
#include "main.h"
/**
* main - Prints all args received 
* @argc: number of arg 
* @argv: array of arg
*/ 
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++) 
	{
		printf("%s\n", argv[i]);
	}
	
	return (0);
}

