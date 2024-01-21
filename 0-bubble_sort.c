#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascend order using Bubble Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Set swapped flag to true */
				swapped = 1;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}

		/* if no two elements were swapped by inner loop, array is already sorted */
		if (swapped == 0)
			break;
	}
}
