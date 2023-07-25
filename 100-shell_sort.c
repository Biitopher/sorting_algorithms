#include "sort.h"
#include <stddef.h>

/**
 * knuth_sequence - knuth_sequence
 * @size: data size
 *
 */

size_t knuth_sequence(size_t size)
{
    size_t gap = 1;
    while (gap < size)
    {
        gap = gap * 3 + 1;
    }
    return gap / 3;
}

/**
 * shell_sort - sorts array of integers in ascending order using Shell sort
 * @array: Array of integers to be sorted
 * @size: size of array
 *
 */

void shell_sort(int *array, size_t size)
{
    size_t gap = knuth_sequence(size);
    size_t i;

    while (gap > 0) {
        for (i = gap; i < size; ++i)
	{
            int temp = array[i];
            size_t j = i;

            while (j >= gap && array[j - gap] > temp)
	    {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }
	print_array(array, size);
	gap /=3;
    }
}
