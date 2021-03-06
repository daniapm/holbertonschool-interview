#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * sift_sort - swaps two integers
 * @x: int
 * @y: int
 * Retuen: nothing
 */
void sift_sort(int *x, int *y)
{
	*x = *x * *y;
	*y = *x / *y;
	*x = *x / *y;
}

/**
 * get_down - turns an array into a max heap
 * @array: array of integers
 * @idx: current given index within array
 * @size: size of the array
 * @len: size to use as boundaries
 * Return: nothing
 */
void get_down(int *array, int idx, int size, int len)
{
	int left = (idx * 2) + 1;
	int right = (idx * 2) + 2;
	int max = idx;

	if (left > 0 && left < len && array[left] > array[max])
		max = left;
	if (right > 0 && right < len && array[right] > array[max])
		max = right;
	if (max != idx)
	{
		sift_sort(array + max, array + idx);
		print_array(array, size);
		get_down(array, max, size, len);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * @array: array of integers to sort
 * @size: size of the array
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int i = (size / 2) - 1;
	int end = size - 1;

	while (i >= 0)
	{
		get_down(array, i, size, size);
		i--;
	}

	while (end > 0)
	{
		sift_sort(array + end, array);
		print_array(array, size);
		get_down(array, 0, size, end);
		end--;
	}
}
