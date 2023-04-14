#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
* _calloc - allocates memory
 * @nmemb: number of members
 * @size: size of elements
 * Return: pointer to allocated memory or NULL if allocation fails or  0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	
	if (nmemb == 0 || size == 0)
		return (NULL);
	
	ptr = malloc(nmemb * size);
	
	if (ptr == NULL)
	return (NULL);
	
	memset(ptr, 0, nmemb * size);

	return (ptr);
}
