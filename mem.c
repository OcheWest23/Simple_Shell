#include "shell.h"

/**
 * _maxx - Shows the path of the command (maxxpath)
 * which is being passed to it
 * @maxxpath: Represents the command that is being passed to it
 *
 * Return: an array of directories containing the command or NULL on failure
 */
char **_maxx(char *maxxpath)
{
	int size = 64;
	int x = 0;
	char *copy_path = NULL;
	char *delim = ":=";

	char **dirs = _calloc(sizeof(char *), size);
	char *token = NULL;

	if (maxxpath == NULL)
	{
		free(maxxpath);
		return (0);
	}
	if (dirs == NULL)
	{
		free(maxxpath);
		perror("Error allocated memory");
		return (NULL);
	}
	copy_path = _strdup(maxxpath); /* Copies the maxxpath string */
	token = strtok(copy_path, delim); /* Split the string by the delimiter */

	while (token != NULL)
	{
		dirs[x] = token;
		x++;
		token = strtok(NULL, delim);
	}
	return (dirs);
}
