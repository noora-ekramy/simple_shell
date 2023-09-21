#include "shell.h"

/**
 * get_input - git the input
 *
 * Return: the input
 *
 * @commands: the arguments of the command
*/

char **get_input(void)
{
	char **tokens;
	char *token;
	int i, buffsize = 1024;	
	

	char *input;
	int interactive_flag;
	ssize_t bytesRead;

    /*******/
	interactive_flag = 0;
	if (isatty(STDIN_FILENO) == 1)
		interactive_flag = 1;
	if (interactive_flag == 1)
	{	print_string("$ ");
		bytesRead = getline(&input, &len, stdin);
	}
	else
	{
		input = read_input_from_pipe();
	}
	if (bytesRead == 0)
	{
		print_string("\n");
		exit(EXIT_SUCCESS);
	}
    /*******/


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
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * get_arguments - git the input
 *
 * Return: the input
 *
 * @arguments: the arguments of the command
 * @input: command
*/

void get_arguments(char *arguments[], char *input)
{
	size_t argCount;
	char *command;

	command = _strtok(input, " ");
	argCount = 0;
	arguments[0] = command;
	while (command != NULL)
	{
		arguments[argCount] = command;
	
		argCount++;
		command = _strtok(NULL, " ");
	}
	arguments[argCount] = NULL;


}
#define MAX_INPUT_SIZE 1024
/**
 * read_input_from_pipe - reads input
 * Return: the input
 */
char *read_input_from_pipe()
{
	char *input = (char *)malloc(MAX_INPUT_SIZE);
	ssize_t bytesRead;
	size_t inputSize = 0;
	char c;
	char *newInput;

	if (input == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while ((bytesRead = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (inputSize >= MAX_INPUT_SIZE - 1)
		{
			newInput = (char *)realloc(input, 2 * MAX_INPUT_SIZE);
			if (newInput == NULL)
			{
				perror("Failed to reallocate memory");
				free(input);
				exit(EXIT_FAILURE);
			}
			input = newInput;
		}

		input[inputSize++] = c;

		if (c == EOF || c == '\0')
		{
			break;
		}
	}
	input[inputSize] = '\0';

	return (input);
}
