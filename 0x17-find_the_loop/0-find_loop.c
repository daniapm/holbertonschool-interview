#include "lists.h"

/**
 * find_listint_loop - Find the Loop
 * @head: pointer to the head of the list
 * Return: The address of the node where the loop starts, or NULL if there is
 *
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first, *last;

	if (head == NULL)
		return (NULL);

	first = head;
	last = head;

	while (first && last && last->next)
	{
		first = first->next;
		last = last->next->next;

		if (first == last)
		{
			first = head;
			while (first && last)
			{
				if (first == last)
					return (first);
				first = first->next;
				last = last->next;
			}
		}
	}

	return (NULL);
}
