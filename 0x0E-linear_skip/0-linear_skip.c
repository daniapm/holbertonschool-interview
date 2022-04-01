#include "search.h"

/**
 * linear_skip - is a pointer to the head of the skip list to search in
 * @list: the value to search for
 * @value: the value to search for
 * Return: pointer on the first node where value is located
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *last = NULL, *first = NULL;

	if (!list)
		return (NULL);

	last = list;
	first = list->express;

	while (first)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       first->index, first->n);
		if (first->n >= value)
			break;
		last = first;
		if (first->express == NULL)
		{
			while (first->next)
				first = first->next;
			break;
		}
		first = first->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       last->index, first->index);

	while (last && last->index <= first->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       last->index, last->n);
		if (last->n == value)
			return (last);
		last = last->next;
	}

	return (NULL);
}
