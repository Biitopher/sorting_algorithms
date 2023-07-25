#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int *counting_array, *output_array, j;
	size_t i;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (j = 0; j < max + 1; j++)
		counting_array[j] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	print_array(counting_array, max + 1);
	for (j = 1; j < max + 1; j++)
		counting_array[j] += counting_array[j - 1];
	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = size - 1; i < size; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	print_array(array, size);
	free(counting_array);
	free(output_array);
}
