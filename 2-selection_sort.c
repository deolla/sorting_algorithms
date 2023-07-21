#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort.
 * @array: the array to be sorted.
 * @size: size of array.
 *
 * Returns: no return. (void)
 */
void selection_sort(int *array, size_t size)
{
	size_t i, m, min_num;
	int tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_num = i;

		for (m = i + 1; m < size; m++)
		{
			if (array[m] < array[min_num])
				min_num = m;
		}

		if (min_num != i)
		{
			tmp = array[i];
			array[i] = array[min_num];
			array[min_num] = tmp;

			print_array(array, size);
		}
	}
}
