#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
*_strdup - duplicate to new memory space location
*@str: pointer to the string to duplicate
*Return: on success, returns a pointer to the duplicated string
*otherwise NULL
*/
char *_strdup(char *str)
{
	char *new_str;
	int len;

	if (str == NULL)
	return (NULL);
	for (len = 0; str[len] != '\0'; len++)
	;
	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
	{
	return (NULL);
	}
	return (new_str);

}
