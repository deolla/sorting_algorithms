#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort.
 * @list: the first node.
 *
 * Returns: no return.(void)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *key, *prev, *next_node, *prev_node;

	if (*list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr)
	{
		key = curr;
		prev = curr->prev;

		while (prev && key->n < prev->n)
		{
			next_node = key->next;
			prev_node = prev->prev;

			if (prev_node)
				prev_node->next = key;
			else
				*list = key;

			prev->prev = key;
			prev->next = next_node;

			if (next_node)
				next_node->prev = prev;

			key->prev = prev_node;
			key->next = prev;

			print_list(*list);

			prev = key->prev;
		}
		curr = curr->next;
	}
}
