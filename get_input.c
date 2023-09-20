#include "shell.h"

/**
 * get_input - git the input
 *
 * Return: the input
 *
 * @commands: the arguments of the command
*/

void get_input(char *commands[])
{
	char *input, *command;
	size_t comCount;
	int interactive_flag;
	ssize_t bytesRead;

	interactive_flag = 0;
	if (isatty(STDIN_FILENO) == 1)
		interactive_flag = 1;
	command = NULL;
	if (interactive_flag == 1)
	{	print_string("$ ");
		input = (char *)malloc(1024);
		bytesRead = read(STDIN_FILENO, input, sizeof(input));
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

	command = _strtok(input, "\n");
	comCount = 0;
	commands[0] = command;
	while (command != NULL)
	{
		commands[comCount] = command;
		comCount++;
		command = _strtok(NULL, "\n");
	}
	commands[comCount] = NULL;
	/*free(input);*/
	free(command);
}

/**
 * get_arguments - git the input
 *
 * Return: the input
 *
 * @arguments: the arguments of the command
 * @input: command
*/

size_t get_arguments(char *arguments[], char *input)
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
	return (argCount);
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
