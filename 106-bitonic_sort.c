#include "sort.h"

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

/**
 * bitonic_merge -  Merges two sorted halves of a bitonic sequence.
 * @array: The array.
 * @size: Number of element.
 * @ops: Starting index of sequence in array.
 * @dir: Size of the sequence to sort.
 * @pop: Direction to sort in array.
 */
void bitonic_merge(int *array, size_t size, size_t ops, size_t dir, char pop)
{
	size_t m, mid;

	mid = dir / 2;

	if (dir > 1)
	{
		for (m = ops; m < ops + mid; m++)
		{
			if ((pop == OP && array[m] > array[m + mid]) ||
			    (pop == OS && array[m] < array[m + mid]))
				_swap(array + m, array + m + mid);
		}
		bitonic_merge(array, size, ops, mid, pop);
		bitonic_merge(array, size, ops + mid, mid, pop);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: The array.
 * @size: Number of elements in the array
 * @ops: Starting index of the bitonic sequence
 * @dir: Size of bitonic sequence.
 * @pop: Direction to sort the bitonic sequence.
 */
void bitonic_recur(int *array, size_t size, size_t ops, size_t dir, char pop)
{
	size_t cut = dir / 2;
	char *p;

	p = (pop == OP) ? "UP" : "DOWN";

	if (dir > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", dir, size, p);
		print_array(array + ops, dir);

		bitonic_recur(array, size, ops, cut, OP);
		bitonic_recur(array, size, ops + cut, cut, OS);
		bitonic_merge(array, size, ops, dir, pop);

		printf("Result [%lu/%lu] (%s):\n", dir, size, p);
		print_array(array + ops, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the Bitonic sort algorithm.
 * @array: The array.
 * @size: NUmbers of element in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_recur(array, size, 0, size, OP);
}
