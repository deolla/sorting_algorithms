#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of array.
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t m, n;
	int tmp;

	for (m = 0; m < size - 1 && swapped; m++)
	{
		swapped = 0;
		for (n = 0; n < (size - 1 - m); n++)
		{
			if (array[n] > array[n + 1])
			{
				tmp = array[n];
				array[n] = array[n + 1];
				array[n + 1] = tmp;
				swapped = 1;

				print_array(array, size);
			}
		}
	}
}
