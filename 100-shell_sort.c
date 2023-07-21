#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * Shell sort algorithm with Knuth sequence.
 *
 * @array: The array to be sorted.
 * @size: Number of element in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int tmp;
	size_t u, m;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (m = gap; m < size; m++)
		{
			tmp = array[m];

			for (u = m; u >= gap && array[u - gap] > tmp; u -= gap)
			{
				array[u] = array[u - gap];
			}

			array[u] = tmp;
		}
		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
