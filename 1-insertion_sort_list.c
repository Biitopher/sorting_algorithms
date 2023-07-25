#include "sort.h"

/**
 * free_list - Frees a doubly linked list
 *
 * @list: Pointer to the head of the list
 */
void free_list(listint_t *list)
{
	listint_t *current = list;

	while (current != NULL)
	{
		listint_t *temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 * insertion_sort_list - Sorts doubly linked list in ascending order
 *
 * @list: Pointer to a pointer  of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *temp = current->next;
		listint_t *prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
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
			print_list(*list);
			prev = current->prev;
		}
		current = temp;
	}
}
