#include "lists.h"

/**
 * get_nodeint_at_index - returns the node of linked list.
 * @head: first node of the list.
 * @index: The index of the node
 *
 * Return: the node pointer, or 0
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		if (i == index)
			return (current);
		i++;
		current = current->next;
	}

	return (NULL);
}
