#include "shell.h"
/**
 * main - entry point
 * Return: Exit status
 */
int main(void)
{
	while (1)
	{
		char *command, *arguments[100];
		int i;

		i =0;
		command = get_input(arguments);
 		
	}
	return (EXIT_SUCCESS);
}

