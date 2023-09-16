#include "shell.h"

/**
 * _strcspn - Calculate the length of the initial segment of s
 * that does not contain any character from the reject string.
 * @s: The string to search within.
 * @reject: The string containing characters to reject.
 *
 * Return: The length of the initial segment of s without any
 * matching characters from reject.
*/

size_t _strcspn(const char *s, const char *reject)
{
	size_t count = 0;
	const char *p;

	for (p = s; *p != '\0'; ++p)
	{
		const char *r;

		for (r = reject; *r != '\0'; ++r)
		{
			if (*p == *r)
			{
				return (count);
			}
		}
	++count;
	}

	return (count);
}

