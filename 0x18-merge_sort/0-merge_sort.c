#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using the Merge Sort
 * @array: array of integers to sort
 * @size: size of the array of integers to sort
 *
 */

void merge_sort(int *array, size_t size)
{
	int *merge_h = malloc(sizeof(int) * size);

	if (merge_h == NULL)
		return;
	if (size <= 1 || array == NULL)
	{
		free(merge_h);
		return;
	}
	merge_holder(array, size, merge_h);
	free(merge_h);
}

/**
 * merge_holde - sorts array of ints with top-down
 * @array: array of integers to sort
 * @size: size of the array of integers to sort
 * @holder: temp array to hold information during merge
 */

void merge_holder(int *array, size_t size, int *holder)
{
	int size_m = size / 2;

	if (size <= 1)
		return;

	merge_holder(array, size_m, holder);
	merge_holder(&array[size_m], size - size_m, holder);
	merge(holder, array, size_m, size);
}

/**
 * merge - merges two subarrays together
 * @holder: temp array to hold information during merge
 * @array: array to merge
 * @mid: index of mid-point
 * @size: size of array to merge
 *
 */

void merge(int *holder, int *array, int mid, size_t size)
{
	int left = 0, right = mid, index = 0;

	printf("Merging...\n[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(&array[mid], size - mid);
	while (left < mid && right < (int)size)
	{
		if (array[left] <= array[right])
		{
			holder[index] = array[left];
			left++;
		}
		else
		{
			holder[index] = array[right];
			right++;
		}
		index++;
	}
	while (left < mid)
	{
		holder[index] = array[left];
		left++;
		index++;
	}
	while (right < (int)size)
	{
		holder[index] = array[right];
		right++;
		index++;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = holder[index];
	printf("[Done]: ");
	print_array(array, size);
}
