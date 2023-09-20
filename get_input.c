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
	char input[1024];
	size_t comCount;
	int interactive_flag;
	ssize_t bytesRead;

	interactive_flag = 0;
	if (isatty(STDIN_FILENO) == 1)
		interactive_flag = 1;
	command = NULL;
	if (interactive_flag == 1)
		print_string("$ ");
	bytesRead = read(STDIN_FILENO, input, sizeof(input));
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
}

/**
 * get_arguments - git the input
 *
 * Return: the input
 *
 * @arguments: the arguments of the command
 * @command: command
*/

void get_arguments(char *arguments[], char *command)
{
	size_t argCount;

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