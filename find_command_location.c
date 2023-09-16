#include "shell.h"

/**
 * find_command_location - Find the location of a command in PATH
 * @command: The command to locate
 *
 * Return: The full path to the command if found, otherwise NULL
 */

char *find_command_location(const char *command)
{
	int access_result;
	char *command_copy;
	command_copy = _strdup(command);
	access_result = access(command_copy, X_OK);
                if (access_result == -1)
                {
                        command_copy = get_path(command_copy);
                }
                access_result = access(command_copy, X_OK);
                if (access_result == -1)
                {
                        return NULL;
                }
		return command_copy;

}
