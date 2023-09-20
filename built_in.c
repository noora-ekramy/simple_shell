#include"shell.h"
/**
 * isBuiltIn - cheakes if the command is from built-in or not
 * @command: the command
 * Return: 1 if it is a bult in command 0 otherwise
 */
int isBuiltIn(char *command)
{
	if (_strcmp(command, "env") == 0)
		return (1);
	else if (_strcmp(command, "exit") == 0)
		return (1);
	else if (_strcmp(command, "cd") == 0)
		return (1);
	else if (_strcmp(command, "setenv") == 0)
		return (1);
	else if (_strcmp(command, "unsetenv") == 0)
		return (1);
	else if (_strcmp(command, "alias") == 0)
		return (1);
	else if (_strcmp(command, "help") == 0)
		return (1);
	else
		return (0);

}
/**
 * run_builtin_commands - runs the command function
 * @command: command
 * @args: command arguments
 * Return: 1 for success ans 0 for fail
 */
int run_builtin_commands(char *command, char *args[])
{
	if (_strcmp(command, "env") == 0)
		return (env_func());
	else if (_strcmp(command, "exit") == 0)
		return (exit_function(args));
	else if (_strcmp(command, "cd") == 0)
		return (cd_func(args));
	else if (_strcmp(command, "setenv") == 0)
		return (setenv_func(args));
	else if (_strcmp(command, "unsetenv") == 0)
		return (unsetenv_func(args));
	else if (_strcmp(command, "alias") == 0)
		return (1);
	else if (_strcmp(command, "help") == 0)
		return (1);
	else
		return (0);
}
