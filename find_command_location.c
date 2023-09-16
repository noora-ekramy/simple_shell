#include "shell.h"

/**
 * find_command_location - Find the location of a command in PATH
 * @command: The command to locate
 *
 * Return: The full path to the command if found, otherwise NULL
 */

char *find_command_location(const char *command)
{
	char *path;
	char *path_copy;
	char *token;
	char full_path[1024];

	path = getenv("PATH");

	if (!path || !(*path))
		return (NULL);
	
	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
