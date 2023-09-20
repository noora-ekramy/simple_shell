#include "shell.h"
/**
 * cd_func - preform cd task
 * @args: cd arguments
 * Return: 1 if susses 0 otherwise
 */
int cd_func(char *args[])
{
	const char *home_directory, *previous_directory;
	char cwd[1024];

	if (args[1] == NULL)
	{
		home_directory = get_env_state("HOME");
		if (home_directory == NULL)
			return (cd_error("cd"));
		if (chdir(home_directory) != 0)
			return (cd_error("cd"));
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		previous_directory = get_env_state("OLDPWD");
		if (previous_directory == NULL)
			return (cd_error("cd"));
		if (chdir(previous_directory) != 0)
			return (cd_error("cd"));
	}
	else
		if (chdir(args[1]) != 0)
			return (cd_error("cd"));


	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (cd_error("getcwd"));
	if (setenv("PWD", cwd, 1) != 0)
		return (cd_error("setenv"));
	return (1);
}
/**
 * cd_error - returns error
 * @messaeg: error type
 * Return: 0
 */
int cd_error(char *messaeg)
{
	perror(messaeg);
	return (0);
}
