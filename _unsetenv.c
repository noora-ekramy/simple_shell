#include "shell.h"

/**
 * _unsetenv - to remove from env
 *
 * Return: 0 if success
 *
 * @name: name of the env. var
*/

int _unsetenv(char *name)
{
	int i = 0, flag;
	char *env_key, *env_copy;

	flag = 0;
	while (environ[i] != NULL)
	{
		env_copy = _strdup(environ[i]);
		env_key = _strtok(env_copy, "=");
		if (flag == 1)
		{
			if (environ[i + 1] != NULL)
			{
				environ[i] = malloc(_strlen(environ[i + 1]) + 1);
				if (environ[i] == NULL)
					return (-1);
				_strcpy(environ[i], environ[i + 1]);
			}
			else
				environ[i] = NULL;
		}
		if (_strcmp(env_key, name) == 0)
		{
			flag = 1;
			continue;
		}

		i++;
	}
	return (0);
}
