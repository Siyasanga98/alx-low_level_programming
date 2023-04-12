#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two strings
 * @s1: input one to concat
 * @s2: input two to concat
 *
 * Return: concat of s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	char *result;

    	size_t len1 = 0;
	size_t len2 = 0;
	size_t i = 0;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    len1 = strlen(s1);
    len2 = strlen(s2);

    result = malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        result[i] = s1[i];

    for (i = 0; i < len2; i++)
        result[len1 + i] = s2[i];

    result[len1 + len2] = '\0';

    return (result);
}

