#include "lists.h"

/**
 * pop_listint - Deletes the head node of linked list
 * @head: pointer to the head node of the list.
 *
 * Return: The data of deleted head node, otherwise 0.
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int data;

	if (*head == NULL)
		return (0);

	tmp = *head;
	*head = (*head)->next;
	data = tmp->n;
	free(tmp);

	return (data);
}
