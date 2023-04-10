#include"main.h"
#include <stddef.h>

/**
* _strchr - This is the entry point
*
* @s: to be searched
* @c: character to be found
*
* Return: pointer to the first occurrence, or NULL if not found
*/
char *starter(char *s, char c)
{
	while (*s != c && *s != '\0')
		s++;

	return (*s == c ? s : NULL);
}
