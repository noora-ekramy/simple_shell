#include "shell.h"
/**
 * setenv_func - sets a spasific enviroment variable to a vvalue
 * @args: arguments
 * Return: 1 if success 0 otherwise
 */
int setenv_func(char *args[])
{
	char *variable;
	char *value;
	int argCount;

	argCount = 0;
	while (args[argCount] != NULL)
		argCount++;

	if (argCount < 3 || args[1] == NULL || args[2] == NULL)
	{
		perror("setenv");
		return (-1);
	}

	variable = args[1];
	value = args[2];

	if (_setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}
/**
 * unsetenv_func - sets a spasific enviroment variable
 * @args: arguments
 * Return: 1 if success 0 otherwise
 */
int unsetenv_func(char *args[])
{
	 char *variable;
	int argCount;

	argCount = 0;
	while (args[argCount] != NULL)
		argCount++;

	if (argCount < 2 || args[1] == NULL)
	{
		perror("unsetenv");
		return (-1);
	}
	variable = args[1];
	if (_unsetenv(variable) != 0)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
