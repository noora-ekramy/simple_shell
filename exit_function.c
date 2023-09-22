#include "shell.h"

/**
 * is_int - check if int
 *
 * Return: 0 if success
 *
 * @input: the string to check
*/

int is_int(char *input)
{
	int i = 0;

	while (input[i] != '\0')
	{
		if (input[i] < '0' || input[i] > '9')
		{
			if (input[i] == '+' || input[i] == '-')
			{
				i++;
				continue;
			}
			return (0);
		}
		i++;
	}
	return (1);

}


/**
 * exit_function - perform exit
 * @args: arguments
 * @last: the last exit number
 * Return: 1
 */
int exit_function(char *args[], int last)
{
	int argCount;
	int exit_code = 0;

	argCount = 0;
	while (args[argCount] != NULL)
		argCount++;
	if (argCount > 1)
	{
		if (is_int(args[1]) == 0)
		{

			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
			free(args);
			return (2);
		}
		exit_code = _atoi(args[1]);
		free(args);
		if (exit_code < 0)
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %d\n", exit_code);
			return (2);
		}
		return (exit_code);
	}
	else
	{
		free(args);
		return (last);
	}
	free(args);
	return (last);
}
