#include "shell.h"

/**
 * get_env_state - find the var path
 *
 * Return: path value
 *
 *@env_index: the key to search for
*/

char *get_env_state(char *env_index)
{
	int i = 0;
	char *env_key, *env_copy, *value , *ans;

	while (environ[i] != NULL)
	{
		env_copy = _strdup(environ[i]);
		env_key = _strtok(env_copy, "=");
		value = _strtok(NULL, "\n");
		if (_strcmp(env_key, env_index) == 0)
		{
			ans = _strdup(value);
			free(env_copy);
			return (ans);
		}
		i++;
	}
	free(env_copy);
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

	path = get_env_state("PATH");
	tok = _strtok(path, ":");

	while (tok != NULL)
	{
		command_path = malloc(strlen(tok) + _strlen(command) + 2);
		if (command_path == NULL)
		{
			free(path);
			return (NULL);
		}
		_strcpy(command_path, tok);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		if (stat(command_path, &buffer) == 0)
		{
			free(path);
			return (command_path);
		}
		free(command_path);
		tok = _strtok(NULL, ":");
	}
	free(command_path);
	free(path);
	return (NULL);
}
