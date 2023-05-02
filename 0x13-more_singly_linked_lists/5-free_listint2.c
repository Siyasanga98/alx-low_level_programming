#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list
 * @head: A pointer to the head of the list.
 *
 * Return: Nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *current_node, *next_node;

	current_node = *head;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*head = NULL;
}
