#include "shell.h"

int check_new_value(char *new_value);

/**
 * _setenv - set env
 *
 * Return: 0 in success
 *
 * @name: name of the env.
 *
 * @value: the value of the env.
 *
 * @overwrite: to overwrite
*/


int _setenv(char *name, char *value, int overwrite)
{
	int i = 0, flag;
	char *env_key, *env_copy, *new_value;

	new_value = "";
	flag = 0;
	while (environ[i] != NULL)
	{
		env_copy = _strdup(environ[i]);
		env_key = _strtok(env_copy, "=");
		if (_strcmp(env_key, name) == 0)
		{
			flag = 1;
			if (overwrite > 0)
			{
				environ[i] = malloc(_strlen(name) + _strlen(value) + 2);
				if (check_new_value(environ[i]) == -1)
					return (-1);
				_strcpy(environ[i], name);
				_strcat(environ[i], "=");
				_strcat(environ[i], value);
				return (0);
			}
		}

		i++;
	}
	if (flag == 1)
	{
		return (0);
	}
	new_value = malloc(_strlen(name) + _strlen(value) + 2);
	if (check_new_value(new_value) == -1)
		return (-1);
	_strcat(new_value, name);
	_strcat(new_value, "=");
	_strcat(new_value, value);
	environ[i] = new_value;
	free(new_value);
	environ[++i] = NULL;
	return (0);
}

/**
 * check_new_value - check the -1 value
 *
 * Return: -1 if success
 *
 * @new_value: the value to check
*/

int check_new_value(char *new_value)
{
	if (new_value == NULL)
		perror("malloc error");
	return (-1);
}
