#include "sort.h"


/**
 * swap_nodes - swaps nodes
 * @list: nodes list
 * @node1: first node
 * @node2: second node
 * 
 */
 
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *tmp_prev = node1->prev;
	listint_t *tmp_next = node1->next;

    if (!node1 || !node2 || node1 == node2)
        return;

    if (node1->prev)
        node1->prev->next = node2;
    if (node2->prev)
        node2->prev->next = node1;

    if (node1->next)
        node1->next->prev = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->prev = node2->prev;
    node1->next = node2->next;

    node2->prev = tmp_prev;
    node2->next = tmp_next;

    if (*list == node1)
        *list = node2;
    else if (*list == node2)
        *list = node1;
}

/**
* cocktail_sort - sorts a doubly linked list of integers in ascending order
* @list: nodes list
* 
*/

void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start = *list;
    listint_t *end = NULL;
    listint_t *current = start;
    
    if (!list || !*list || !(*list)->next)
        return;

    do {
        swapped = 0;

        while (current->next != end)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            } else
            {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        end = current;

        swapped = 0;

        while (current->prev != start)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list); 
            } else {
                current = current->prev;
            }
        }

        start = current;
    }
    while (swapped);
}

listint_t *create_node(int value)
{
    listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
    if (!new_node)
    {
    new_node->next = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    }
    return new_node;
}
