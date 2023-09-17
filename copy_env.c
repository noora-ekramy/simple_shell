#include "shell.h"
/**
 * copy_env - Creates a copy of the environment.
 * Return: env if succes else NULL
 */
char **copy_env(void)
{
	char **new_environ = NULL;
	size_t size, env_len, i, j;

	for (size = 0; environ[size]; size++);
	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		env_len = strlen(environ[i]);
		new_environ[i] = malloc(env_len + 1);
		if (!new_environ[i])
		{
			for (j = 0; j < i; j++)
				free(new_environ[j]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[i], environ[i]);
	}
	new_environ[size] = NULL;
	return (new_environ);
}
