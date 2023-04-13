#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* strtow - splits a string into words
* @str: the string to split
*
* Return: to array,NULL if str is NULL or empty
*/
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	
	int i;
	int j;
	int k;
	int n = 0;
	int len = strlen(str);
	char **words = NULL;

	for (i = 0; i < len; i++)
	{
	if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
	{
	n++;
	}
	}

	words = (char **) malloc((n + 1) * sizeof(char *));
	if (!words)
	{
	return (NULL);
	}

	k = 0;
	for (i = 0; i < len; i++)
	{
	if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
	{
	for (j = i + 1; j < len && str[j] != ' '; j++);

	words[k] = (char *) malloc((j - i + 1) * sizeof(char));
	if (!words[k])
	{
	for (j = 0; j < k; j++)
	{
		free(words[j]);
	}
	free(words);
	return (NULL);
	}

	strncpy(words[k], &str[i], j - i);
	words[k][j - i] = '\0';
	k++;
	i = j - 1;
	}
	}

	words[k] = NULL;

	return (words);
}
