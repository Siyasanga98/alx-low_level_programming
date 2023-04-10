#include "main.h"
/**
* _strcpy - copies a string
* @dest:  copy to
* @src: copy from
*
* Return: the pointer to destination string
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
