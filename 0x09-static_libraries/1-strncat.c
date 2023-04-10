#include"main.h"

/**
* _strncat - concatenates two strings
*
* @dest: input value
* @src: input value
* @n: input value
*
* Return: pointer to destination string
*/
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)

	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
