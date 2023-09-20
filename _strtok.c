#include "shell.h"

/**
 * is_flag - check if the char is flag
 *
 * Return: 1 if the char is flag
 *
 * @c: the char to check if flag
 *
 * @flag: the flags
*/

int is_flag(char c, const char *flag)
{
	size_t i = 0;

	while (flag[i] != '\0')
	{
		if (c == flag[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * _strtok - tok. a string
 *
 * Return: the string before flag
 *
 * @str: the string to tok.
 *
 * @flag: the flags to stop at
*/

char *_strtok(char *str, const char *flag)
{
	static char *next;
	char *token;

	if (str != NULL)
	{
		next = str;
	}
	else if (next == NULL)
	{
		return (NULL);
	}
	while (*next != '\0' && is_flag(*next, flag))
	{
		next++;
	}
	if (*next == '\0')
	{
		return (NULL);
	}
	token = next;
	while (*next != '\0' && !is_flag(*next, flag))
	{
		next++;
	}
	if (*next != '\0')
	{
		*next = '\0';
		next++;
	}
	return (token);
}

