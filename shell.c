#include "shell.h"

/**
 * main - entry point
 * Return: Exit status
 */

int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		char *command = argv[1];
        char *arguments[100];

		print_string(command);
        for (int i = 2; i < argc; i++)
        {
            arguments[i - 2] = argv[i];
			print_string(argv[i])
        }
        arguments[argc - 2] = NULL;

        int result = execute_command(command, arguments);

        if (result == -1)
        {
            fprintf(stderr, "Command execution failed.\n");
            return EXIT_FAILURE;
        }

        return result;
	}
	while (1)
	{
		char *commands[100], *arguments[100];
		int i;

		signal(SIGINT, sig_handler);
		if (!environ)
			exit(-100);
		get_input(commands);
		i = 0;
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
				{
					i++;
					continue;
				}
			}
			i++;
		}
		if (isatty(STDIN_FILENO) != 1)
			break;
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
