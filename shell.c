#include "shell.h"  

int main(void)
{
    char *input;
    size_t inputSize;
    char *token;
    char *command;
    char *arguments[100]; 
    int argCount;

    while (1)
    {
        input = NULL;
        inputSize = 0;
        printf("#cisfun$ ");
        getline(&input, &inputSize, stdin);
        input[strcspn(input, "\n")] = '\0';

        
        command = strtok_r(input, " ", &token);
        argCount = 0;

        while (token != NULL)
        {
            arguments[argCount++] = token;
            token = strtok_r(NULL, " ", &token);
        }
        arguments[argCount] = NULL; 

        if (command != NULL)
        {
            if (strcmp(command, "exit") == 0)
            {
                free(input);
                exit(EXIT_SUCCESS);
            }
            else if (strcmp(command, "cd") == 0)
            {
                if (argCount >= 1)
                {
                    if (chdir(arguments[0]) != 0)
                    {
                        perror("cd");
                    }
                }
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
    return EXIT_SUCCESS;
}
