#include "shell.h"
/**
 * execute_command - Execute a command with arguments
 * @command: The command to execute
 * @arguments: An array of arguments (including the command itself)
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(const char *command, char *const arguments[])
{
	pid_t child_pid;
	int status;
	int  i;
	char *command_location;

	command_location = find_command_location(command);
	
	if (command_location == NULL)
	{
		perror("execve");
		return (-1);
	}
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(command_location);
		return (-1); 
	}

	if (child_pid == 0)
	{
		printf("Executing command: %s\n", command_location);
		for ( i = 0; arguments[i] != NULL; i++)
		{
			printf("Argument %d: %s\n", i, arguments[i]);
		}
		if (execve(command_location, arguments, environ) == -1)
		{
			perror("execve");
			free(command_location);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(command_location);
		if (WIFEXITED(status))
		{
 			int exit_status = WEXITSTATUS(status);
			return (exit_status); 
		}
		else
		{
			return (-1);
		}
	}

    return (0); 
}
