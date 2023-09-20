#include "shell.h"

/**
 * _strdup - duplicate a string
 *
 * Return: dup. string
 *
 * @scr: the scr string
*/

char *_strdup(const char *scr)
{
	int len, itr;
	char *dest;

	if (scr == NULL)
		return (NULL);
	len = _strlen(scr);
	itr = 0;
	dest = malloc(sizeof(char) * len + 1);
	while (scr[itr] != '\0')
	{
		dest[itr] = scr[itr];
		itr++;
	}
	dest[itr] = '\0';
	return (dest);
}
