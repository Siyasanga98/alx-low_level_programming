#include"main.h"

/**
* _strspn - Entry point
* @s: to be checked
* @accept: c to match
* Return: number of bytes in the initial segment of s
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i;
	int j;
	int  match;

	for (i = 0; s[i] != '\0'; i++)
	{
		match = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
		{
			count++;
			match = 1;
			break;
		}
		if (match == 0)
		{
			return (count);
		}
		}
		return (count);
	}
}
