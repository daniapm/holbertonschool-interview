#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or not a given unsigned integer is a palindrome
 * @n:  The number to be checked
 *
 * Return: returns 1 if palindrome, 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	unsigned long temp = n, reverse-number = 0;
	int rem = 0;

	while (n != 0)
	{
		rem = n % 10;
		reverseNumber = reverseNumber * 10 + rem;
		n = n / 10;
	}
	if (temp == reverseNumber)
		return (1);
	return (0);
}
