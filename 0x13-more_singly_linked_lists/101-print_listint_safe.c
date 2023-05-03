#include "lists.h"
/**
 * print_listint_safe - Prints a linked list of integers.
 * @head: A pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t count = 0;

    while (fast && fast->next)
    {
        printf("[%p] %d\n", (void *) slow, slow->n);
        count++;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            printf("[%p] %d\n", (void *) slow, slow->n);
            count++;
            break;
        }
    }

    while (head && (!fast || !fast->next))
    {
        printf("[%p] %d\n", (void *) head, head->n);
        count++;
        head = head->next;
    }

    if (!head)
    {
        free_listint_safe((listint_t **) &head);
        exit(98);
    }

    return (count);
}

