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
int execute_command(const char *command, char *const arguments[]);
size_t _strcspn(const char *s, const char *reject);

#endif /* SHELL_H */

