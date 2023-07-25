#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @x: first integer to swap first.
 * @y: integer to swap second.
 */

void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function to sort an array using Quick sort
 *
 * @array: The array to be sorted
 * @size: size of array
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high - low > 0)

	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);

	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: array size
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int *temp, i, j;

	temp = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *temp)
		{
			if (i < j)
			{
				swap_ints(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *temp)
	{
		swap_ints(array + i, temp);
		print_array(array, size);
	}

	return (i);
}
