#include "shell.h"
/**
 * execute_command - Execute a command with arguments
 * @command: The command to execute
 * @arguments: An array of arguments (including the command itself)
 * Return: 0 on success, -1 on failure.
 */
int execute_command(const char *command, char *const arguments[])
{
	pid_t child_pid;
	int status;
	char *command_location;

	command_location = find_command_location(command);
	if (command_location == NULL)
	{
		free(command_location);
		fprintf(stderr, "./hsh: 1: %s: not found\n", command);
		return (127);
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
		if (execve(command_location, arguments, environ) == -1)
		{
			perror("execve");
			free(command_location);
			exit(EXIT_FAILURE);
		}
		free(command_location);

	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(command_location);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
	}
	free(command_location);
	return (0);
}
