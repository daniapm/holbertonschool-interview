#include "slide_line.h"

/**
 * merge_left - Merges numbers starting from the left
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements
 */

void to_left(int *line, size_t size)
{
	size_t index;

	for (index = 0; index < size - 1; index++)
	{
		if (line[index] == line[index + 1])
		{
			line[index] += line[index  + 1];
			line[index + 1] = 0;
		}
	}
}

/**
 * merge_right - Merges numbers starting from the right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements
 */

void to_right(int *line, size_t size)
{
	ssize_t index;

	for (index = size - 1; index >= 0 ; index--)
	{
		if (line[index] == line[index - 1])
		{
			line[index] += line[index - 1];
			line[index - 1] = 0;
		}
	}
}

/**
 * slide_zeroes_right - Moves all zeros to the end (right)
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements
 */

void to_zero_right(int *line, size_t size)
{
	size_t index, n = 0, post = 0;

	for (index = 0; index < size; index++)
	{
		if (line[index] > 0)
		{
			post = line[index];
			line[index] = line[n];
			line[n] = post;
			n++;
		}
	}
}

/**
 * slide_zeroes_left - Moves all zeros to the start (left)
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements
 */

void to_zero_left(int *line, size_t size)
{
	ssize_t index, tmp = 0;

	for (index = size - 1; index >= 0; index--)
	{
		if (line[index] == 0)
			tmp++;
		else
			line[index + tmp] = line[index];
	}
	for (index = 0; index < tmp; index++)
		line[index] = 0;
}

/**
 * slide_line - Slides and merges an array of integers
 *
 * @line: points to an array of integers containing size elements
 * @size: Numbre to elements
 * @direction: right or left
 *
 * Return: return 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_RIGHT)
	{
		to_zero_left(line, size);
		to_right(line, size);
		to_zero_left(line, size);
	}

	else if (direction == SLIDE_LEFT)
	{
		to_zero_right(line, size);
		to_left(line, size);
		to_zero_right(line, size);
	}

	return (1);
}
