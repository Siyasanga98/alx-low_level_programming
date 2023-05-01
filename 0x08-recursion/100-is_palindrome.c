#include "main.h"
#include <stdio.h>
/**
 * _strlen_recursion - returns the length of a string
 * @s: string
 *
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (_strlen_recursion(s + 1) + 1);
}

/**
 * comparator - compares each characters of a string
 * @s: string
 * @len: length of the string
 *
 * Return: 1 or 0
 */
int comparator(char *s, int len)
{
	if (len <= 1)
		return (1);
	else if (*s == *(s + len - 1))
		return (comparator(s + 1, len - 2));
	else
		return (0);
}

/**
 * is_palindrome - detects if a string is a palindrome.
 * @s: string
 *
 * Return: 1 if a palindrome, or 0
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	if (len <= 1)
		return (1);
	else
		return (comparator(s, len));
}
