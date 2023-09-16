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
char *find_path(void);
char *get_path(char *command);
void get_input(char *input,char *command , char *arguments[]);
#endif /* SHELL_H */

