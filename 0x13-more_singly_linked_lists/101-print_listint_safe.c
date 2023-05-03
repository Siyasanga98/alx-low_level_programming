#include "lists.h"
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	size_t  index = 0;

	if (nodes == 0)
	{
		for (;head != NULL; nodes++)
	{
		  printf("[%p] %d\n", (void *)head, head->n);
		  head = head->next;
	}
	}

	else
	{
	for (index = 0; index < nodes; index++)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head= head->next;
	}
			printf("-> [%p] %d\n", (void *)head, head->n);
		}

	return (nodes);
}
