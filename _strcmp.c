#include "shell.h"

/**
 * _strcmp - copare two strings
 *
 * Return: 0 if the string is the same
 *
 * @s1: first string to compare
 *
 * @s2: second string to compare
 *
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0, r;

	while (s2[j] != '\0' || s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
			continue;
		}
		else
		{
			r = s1[i] - s2[j];
			return (r);
		}
	}
	return (0);
}
