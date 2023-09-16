#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

void end(int sig);
char *get_path(char *command);

int main(void)
{
        extern char ** environ;
        char *buffer = NULL;
        size_t length;
        pid_t pid;
        char *command, *args;
        char *argv[20];
        int i = 0, t = 0, t2 = 0;
        int access_result;
	ssize_t bytesRead;	
        while (1)
        {
		buffer = NULL;
                int env_count = 0;
                printf("$ ");
		bytesRead = getline(&buffer, &length, stdin);


                if (bytesRead == -1)
                {
                        /*free(buffer);*/
                        printf("\n");
                        exit(EXIT_SUCCESS);
			return 0;
                }

                signal(SIGINT, end);
                command = buffer;
                if(command[strlen(command)-1] == '\n')
			command[strlen(command)-1]= '\0';

                if (command == NULL)
                {
                        continue;
                }
                command = strtok(command, " ");
                if (strcmp(command, "exit") == 0)
                        exit (0);
                if (strcmp(command, "env") == 0)
                {
                        while (environ[env_count] != NULL)
                        {
                                printf("%s\n", environ[env_count]);
                                env_count++;
                        }
                        continue;
                }
		//try
                argv[0] = command;
                i = 0;
                while (command != NULL)
                {
                        argv[i] = command;
                        i++;
                        command = strtok(NULL, " ");
                }

                argv[i] = NULL;

                //try
                t = 0;
                while (argv[t] != NULL)
                {
                        printf("argv[%d] = %s\n", t, argv[t]);
                        t++;
                }
                access_result = access(argv[0], X_OK);
                if (access_result == -1)
                {
                        argv[0] = get_path(argv[0]);
                        printf("argv[0] = %s\n", argv[0]);
                }
                access_result = access(argv[0], X_OK);
                if (access_result == -1)
                {
                        perror("access errorrrrr");
                        continue;
                }


                pid = fork();
                if (pid == 0)
                {
                        if (execve(argv[0], argv, environ) == -1)
                        {
                                perror("execve error");
                                exit (1);
                        }
                }
                else
                {
                        wait(NULL);
                }
        }
	 return (0);
}

void end(int sig)
{
        printf("\n");
        exit (0);
}

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
