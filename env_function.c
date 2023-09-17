#include"shell.h"
int env_func(void)
{
	int env_count;

	env_count = 0;
	while (environ[env_count] != NULL)
	{
		print_string(environ[env_count]);
		print_string("\n");
		env_count++;
	}
	return (1);
}
