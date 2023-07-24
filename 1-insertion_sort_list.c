#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly linked list in ascending order
 *
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->next;
        listint_t *prev = current->prev;

        while (prev != NULL && prev->n > current->n)
        {
            /* Swap the nodes */
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;

            if (current->next != NULL)
                current->next->prev = prev;

            prev->next = current->next;
            current->prev = prev->prev;

            prev->prev = current;
            current->next = prev;

            /* Print the list after swapping */
            print_list(*list);

            prev = current->prev;
        }

        current = temp;
    }
}
