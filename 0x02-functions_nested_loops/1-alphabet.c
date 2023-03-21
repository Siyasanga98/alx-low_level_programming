#include "main.h"

/**
 * main - prints the alphabet lowecase
 * 
 * Return: Always nothing 
 */
void print_alphabet(void)
{
	char c;

	for(c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}

