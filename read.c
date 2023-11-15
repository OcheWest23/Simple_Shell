#include "shell.h"

/**
 * read_input - Saves anything passed to it as standard input
 *
 * Return: String holding the input
 */
char *read_input(void)
{
	char *line = NULL;
	ssize_t bytes_read;
	size_t bufsize;
	int x;

	bufsize = 0;
	bytes_read = getline(&line, &bufsize, stdin);
	if (!line)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	if (bytes_read == 1)
	{
		free(line);
		return (NULL);
	}
	else if (bytes_read == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}
	else
	{
		for (x = 0; line[x] == ' ' && line[x + 1] == ' '; x++)
			;
		if (!line[x] && line[x + 1] == '\n')
		{
			free(line);
			return (0);
		}
	}

	return (line);
}
