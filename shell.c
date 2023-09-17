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

		signal(SIGINT, sig_handler);
		environ = copy_env();
		if (!environ)
			exit(-100);
		command = get_input(arguments);
		if (command != NULL)
		{
			if (isBuiltIn(command) == 1)
			{
				run__builtin_commands(command , arguments);
			}
			else
			{
				if (execute_command(command, arguments) == -1)
					break;
			}
		}
	}
	return (EXIT_SUCCESS);
}

/*
 *
 *
 *
 */
void sig_handler(int sig)
{
	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, "\n$ ", 3);
}
