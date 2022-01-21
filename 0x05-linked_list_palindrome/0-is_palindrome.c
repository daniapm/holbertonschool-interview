#include "lists.h"

/**
 * isPalindromeUtil - Recursively moves the pointers to check if palindrome
 * @left: Will move from the start of the list
 * @right: Will move from the end of the list
 *
 * Return: Either 0 or 1 depending if is a palindrome
 */

int isPalindromeUtil(listint_t **left, listint_t *right)
{

	if (right == NULL)
		return (1);
	
	int isTrue;

	isTrue = isPalindromeUtil(left, right->next);

	if (isTrue == 0)
		return (0);

	if ((*left)->n == right->n)
		isTrue = 1;
	else
		isTrue = 0;

	*left = (*left)->next;

	return (isTrue);
}

/**
 * is_palindrome - Function in C that checks if a singly linked list is a palindrome.
 * @head: head of the linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t **left = head;
	listint_t *right = *head;

	if (*head == NULL)
		return (1);
	return (isPalindromeUtil(left, right));
}
