#include "sort.h"

/**
* swap - Swaps two elements in an array.
* @array: The array.
* @a: First element to swap.
* @b: Second element to swap.
*
* Return: no return(void)
*/
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
* lomuto_partition - Lomuto partition scheme for Quick Sort.
* @array: The array.
* @low: Starting index of partition to be sorted.
* @high: Ending index of partition to be sorted.
* @size: The size.
*
* Return: Index of the pivot final position.
*/
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (array[i] != array[j])
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(array, i, high);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: Array to be sorted
 * @low: The starting index partition to be sorted
 * @high: The ending index partition to be sorted.
 * @size: the size.
 *
 * Return: no return(void).
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t partition_index = 0;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order.
 * using Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Number of elements in array.
 *
 * Return: no return.(void).
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
