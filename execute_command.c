#include "shell.h"


extern char **environ; 

int execute_command(const char *command, char *const arguments[])
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return -1; 
    }

    if (child_pid == 0) {
   
        if (execve(command, arguments, environ) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            return exit_status; 
        } else {
            return -1;
        }
    }

    return 0; 
}
