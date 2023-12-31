#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int *new, high, e;

	if (array == NULL || size < 2)
		return;

	/* allocate memory */
	new = malloc(sizeof(int) * size);
	if (new == NULL)
		return;

	/* Find the maximum value */
	high = maximum_value(array, size);

	/* Perform counting sort for each significant digit */
	for (e = 1; high / e > 0; e *= 10)
	{
		count_sort(array, size, e, new);
		/* Print the array after each iteration */
		print_array(array, size);
	}
	free(new);
}

/**
 * count_sort - Helper function to perform Counting Sort.
 * @array: The array to be sorted.
 * @size: Number of element in the array.
 * @e: The current digit.
 * @output: Stores array.
 */
void count_sort(int *array, size_t size, int e, int *output)
{
	size_t m;
	int count[10] = {0};

	/* Count the occurrences of each digit in the input array */
	for (m = 0; m < size; m++)
		count[(array[m] / e) % 10]++;

	/* Update the counting array to store the correct positions */
	for (m = 1; m < 10; m++)
		count[m] += count[m - 1];

	/* Build the output array in sorted order */
	for (m = size - 1; (int) m >= 0; m--)
	{
		output[count[(array[m] / e) % 10] - 1] = array[m];
		count[(array[m] / e) % 10]--;
	}

	/* Copy the sorted elements back to the original array */
	for (m = 0; m < size; m++)
		array[m] = output[m];
}

/**
 * maximum_value - Finds the maximum value in an array.
 * @array: The array.
 * @size: The numbers of element in an array.
 *
 * Return: The maximum value.
 */
int maximum_value(int *array, int size)
{
	int m = 1, u;

	u = array[0];
	while (m < size)
	{
		if (array[m] > u)
			u  = array[m];
		m++;
	}
	return (u);
}
