#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <sys/stat.h>

extern char **environ;

int _setenv(char *name, char *value, int overwrite);
int check_new_value(char *new_value);
int _unsetenv(char *name);
int env_func(void);

int main() {
  char *name = "TEST_ENV";
  char *value = "my value";

  // Set the environment variable.
  if (_setenv(name, value, 1) != 0) {
    printf("Failed to set environment variable.\n");
    return 1;
  }

  // Get the value of the environment variable.
  char *env_value = getenv(name);

  // Print the value of the environment variable.
  printf("The value of the environment variable %s is %s.\n", name, env_value);

  _unsetenv("HOME");
  _unsetenv("PATH");
  _unsetenv("NAME");
  _unsetenv("PWD");
  _unsetenv("PATH");


  env_func();
  return 0;
}

int _setenv(char *name, char *value, int overwrite)
{
        int i = 0, flag;
        char *env_key, *env_copy, *new_value;

        new_value = "";
        flag = 0;
        while (environ[i] != NULL)
        {
                env_copy = strdup(environ[i]);
                env_key = strtok(env_copy, "=");
                if (strcmp(env_key, name) == 0)
                {
                        flag = 1;
                        if (overwrite > 0)
                        {
                                free(environ[i]);
                                environ[i] = malloc(strlen(name) + strlen(value) + 2);
                                if (check_new_value(environ[i]) == -1)
                                        return (-1);
                                strcpy(environ[i], name);
                                strcat(environ[i], "=");
                                strcat(environ[i], value);
                                return (0);
                        }
                }

                i++;
        }
        if (flag == 1)
        {
                return (0);
        }

        new_value = malloc(strlen(name) + strlen(value) + 2);
        if (check_new_value(new_value) == -1)
                return (-1);
        strcpy(new_value, name);
        strcat(new_value, "=");
        strcat(new_value, value);
        environ[i] = new_value;
        environ[++i] = NULL;
        return (0);
}

int check_new_value(char *new_value)
{
        if (new_value == NULL)
        {
                perror("malloc error");
                return (-1);
        }
        return (0);
}

int _unsetenv(char *name)
{
        int i = 0, flag;
        char *env_key, *env_copy;

        flag = 0;
        while (environ[i] != NULL)
        {
                env_copy = strdup(environ[i]);
                env_key = strtok(env_copy, "=");
                if (flag == 1)
                {
                        if (environ[i + 1] != NULL)
                        {
                                environ[i] = malloc(strlen(environ[i + 1]) + 1);
                                if (environ[i] == NULL)
                                {
                                        free(env_copy);
                                        return (-1);
                                }
                                strcpy(environ[i], environ[i + 1]);
                        }
                        else
                        {
                                environ[i] = NULL;
                                free(environ[i]);
                        }
                }
                if (strcmp(env_key, name) == 0)
                {
                        flag = 1;
                        continue;
                }

                i++;
        }
        free(env_copy);
        return (0);
}

int env_func(void)
{
        int env_count;

        env_count = 0;
        while (environ[env_count] != NULL)
        {
                printf("%s\n", environ[env_count]);
                env_count++;
        }
        return (1);
}
