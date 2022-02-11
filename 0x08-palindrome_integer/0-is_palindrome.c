#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 * @n:  The number to be checked
 *
 * Return: returns 1 if palindrome, 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	int tmp, num, prod = 0;

	for (num = n; n != 0; n = n / 10)
	{
		tmp = n % 10;
		prod = prod * 10 + tmp;
	}
	if (num == prod)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
