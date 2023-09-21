#include "shell.h"
#include <stdlib.h>

/**
 * parse_cmd - Parse Line Of Input
 * @input:User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = 1024;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * read_file - Read Command From File
 * @filename: File name
 * Return: -1 or  0
 */
void read_file(char *filename)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char **arguments;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		arguments = parse_cmd(line);
		if (isBuiltIn(arguments[0]) == 1)
		{
			run_builtin_commands(arguments[0], arguments);
		}
			else
			{
				if (execute_command(arguments[0], arguments) == -1)
				{
					continue;
				}
			}

		free(arguments);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
int is_all_spc(char *input)
{
	int i = 0;
	while (input[i] != '\0')
	{	
		if (input[i] != ' ')
			return (0);
		i++;
	}
	return (1);

}
/**
 * main - entry point
 * Return: Exit status
 * @argc: argc
 * @argv: argv
 */

int main(int argc, char **argv)
{
	if (argc == 2)
		read_file(argv[1]);
	else
	{
	while (1)
	{
		char **commands, *input;
		char **arguments;
		int i ;

		signal(SIGINT, sig_handler);
		if (!environ)
			exit(-100);
		input = _getline();
		if (is_all_spc(input))
		{
			free(input);
			continue;
		}
		commands = parse_cmd(input);
		i = 0;
		while (commands[i] != NULL)
		{
			arguments = get_arguments(commands[i]);
			if (isBuiltIn(arguments[0]) == 1)
			{
				run_builtin_commands(arguments[0], arguments);
			}
			else
			{
				if (execute_command(arguments[0], arguments) == -1)
				{
					i++;
					continue;
				}
			}
			i++;
		free(arguments);
		arguments = NULL;
		}
		free(input);
		free(commands);
		input = NULL;
		commands = NULL;
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
