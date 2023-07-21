#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of element in array.
 */
void heap_sort(int *array, size_t size)
{
	int m;

	if (array == NULL || size < 2)
		return;

	/* Bulild the max heap */
	for (m = (size / 2) - 1; m >= 0; m--)
		sift_down(array, size, size, m);

	for (m = size - 1; m > 0; m--)
	{
		heap_swap(array, array + m);
		print_array(array, size);
		sift_down(array, size, m, 0);
	}
}

/**
 * sift_down - Helper function to perform the sift-down operation in max heap.
 * @array: The array.
 * @size: Number of element in array.
 * @index: Index of the root node.
 * @pop: The index base.
 */
void sift_down(int *array, size_t size, size_t pop, size_t index)
{
	size_t left, right, big;

	big = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < pop && array[left] > array[big])
		big = left;

	if (right < pop && array[right] > array[big])
		big = right;

	if (big != index)
	{
		heap_swap(array + index, array + big);
		print_array(array, size);
		sift_down(array, size, pop, big);
	}
}

/**
 * heap_swap - Helper function that swap two element in an array.
 * @a: first element.
 * @b: second element.
 */
void heap_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
