#include "main.h"
#include <stdlib.h>

/**
* array_range - creates an array of integers from min to max
* @min: the minimum integer in the array
* @max: the maximum integer in the array
*
* Return: On success, a pointer to the newly created array; On failure, NULL.
*/
int *array_range(int min, int max)
{
	int size;
	int i;
	int *arr;

	if (min > max)
	return (NULL);

	size = max - min + 1;
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
	return (NULL);

	for (i = 0; i < size; i++)
	arr[i] = min + i;

	return (arr);
}
