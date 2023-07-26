#include "sort.h"


/**
 * swap - swaps nodes
 * @list: nodes list
 * @node1: first node
 * @node2: second node
 *
 */

void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *current = *list;

	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (!node2->prev)
		*list = node2;

	if (!node1->next)
		*list = node1;
	while (current != NULL)
	{
		current = current->next;
	}
}


/**
* cocktail_sort_list - sorts doubly linked list of integers in ascending order
* @list: nodes list
*
*/

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current = start = *list;

	if (!list || !(*list))
		return;
	do {
		swapped = 0;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap(list, current, current->next);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		end = current;
		swapped = 0;
		current = end;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev, current);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
				current = current->prev;
		}
		start = current;
	} while (swapped);
}
