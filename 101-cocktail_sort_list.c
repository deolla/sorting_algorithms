#include "sort.h"

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in
* ascending order using Cocktail Shaker sort algorithm
*
* @list: Pointer to the pointer of the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left = *list;
	listint_t *right = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		while (left->next != right)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				swapped = 1;
			}
			else
			{
				left  = left->next;
			}
		}
		if (!swapped)
			break;

		right = left;
		while (left->prev != NULL)
		{
			if (left->n < left->prev->n)
			{
				swap_nodes(list, left->prev, left);
				swapped = 1;
			}
			else
			{
				left = left->prev;
			}
		}
		left = (*list);
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
	if (*list == NULL || node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	print_list(*list);
}
