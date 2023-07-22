#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using Bitonic sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 2)
		return;

	bitonic_recursive(array, size, 0, size, OPS);
}

/**
 * bitonic_recursive - Performs Bitonic sort on an array
 * @array: The array
 * @low: Index of the start of the array
 * @size: Number of elements in the array
 * @dir: Direction of the sort (1 for ascending, 0 for descending)
 */
void bitonic_recursive(int *array, size_t size, size_t low, char pop, size_t dir)
{
	char *p;
	size_t mid;

	mid = dir / 2;
	p = (pop == OPS) ? "UP" : "DOWN";

	if (dir > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", dir, size, p);
		print_array(array + low, dir);
		
		bitonic_recursive(array, size, low, mid, OPS);
		bitonic_recursive(array, size, low + mid, mid, OP);
		bitonic_recursive(array, size, low, pop, dir);

		printf("Result [%lu/%lu] (%s):\n", dir, size, p);
		print_array(array + low, dir);
	}
}

/**
 * bitonic_merge - Merges two sorted halves of a bitonic sequence
 *
 * @array: The array
 * @low: Index of the start of the first half
 * @size: Number of elements in each half
 * @dir: Direction of the merge (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, size_t low, char pop, size_t dir)
{
	size_t mid, m;

	mid = dir / 2;
	if (dir > 1)
	{
		for (m = low; m < low + mid; m++)
		{
			if ((pop == OPS && array[m] > array[m + mid]) ||
			    (pop == OP && array[m] < array[m + mid]))
				_swap(array + m, array + m + mid);
		}
		bitonic_merge(array, size, low, mid, pop);
		bitonic_merge(array, size, low + mid, mid, pop);
	}
}

/**
 * _swap - Swaps two elements in an array.
 * @a: Index of the first element.
 * @b: Index of the second element.
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
