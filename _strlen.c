#include "shell.h"

/**
 * _strlen - give the length of the string
 *
 * Return: string length
 *
 * @s: the string to print
*/

int _strlen(const char *s)
{
	int i = 0, count = 0;

	for (; s[i] != 0; i++)
	{
		count++;
	}
	return (count);
}
