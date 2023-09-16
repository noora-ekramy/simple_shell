#include "shell.h"
/*
 *
 *
 *
 */

void get_input(char *input,char *command , char *arguments[])
{
	int argCount;


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

}
