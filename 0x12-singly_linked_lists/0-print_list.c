#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_list - prints all the elements of a list_t list
* @h: pointer head of the list pointer
*
* Return: the number of nodes
*/
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	printf("[%u] %s\n", h->len, (h->str == NULL) ? "(nil)" : h->str);
	count++;
	h = h->next;
	 }

    return (count);
}

