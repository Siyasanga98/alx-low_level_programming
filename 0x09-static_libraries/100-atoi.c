#include "main.h"
/**
* _atoi - converts a string to an integer
* @s: the string to use
*
* Return:  integer
*/
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	while (s[i])
	{
		if (s[i] == '-')
	{
		sign = -1;
	}
		else if (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
	}
		else if (result > 0)
	{
		break;
	}
		i++;
	}
	return (result * sign);
}
