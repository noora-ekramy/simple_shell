#include "shell.h"
/**
 * main - entry point
 * Return: Exit status
 */
int main(void)
{
	while (1)
	{
		char *command, *arguments[100];
		int  env_count;

		env_count=0;
		command = get_input(arguments);
 		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
				exit(EXIT_SUCCESS);
			else if (strcmp(command, "env") == 0)
               		{
                        	while (environ[env_count] != NULL)
                        	{
                                	print_string(environ[env_count]);
					print_string("\n");
                                	env_count++;
                        	}
                        	continue;
                	}
			else
			{
				if (execute_command(command, arguments) == -1)
					break;
			}
		}
	}
	return (EXIT_SUCCESS);
}

