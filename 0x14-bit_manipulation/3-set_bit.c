#include "main.h"
#include <stddef.h>

/**
 * set_bit - Sets the value of a bit to 1 at given index
 * @n: Pointer to the number to change 
 * @index: The index of the bit
 *
 * Return: 1 on sucess, or -1 
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index >= sizeof(unsigned long int) * 8)
		return -1;

	*n |= (1UL << index);
	return 1;
}
