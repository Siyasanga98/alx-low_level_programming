#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
* argstostr - Concatenates arguments
* @ac: number of arguments
* @av: contains the arguments
* Return: 0
*/
char *argstostr(int ac, char **av)
{
	int i;
	int j;
	int k = 0;
	int len = 0;
	char *str;
	
	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++) 

		for (j = 0; av[i][j]; j++)
		{
			len++;
		}

	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
	return (NULL);

	for (i = 0; i < ac; i++)

	{
		for (j = 0; av[i][j]; j++)
	{
		str[k] = av[i][j];
		k++;
	}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';
	
	return (str);

	}
