#include "lists.h"

/**
 * free_listint - Frees a linked  list.
 * @head: list to be freed
 *
 * Return: Nothing.
 */
void free_listint(listint_t *head)
{
	listint_t *current_node, *next_node;

	current_node = head;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
