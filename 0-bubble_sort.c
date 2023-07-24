#include "sort.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array of integers to be sorted
 * @size: size of data
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
        size_t a, b;

        for (a = 0; a < size - 1; ++a)
        {
                for (b = 0; b < size - a - 1; ++b)
                {
                        if (array[b] > array[b + 1])
                        {
                                swap(&array[b], &array[b + 1]);
                        }
                }
        }
}
