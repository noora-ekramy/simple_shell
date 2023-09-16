#include "shell.h"
char *find_path(void)
{
        extern char **environ;
        int i = 0;
        char *env_key, *env_copy;

        while (environ[i] != NULL)
        {
                env_copy = strdup(environ[i]);
                env_key = strtok(env_copy, "=");
                if (strcmp(env_key, "PATH") == 0)
                        return (strtok(NULL, "\n"));
                i++;
        }
        return (NULL);
}

char *get_path(char *command)
{
        char *path, *tok, *command_path;
        struct stat buffer;

        path = find_path();
        tok = strtok(path, ":");

        while (tok != NULL)
        {
                command_path = malloc(strlen(tok) + strlen(command) + 2);
                if (command_path == NULL)
                        return(NULL);
                strcpy(command_path, tok);
                strcat(command_path, "/");
                strcat(command_path, command);
                if (stat(command_path, &buffer) == 0)
                {
                        printf("command_path = %s\n", command_path);
                        return (command_path);
                }
		free(command_path);
                tok = strtok(NULL, ":");
        }
        return (NULL);
}
