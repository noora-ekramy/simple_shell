#ifndef SHELL_H
#define SHELL_H

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

int execute_command(const char *command, char *const arguments[]);
size_t _strcspn(const char *s, const char *reject);
char *find_command_location(const char *command);
char *get_env_state(char *env_index);
char *get_path(char *command);
void get_input(char *commands[]);
size_t get_arguments(char *arguments[], char *input);
int _putchar(char c);
int print_string(char *s);
int _strlen(const char *s);
char *_strdup(const char *scr);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void sig_handler(int sig);
int isBuiltIn(char *command);
int run_builtin_commands(char *command, char *args[]);
int cd_func(char *args[]);
int exit_function(char *args[]);
int env_func(void);
int setenv_func(char *args[]);
int unsetenv_func(char *args[]);
int cd_error(char *messaeg);
int _atoi(char *s);
int is_flag(char c, const char *flag);
char *_strtok(char *str, const char *flag);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
char *read_input_from_pipe();
#endif /* SHELL_H */

