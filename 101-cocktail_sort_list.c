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
	listint_t *current, *left = NULL, *right = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		current = left = *list;

		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;
				
				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;

				if (current->next != NULL)
					current->next->prev = current;

				current->prev->next = current;

				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}
		right = current;
		if (!swapped)
			break;
		swapped = 0;

		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				if(current->next != NULL)
					current->next->prev = current->prev;
				else
					right = current->prev;

				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->prev->prev;

				if (current->prev != NULL)
					current->prev->next = current;

				current->next->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
		left = current;
	} while (swapped);
}
