#include "shell.h"
/**
 * exit_function - perform exit
 * @args: arguments
 * Return: 1
 */
int exit_function(char *args[])
{
	int argCount;
	int exit_code;

	argCount = 0;
	while (args[argCount] != NULL)
		argCount++;
	if (argCount > 1)
	{
		exit_code =_atoi(args[1]);
		exit(exit_code);
	}
	else
	{
		exit(0);
	}
	return (1);
}
