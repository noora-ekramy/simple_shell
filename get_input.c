#include "shell.h"

/**
 * _getline - Read input from stdin
 * Return: A dynamically allocated string containing the user's input.
 *         Returns NULL on failure or EOF (Ctrl+D).
 */
char *_getline(void)
{
    int BUFSIZE = 1024;
    int i, buffsize = 1024;
    char c = 0;
    char *buff ;
    char *new_buff;
    ssize_t rd;
	if (isatty(STDIN_FILENO) != 1)
		return (read_input_from_pipe());
	else
		print_string("$ ");

	buff = malloc(buffsize);	
    if (buff == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (i = 0; c != EOF && c != '\n'; i++)
    {
        if (i >= buffsize - 1)
        {
            buffsize += BUFSIZE;
            new_buff = realloc(buff, buffsize);
            if (new_buff == NULL)
            {
                perror("realloc");
                free(buff);
                exit(EXIT_FAILURE);
            }
            buff = new_buff;
        }
		fflush(stdout);
        rd = read(STDIN_FILENO, &c, 1);
        if (rd == 0)
        {
            free(buff);
            exit(EXIT_SUCCESS);
        }

        buff[i] = c;

        if (buff[0] == '\n')
        {
            buff[0] = '\0';
            return buff;
        }
    }
    buff[i] = '\0';
    return buff;
}

/**
 * get_input - git the input
 *
 * Return: the input
 *
 * @commands: the arguments of the command
*/

char **get_input(void)
{
	char **tokens;
	char *token;
	int i, buffsize = 1024;	
	

	char *input;
	int interactive_flag;


    /*******/
	interactive_flag = 0;
	if (isatty(STDIN_FILENO) == 1)
		interactive_flag = 1;
	if (interactive_flag == 1)
	{	print_string("$ ");
		
	}
	else
	{
		input = read_input_from_pipe();
	}

    /*******/


	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}
    token = _strtok(input, "\n");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * get_arguments - git the input
 *
 * Return: the input
 *
 * @arguments: the arguments of the command
 * @input: command
*/

char ** get_arguments( char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = 1024;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, " ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, " ");
	}
	tokens[i] = NULL;

	return (tokens);


}
#define MAX_INPUT_SIZE 1024
/**
 * read_input_from_pipe - reads input
 * Return: the input
 */
char *read_input_from_pipe()
{
    char *input = (char *)malloc(MAX_INPUT_SIZE);
    ssize_t bytesRead;
    size_t inputSize = 0;
    char c;
    char *newInput;
    size_t buffer_size = MAX_INPUT_SIZE; // Separate buffer size variable

    if (input == NULL)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = read(STDIN_FILENO, &c, 1)) > 0)
    {
        if (inputSize >= buffer_size - 1)
        {
            size_t newSize = 2 * buffer_size; // Calculate the new size

            newInput = (char *)realloc(input, newSize);
            if (newInput == NULL)
            {
                perror("Failed to reallocate memory");
                free(input);
                exit(EXIT_FAILURE);
            }

            input = newInput;
            buffer_size = newSize; // Update the buffer size variable
        }

        input[inputSize++] = c;

        if (c == EOF || c == '\0')
        {
            break;
        }
    }

    input[inputSize] = '\0';

    return input;
}
