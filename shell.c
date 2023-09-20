#include "shell.h"
#include <stdlib.h>

void freeStringArray(char **arr)
{
	size_t i;

    	if (arr != NULL)
    	{
        	for (i = 0; arr[i] != NULL; i++)
		{
			if (arr[i] != NULL)
            		{
                		free(arr[i]);
            		}
        	}
    	}
}
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

	token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * read_file - Read Command From File
 * @filename: Filename
 * @argv: Program Name
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
		
		/*freeStringArray(arguments);*/
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
		read_file(argv[1]);
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
