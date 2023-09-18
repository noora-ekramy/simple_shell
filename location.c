#include "shell.h"

/**
 * find_path - find the var path
 *
 * Return: path value
 *
*/

char *find_path(void)
{
	int i = 0;
	char *env_key, *env_copy;

	while (environ[i] != NULL)
	{
		env_copy = _strdup(environ[i]);
		env_key = strtok(env_copy, "=");
		if (_strcmp(env_key, "PATH") == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

/**
 * get_path - git the path of the command
 *
 * Return: the path of the command
 *
 * @command: the command to find the path for
*/

char *get_path(char *command)
{
	char *path, *tok, *command_path;
	struct stat buffer;

	path = find_path();
	tok = strtok(path, ":");

	while (tok != NULL)
	{
		command_path = malloc(strlen(tok) + _strlen(command) + 2);
		if (command_path == NULL)
			return (NULL);
		_strcpy(command_path, tok);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		if (stat(command_path, &buffer) == 0)
		{
			return (command_path);
		}
		free(command_path);
		tok = strtok(NULL, ":");
	}
	return (NULL);
}
