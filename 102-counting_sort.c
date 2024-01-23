#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers
 * in ascending order using Counting sort
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int max, *count, *output, j, k;

	if (size < 2)
		return;
	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	count = (int *)malloc((max + 1) * sizeof(int));

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	output = (int *)malloc(size * sizeof(int));
	j = 0;

	for (i = 0; i <= (size_t)max; i++)
	{
		for (k = 0; k < count[i]; k++)
			output[j++] = i;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
