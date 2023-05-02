#include "lists.h"

/**
 * sum_listint - calculate sum of list of the data
 * @head: lead node of the list.
 *
 * Return: return the resulting sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
