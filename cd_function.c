#include "shell.h"
int cd_func(char *args[])
{
	const char *home_directory;
	const char *previous_directory;
	 char cwd[1024];

    if (args[1] == NULL)
	{
        home_directory = getenv("HOME");
        if (home_directory == NULL) {
            perror("cd");
            return 0;
        }
        if (chdir(home_directory) != 0) {
            perror("cd");
            return 0; 
        }
    } 
	else if (_strcmp(args[1], "-") == 0) 
	{
        
        previous_directory = getenv("OLDPWD");
        if (previous_directory == NULL) {
            perror("cd");
            return 0;
        }

        if (chdir(previous_directory) != 0)
		{
            perror("cd");
            return 0;
        }
    } else 
	{
        if (chdir(args[1]) != 0) 
		{
            perror("cd");
            return 0;
  }
    }

   
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return 0; 
    }

    if (setenv("PWD", cwd, 1) != 0) {
        perror("setenv");
        return 0;
    } 

    return 1;
}
