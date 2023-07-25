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
 * selection_sort - Function to sort array in asc order
 *
 * @array: Array to be sorted
 * @size: Size of array
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;
		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
