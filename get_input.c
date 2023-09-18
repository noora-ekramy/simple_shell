#include "shell.h"

/**
 * get_input - git the input
 *
 * Return: the input
 *
 * @arguments: the arguments of the command
*/

char *get_input(char *arguments[])
{
	char input[1024], *command;
	size_t argCount;
	int interactive_flag;
	ssize_t bytesRead;

	interactive_flag = 0;
	if (isatty(STDIN_FILENO) == 1)
		interactive_flag = 1;
	/*input = NULL;*/
	command = NULL;
	if (interactive_flag == 1)
		print_string("$ ");
	bytesRead = read(STDIN_FILENO, input, sizeof(input));
	if (bytesRead == -1)
	{
		/*free(input);*/
		print_string("\n");
		exit(EXIT_SUCCESS);
	}
	command = _strtok(input, "\n");
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
	command = arguments[0];
	return (command);
}
