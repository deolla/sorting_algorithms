#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using Quick sort with Hoare partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	 if (array == NULL || size < 2)
		 return;

	 quick_recursive(array, size, 0, size - 1);
}
/**
 * quick_recursive - Recursively performs Quick sort on the array
 *
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 */
void quick_recursive(int *array, size_t size, int low, int high)
{
	int pivot;

	if (high - low > 0)
	{
		pivot = hoare_partition(array, size, low, high);
		quick_recursive(array, size, low, pivot - 1);
		quick_recursive(array, size, pivot, high);
	}
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 *
 * Return: The index of the pivot after partitioning
 */
int hoare_partition(int *array, int size, int low, int high)
{
	int pivot = array[high];
	int i, j;

	i = low - 1;
	j = high + 1;
	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			_swap(array + i, array + j);
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * _swap - Swap two integers in an array.
 * @a: First index element.
 * @b: Second index element.
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
