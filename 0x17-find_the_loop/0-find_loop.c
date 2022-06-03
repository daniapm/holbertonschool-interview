#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 * @head: pointer to the head of the list
 * Return: The address of the node where the loop starts or NULL
 *
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *firts, *last;

	if (head == NULL)
		return (NULL);

	firts = head;
	last = head;

	while (firts && last && last->next)
	{
		firts = firts->next;
		last = last->next->next;

		if (firts == last)
		{
			firts = head;
			while (firts && last)
			{
				if (firts == last)
					return (firts);
				firts = firts->next;
				last = fast->next;
			}
		}
	}

	return (NULL);
}
