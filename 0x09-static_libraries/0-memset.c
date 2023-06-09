#include "main.h"

/**
* _memset - fills memory with a constant byte
* @s: pointer to the memory area to be filled
* @b: the desired value
* @n: the number of bytes to be changed
*
* Return: a pointer to the filled memory area
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	s[i] = b;

	return (s);
}
