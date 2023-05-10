#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: number to search
 * @index: The Bit index
 *
 * Return: The bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((n >> index) & 1);
}

int main(void)
{
	unsigned long int num = 42;
	unsigned int bit_index = 3;
	int bit_value = get_bit(num, bit_index);

	if (bit_value == -1)
		printf("Invalid bit index!\n");
	else
		printf("Bit value at index %u: %d\n", bit_index, bit_value);

	return (0);
}
