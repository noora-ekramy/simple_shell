#include "shell.h"
/**
 * exit_function - perform exit
 * @args: arguments
 * Return: 1
 */
int exit_function(char *args[] , int last)
{
	int argCount;
	int exit_code=0;

	argCount = 0;
	while (args[argCount] != NULL)
		argCount++;
	if (argCount > 1)
	{
		exit_code = _atoi(args[1]);
		free(args);
		return(exit_code);
	}
	else
	{
		free(args);
		return(last);
	}
	free(args);
	return (last);
}
