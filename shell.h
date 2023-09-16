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
<<<<<<< HEAD
char *get_input(char *arguments[]);
=======
void get_input(char *input,char *command , char *arguments[]);
int _putchar(char c);
int print_string(char *s);
int _strlen(char *s);
>>>>>>> 5726fb0dd9300af44491f38bea6dd9d0095b3a37
#endif /* SHELL_H */

