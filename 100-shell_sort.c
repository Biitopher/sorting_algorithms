#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * shell_sort - sorts array of integers in ascending order using Shell sort
 * @array: Array of integers to be sorted
 * @size: size of array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t temp, i, j;

	if (array == NULL || size < 2)
		return;
	for (temp = 1; temp < (size / 3);)
		temp = temp * 3 + 1;
	for (; temp >= 1; temp /= 3)
	{
		for (i = temp; i < size; ++i)
		{
			j = i;
			while (j >= temp && array[j - temp] > array[j])
			{
				swap_ints(array + j, array + (j - temp));
				j -= temp;
			}
		}
	}
}
