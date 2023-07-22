#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_value = array[0], e;
	size_t m;

	if (array == NULL || size < 2)
		return;
	
	/* allocate memory */
	new = malloc(sizeof(int) * size);
	if (new == NULL)
		return;

	/* Find the maximum value */
	high = max_value(array, size);

	/* Perform counting sort for each significant digit */
	for (e = 1; high / e > 0; e *= 10)
	{
		count_sort(array, size, e);
		/* Print the array after each iteration */
		print_array(array, size);
	}
}

/**
 * count_sort - Helper function to perform Counting Sort.
 * @array: The array to be sorted.
 * @size: Number of element in the array.
 * @e: The current digit.
 */
void count_sort(int *array, size_t size, int e)
{
	int *output;
	size_t i;
	int count[10] = {0};

	/* Count the occurrences of each digit in the input array */
	for (m = 0; m < size; m++)
		count[(array[m] / e) % 10]++;

	/* Update the counting array to store the correct positions */
	for (m = 1; m < 10; m++)
		count[m] += count[m - 1];

	/* Build the output array in sorted order */
	for (m = size - 1; m >= 0; m--)
	{
		output[count[(array[m] / e) % 10] - 1] = array[m];
		count[(array[m] / e) % 10]--;
	}

	/* Copy the sorted elements back to the original array */
	for (m = 0; m < size; m++)
		array[m] = output[m];

	free(output);
}
