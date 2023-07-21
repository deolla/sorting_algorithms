#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_array;

	if (array == NULL || size < 2)
		return;

	tmp_array = (int *)malloc(size * sizeof(int));
	if (tmp_array == NULL)
		return;

	merge_sort_recursive(array, 0, size - 1, tmp_array);

	free(tmp_array);
}

/**
 * merge_sort_recursive - Recursive helper function for Merge sort
 *
 * @array: The array to be sorted
 * @start: The starting index of the current sub-array.
 * @end: The ending index of the current sub-array.
 * @tmp_array: Temporary array for merging.
 */
void merge_sort_recursive(int *array, int start, int end, int *tmp_array)
{
	int middle;

	if (start >= end)
		return;

	middle = (start + end) / 2;

	merge_sort_recursive(array, start, middle, tmp_array);
	merge_sort_recursive(array, middle + 1, end, tmp_array);

	merge(array, start, middle, end, tmp_array);
}

/**
 * merge - Merges two sorted sub-arrays into a single sorted array
 *
 * @array: The original array
 * @start: The starting index.
 * @mid: The last index of the first sub-array
 * @end: The last index of the second sub-array
 * @tmp_array: Temporary array for merging
 */
void merge(int *array, int start, int mid, int end, int *tmp_array)
{
	int left_index = start;
	int right_index = mid + 1;
	int tmp_index = 0, i;

	while (left_index <= mid && right_index <= end)
	{
		if (array[left_index] <= array[right_index])
		{
			tmp_array[tmp_index] = array[left_index];
			left_index++;
		}
		else
		{
			tmp_array[tmp_index] = array[right_index];
			right_index++;
		}
		tmp_index++;
	}
	
	while (left_index <= mid)
	{
		tmp_array[tmp_index] = array[left_index];
		left_index++;
		tmp_index++;
	}

	while (right_index <= end)
	{
		tmp_array[tmp_index] = array[right_index];
		right_index++;
		tmp_index++;
	}
	for (i = 0; i < tmp_index; i++)
	{
		array[start + i] = tmp_array[i];
	}
}
