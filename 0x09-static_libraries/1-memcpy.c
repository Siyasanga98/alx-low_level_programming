#include "main.h"
/**
* _memcpy - a function that copies memory area
*
* @dest: storage memory
* @src: memory where it copied
* @n: number of bytes to be copied
*
* Return: copied memory with byted changed
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

	for (i = 0; i < n; i++)
	dest[i] = src[i];

return (dest);
}

