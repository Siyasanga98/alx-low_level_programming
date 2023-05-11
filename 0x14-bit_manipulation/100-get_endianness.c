#include "main.h"

/**
 * get_endianness - Checks if a machine is little or big
 *
 * Return: 0 if big , 1 if little
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *byte = (char *)&num;

	return ((int)*byte);
}
