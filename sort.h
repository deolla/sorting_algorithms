#ifndef _SORT_H_
#define _SORT_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

/* Helper Functions */
void swap(int *array, ssize_t a, ssize_t b);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, int size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
int maximum_value(int *array, int size);
void merge(int *array, int *tmp_array, size_t start, size_t mid, size_t end);
void merge_recursive(int *array, int *tmp_array, size_t start, size_t end);
void sift_down(int *array, size_t size, size_t pop, size_t index);
void heap_swap(int *a, int *b);
void count_sort(int *array, size_t size, int e, int *output);

#endif /*_SORT_H_ */
