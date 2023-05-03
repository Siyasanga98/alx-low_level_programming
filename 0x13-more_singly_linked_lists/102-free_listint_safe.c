#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to pointer of the head of the list
 *
 * Return: the size of the list that was free'd
 */

size_t free_listint_safe(listint_t **h)
{
    listint_t *current, *next;
    size_t count = 0;

    if (h == NULL || *h == NULL)
        return (0);

    current = *h;
    *h = NULL; /* set head to NULL before freeing */

    while (current != NULL)
    {
        count++;
        next = current->next;
        free(current);
        if (next >= current)
            break;
        current = next;
    }

    return (count);
}
