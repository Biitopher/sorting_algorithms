#include "sort.h"

/**
 * merge - sorts an array of integers in ascending order using the Merge sort
 * @left: pointer to the left elements
 * @right: pointer to elements on the right
 * @left_s: left size
 * @right_s: right size
 * @array: size of array
 */

void merge(int *left, size_t left_s, int *right, size_t right_s, int *array)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_s && j < right_s)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_s)
	{
		array[k] = left[i];
		i++;
		k++;
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: integers in the array
 * @size: size of array
 *
 */

void merge_sort(int *array, size_t size)
{
	size_t i, j, k;
	size_t mid = size / 2;
	int *left = (int *)malloc(mid * sizeof(int));
	int *right = (int *)malloc((size - mid) * sizeof(int));
	size_t right_size = 0;

	if (size <= 1)
		return;
	if (!left || !right)
	{
		while (j < right_size)
		{
			array[k] = right[j];
			j++;
			k++;
		}
	}
	for (i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(left, mid, right, size - mid, array);
	print_array(array, size);
	free(left);
	free(right);
}
