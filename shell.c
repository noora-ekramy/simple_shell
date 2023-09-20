#include "shell.h"

/**
 * read_file - Read Command From File
 * @filename: Filename
 * @argv: Program Name
 * Return: -1 or  0
 */
void read_file(char *filename, char **argv)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
	char *arguments[100];
  
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    while ((getline(&line, &len, fp)) != -1)
	{
		get_arguments(arguments, line);
			if (isBuiltIn(line) == 1)
			{
				run_builtin_commands(line, arguments);
			}
			else
			{
				if (execute_command(line, arguments) == -1)
				{
					continue;
				}
			}
		}
		
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * main - entry point
 * Return: Exit status
 */

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		read_file(argv[1], argv);
	}
	else
	{
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
