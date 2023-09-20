#include "shell.h"

/**
 * print_string - print givin string
 *
 * Return: string length
 *
 * @s: the string to print
*/

int print_string(char *s)
{
	int i = 0, count = 0;

	for (; s[i] != 0; i++)
	{
		_putchar(s[i]);
		count++;
	}
	return (count);
}
