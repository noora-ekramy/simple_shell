#include "shell.h"
/*
 *
 *
 */
char * get_input( char *arguments[])
{
	char *input, *command;
        size_t argCount, inputSize;
        int interactive_flag;
        ssize_t bytesRead;

	interactive_flag= 0;
	if (isatty(STDIN_FILENO) == 1)
                interactive_flag=1;
        input = NULL;
        command =NULL;
        inputSize = 0;
                if(interactive_flag == 1)
                        print_string("#cisfun$ ");
                bytesRead = getline(&input, &inputSize, stdin);
                if (bytesRead == -1)
                {
                        free(input);
			print_string("\n");
                        exit(EXIT_SUCCESS); 
                }
                if (input[_strlen(input) - 1] == '\n')
                        input[_strlen(input) - 1] = '\0';
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
return command;
}
