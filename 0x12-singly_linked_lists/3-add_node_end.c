#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* add_node_end - adds a new node
* @head: double pointer to the head of the list
* @str: string to be added
* Return: the address , NULL if it failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = 0;
	while (new_node->str[new_node->len] != '\0')
		new_node->len++;

	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	}

	return (new_node);
}
