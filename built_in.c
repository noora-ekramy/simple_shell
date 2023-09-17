#include"shell.h"
int isBuiltIn(char * command)
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
int run__builtin_commands(char *command , char *args[])
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
