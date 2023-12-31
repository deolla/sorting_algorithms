#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using Counting sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count_array, m, max_num;

	if (array == NULL || size < 2)
		return;

	count_array = malloc(sizeof(int) * size);

	if (count_array == NULL)
		return;

	max_num = maximum_value(array, size);
	output = malloc(sizeof(int) * (max_num + 1));
	if (output == NULL)
	{
		free(count_array);
		return;
	}
	for (m = 0; m < (max_num + 1); m++)
		output[m] = 0;
	for (m = 0; m < (int)size; m++)
		output[array[m]] += 1;
	for (m = 0; m < (max_num + 1); m++)
		output[m] += output[m - 1];
	print_array(output, max_num + 1);

	for (m = 0; m < (int)size; m++)
	{
		count_array[output[array[m]] - 1] = array[m];
		output[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = count_array[m];

	free(count_array);
	free(output);
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
	int m, u;

	for (u = array[0], m = 1; m < size; m++)
	{
		if (array[m] > u)
			u  = array[m];
	}
	return (u);
}
