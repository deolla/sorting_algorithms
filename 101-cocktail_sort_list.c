#include "sort.h"

/**
* cocktail_sort_list - Sorts a doubly linked list of integers.
* @list: Pointer to the pointer of the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *left = NULL, *right = NULL;

	if (list == NULL || *list == NULL)
		return;
	do {
		swapped = 0;
		current = left = *list;

		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}
		right = current;

		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		left = current;
	} while (swapped);
}

/**
* swap_nodes - Swaps two nodes in a doubly linked list.
* @list: Pointer to the pointer of the head of the list.
* @node1: Pointer to the first node to be swapped
* @node2: Pointer to the second node to be swapped
*
* Return: no return(void).
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
