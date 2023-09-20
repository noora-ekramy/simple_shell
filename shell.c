#include "shell.h"

void freeStringArray(char *arr[], size_t arrSize);

/**
 * main - entry point
 * Return: Exit status
 */

int main(void)
{
	while (1)
	{
		char *commands[100], *arguments[100];
		int i;
		size_t argCount;

		signal(SIGINT, sig_handler);
		if (!environ)
			exit(-100);
		get_input(commands);
		i = 0;
		while (commands[i] != NULL)
		{
			argCount = get_arguments(arguments, commands[i]);
			if (isBuiltIn(commands[i]) == 1)
			{
				run_builtin_commands(commands[i], arguments);
			}
			else
			{
				if (execute_command(commands[i], arguments) == -1)
				{
					i++;
					continue;
				}
			}
			i++;
			freeStringArray(arguments, --argCount);
		}
		freeStringArray(commands, i);
		if (isatty(STDIN_FILENO) != 1)
			break;
	}
	return (EXIT_SUCCESS);
}

/**
 * sig_handler - Handles the SIGINT signal.
 * @sig: The signal number (SIGINT).
 */
void sig_handler(int sig)
{
	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, "\n$ ", 3);
}

/**
 * freeStringArray - free an array of string
 *
 * Return: void
 *
 * @arr: the array to free
 *
 * @arrSize: the size of array
*/

void freeStringArray(char *arr[], size_t arrSize)
{
	size_t i;

	if (arr != NULL)
	{
		for (i = 0; i < arrSize; i++)
		{
			if (arr[i] != NULL)
			{
				free(arr[i]);
			}
		}
	}
}

