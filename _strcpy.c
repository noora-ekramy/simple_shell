#include "shell.h"

/**
 * _strcpy - copy string
 *
 * Return: pointer to string
 *
 * @dest: the place to paste in
 * @src: the place to copy from
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
