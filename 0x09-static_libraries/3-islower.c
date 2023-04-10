#include "main.h"
/**
* islower - checks if a character is a lowercase letter
* @c: the character to check
*
* Return: 1 if c is a lowercase letter, 0 otherwise
*/
int islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}

	else
	{

		return (0);
	}
}
