#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insert in sorted linked list
 * @head: The first node
 * @number: new node
 *
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *dummy = *head;
	listint_t *my_node;
	listint_t *previous = NULL;

	my_node = malloc(sizeof(listint_t));

	if (my_node == NULL) {
		return (NULL);
	}
		

	my_node->n = number;
	my_node->next = NULL;

	if (*head == NULL || (*head)->n >= number)
	{
		my_node->next = *head;
		*head = my_node;
		return (my_node);
	}

	while (dummy && number >= dummy->n)
	{
		previous = dummy;
		dummy = dummy->next;
	}

	my_node->next = dummy;
	previous->next = my_node;

	return (my_node);
}