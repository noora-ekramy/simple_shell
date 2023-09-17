#include "shell.h"
int exit_function(char *args[])
{
	int argCount;
	int exit_code;

	argCount = 0;
	while (args[argCount] != NULL)
		argCount++;
	if (argCount > 1)
	{
		exit_code = atoi(args[1]);
		exit(exit_code);
	}
	else
	{
		exit(0);
	}
	
}
