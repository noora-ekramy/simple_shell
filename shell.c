#include "shell.h"
/**
 * main - entry point
 * Return: Exit status
 */
int main(void)
{
	while (1)
	{
		char *command, *arguments[100];
		int i;

		i =0;
		command = get_input(arguments);
 		printf("command:  %s \n", command);
                while(arguments[i++] != NULL)
                        printf("argumnet %i : %s \n", i , arguments[i]);


	}
	return (EXIT_SUCCESS);
}

