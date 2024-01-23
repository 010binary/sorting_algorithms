#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of the array.
 * @array: The array to be sorted
 * @l: Pointer to the left subarray
 * @l_size: Size of the left subarray
 * @r: Pointer to the right subarray
 * @r_size: Size of the right subarray
 */

void merge(int *array, int *l, size_t l_size, int *r, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((l_size + r_size) * sizeof(int));

	printf("Merging...\n[l]: ");
	print_array(l, l_size);
	printf("[r]: ");
	print_array(r, r_size);

	while (i < l_size || j < r_size)
	{
		temp[k++] = (j >= r_size || (i < l_size &&
					l[i] <= r[j])) ? l[i++] : r[j++];
	}
	for (i = 0; i < l_size + r_size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, l_size + r_size);
	free(temp);
}

/**
 * merge_sort_recursive - Recursively sorts an array
 * using the merge sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */

void merge_sort_recursive(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (size < 2)
		return;
	mid = size / 2;
	left = array;
	right = array + mid;
	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, size - mid);
	merge(array, left, mid, right, size - mid);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	merge_sort_recursive(array, size);
}
