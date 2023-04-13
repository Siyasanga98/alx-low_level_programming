
#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
*string_nconcat: returns a pointer to allocated string that
*contains concatenation
*@s1:string
*@s2:string
*@n: unsigned integer
*Return:If memory allocation fails, the function returns NULL.
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len_s1 = 0;
	unsigned int len_s2 = 0;
	unsigned int i;
	unsigned int j;
	char *result;

	if (s1 == NULL)
	s1 = "";
	if (s2 == NULL)
	s2 = "";

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);

	if (n >= len_s2)
	n = len_s2;

	result = malloc((len_s1 + n + 1) * sizeof(char));
	if (result == NULL)
	return (NULL);

	for (i = 0; i < len_s1; i++)
	result[i] = s1[i];
	for (j = 0; j < n; j++, i++)
	result[i] = s2[j];
	result[i] = '\0';

	return (result);
}
