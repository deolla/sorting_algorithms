#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_array;

	if (array == NULL || size < 2)
		return;

	tmp_array = malloc(size * sizeof(int));
	if (tmp_array == NULL)
		return;

	merge_recursive(array, tmp_array, 0, size);

	free(tmp_array);
}

/**
 * merge_recursive - Recursive function for Merge sort
 * @array: The array to be sorted
 * @start: The starting index of sub-array.
 * @end: The ending index of sub-array.
 * @tmp_array: Temporary array.
 */
void merge_recursive(int *array, int *tmp_array, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		merge_recursive(array, tmp_array, start, middle);
		merge_recursive(array, tmp_array, middle, end);

		merge(array, tmp_array, start, middle, end);
	}
}

/**
 * merge - Merges two sorted sub-arrays into a single sorted array.
 * @array: The original array
 * @start: The starting index.
 * @mid: The last index of sub-array
 * @end: The last index of sub-array
 * @tmp_array: Temporary array.
 */
void merge(int *array, int *tmp_array, size_t start, size_t mid, size_t end)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (a = start, b = mid; a < mid && b < end; c++)
		tmp_array[c] = (array[a] < array[b]) ? array[a++] : array[b++];
	for (; a < mid; a++)
		tmp_array[c++] = array[a];
	for (; b < end; b++)
		tmp_array[c++] = array[b];
	for (a = start, c = 0; a < end; a++)
		array[a] = tmp_array[c++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
