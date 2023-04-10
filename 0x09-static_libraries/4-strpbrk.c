#include <stddef.h>
#include"main.h"

/**
* _strpbrk - Entry point
* @s: input
* @accept: input
*
* Return: Always 0 (success)
*/
char *_strpbrk(char *s, char *accept)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (accept[j] != '\0')
	{
		j++;
	}

	if (s[i] == accept[j])
	{
		return (&s[i]);
	}
	return (NULL);
}
