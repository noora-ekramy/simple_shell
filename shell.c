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
		int env_count;

		signal(SIGINT, sig_handler);
		env_count = 0;
		command = get_input(arguments);
		if (command != NULL)
		{
			if (_strcmp(command, "exit") == 0)
				exit(EXIT_SUCCESS);
			else if (_strcmp(command, "env") == 0)
			{
				while (environ[env_count] != NULL)
				{
					print_string(environ[env_count]);
					print_string("\n");
					env_count++;
				}
				continue;
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
