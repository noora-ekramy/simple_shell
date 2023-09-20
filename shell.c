#include "shell.h"

/**
 * main - entry point
 * Return: Exit status
 */

int main(void)
{
	while (1)
	{
		char *commands[100], *arguments[100];
		int i;

		signal(SIGINT, sig_handler);
		if (!environ)
			exit(-100);
		get_input(commands);
		i=0;
		while (commands[i] != NULL)
		{
			get_arguments(arguments, commands[i]);
			if (isBuiltIn(commands[i]) == 1)
			{
				run_builtin_commands(commands[i], arguments);
			}
			else
			{
				if (execute_command(commands[i], arguments) == -1)
					continue;
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * sig_handler - Handles the SIGINT signal.
 * @sig: The signal number (SIGINT).
 */
void sig_handler(int sig)
{
	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, "\n$ ", 3);
}
