#include "shell.h"
/**
 * main - entry point
 * Return: Exit status
 */
int main(void)
{
	char *input, *command, *arguments[100];
	size_t argCount, inputSize;
	int interactive_flag;
	ssize_t bytesRead;

	interactive_flag= 0;
	if (isatty(STDIN_FILENO))
	{
		interactive_flag=1;
	}
	while (1)
	{
		int env_count = 0;
		input = NULL;
		command =NULL;
		inputSize = 0;
		if(interactive_flag == 1)
			printf("#cisfun$ ");
		bytesRead = getline(&input, &inputSize, stdin);
		if (bytesRead == -1)
		{
			free(input);
			printf("\n"); 
			exit(EXIT_SUCCESS); 
		}
		        /* Remove the newline character from user_input */
                if (input[strlen(input) - 1] == '\n')
                {
                        input[strlen(input) - 1] = '\0';
                }
                /* Tokenize user_input to separate the command and arguments */
                command = strtok(input, " ");
                argCount = 0;

                arguments[0] = command;
                while (command != NULL)
                {
                        arguments[argCount] = command;
                        argCount++;
                        command = strtok(NULL, " ");
                }
                arguments[argCount] = NULL;
                command = arguments[0];


 		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
			{
				free(input);
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(command, "env") == 0)
               		{
                        	while (environ[env_count] != NULL)
                        	{
                                	printf("%s\n", environ[env_count]);
                                	env_count++;
                        	}
                        	continue;
                	}

			else
			{
				if (execute_command(command, arguments) == -1)
				{
					free(input);
					break;
				}
			}
		}

		free(input);
	}
	return (EXIT_SUCCESS);
}

