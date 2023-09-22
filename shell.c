#include "shell.h"
#include <stdlib.h>
int is_all_spc(char *input);
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

	token = _strtok(input, "\n;");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n;");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * read_file - Read Command From File
 * @filename: File name
 * Return: -1 or  0
 */
int read_file(char *filename)
{
	int  last_exit=0;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char **arguments , *input;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "./hsh: 0: Can't open %s\n", filename);
        return (127);
	}
	while ((getline(&line, &len, fp))!= -1)
	{

                input = _strtok(line, "\n");
                if (is_all_spc(input))
                {
                        last_exit =0;
                        continue;
                }
                
			arguments = get_arguments(input);
			if (isBuiltIn(arguments[0]) == 1)
			{
				if(_strcmp(arguments[0], "exit") == 0)
				{			
					last_exit = exit_function(arguments, last_exit);
					exit(last_exit);
					return (EXIT_SUCCESS);
				}
				run_builtin_commands(arguments[0], arguments);
				
			}
			else
			{
				last_exit = execute_command(arguments[0], arguments);
			}       
                if(arguments != NULL)
		        free(arguments);
	}
	if (line!= NULL)
		free(line);
	fclose(fp);

	return 0;
}
int is_all_spc(char *input)
{

	int i = 0;
        if(input ==NULL)
                return 1;
	while (input[i] != '\0')
	{	
		if (input[i] != ' ' &&  input[i] != '\n' )
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
	int  last_exit=0;
	if (argc == 2)
	{
		last_exit = read_file(argv[1]);
		return last_exit;
	}
	else
	{
	while (1)
	{
		char **commands, *input;
		char **arguments;
		int i;

		signal(SIGINT, sig_handler);
		if (!environ)
			exit(-100);
		input = _getline();
		if (is_all_spc(input))
		{
			free(input);
			if (isatty(STDIN_FILENO) != 1)
			{
				exit(0);
				return(EXIT_SUCCESS);
			}
			continue;
		}
		commands = parse_cmd(input);
		i = 0;
		while (commands[i] != NULL)
		{
			arguments = get_arguments(commands[i]);
			if (isBuiltIn(arguments[0]) == 1)
			{
				if(_strcmp(arguments[0], "exit") == 0)
				{
				
					
					last_exit = exit_function(arguments, last_exit);
					free(commands);
					free(input);
					exit(last_exit);
					return (EXIT_SUCCESS);
				}
				run_builtin_commands(arguments[0], arguments);
				
			}
			else
			{
				last_exit = execute_command(arguments[0], arguments);
				if (last_exit != 0)
				{
					i++;
					free(arguments);
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
	
	exit(last_exit);
	return (last_exit);
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
