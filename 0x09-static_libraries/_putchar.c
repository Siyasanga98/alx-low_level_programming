#include <unistd.h>

/**
*_putchar - writes
*@c: the character to print
*
*Return: on success 1,otherwise -1 is returned
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
