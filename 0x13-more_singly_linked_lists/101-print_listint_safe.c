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
    const listint_t *current, *next;
    size_t count = 0;

    if (head == NULL)
        exit(98);

    current = head;

    while (current != NULL)
    {
        count++;
        printf("[%p] %d\n", (void *)current, current->n);
        next = current->next;
        if (next >= current)
        {
            printf("-> [%p] %d\n", (void *)next, next->n);
            exit(98);
        }
        current = next;
    }

    return (count);
}

