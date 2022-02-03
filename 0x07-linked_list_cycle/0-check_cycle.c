#include "lists.h"

/**
 * check_cycle - function in C that checks if a singly linked list has a cycle in it
 * @list: list to check
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
    listint_t *loop_one = list;
	listint_t *loop_two = list;

	while (loop_one != NULL && loop_one->next != NULL)
	{
		loop_one = loop_one->next->next;
		loop_two = loop_two->next;
		if (loop_one == loop_two)
			return (1);
	}
	return (0);
}
