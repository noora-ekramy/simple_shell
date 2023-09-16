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
char *get_input(char *arguments[]);
int _putchar(char c);
int print_string(char *s);
int _strlen(const char *s);
char *_strdup(const char *scr);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void sig_handler(int sig);


#endif /* SHELL_H */

