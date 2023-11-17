#include "shell.h"

/**
 * _maxx - Indicates the path of the command (fpath)
 * that is being passed to it
 * @fpath: the command that is being passed to it
 *
 * Return: an array of directories containing the command or NULL on failure
 */
char **_maxx(char *fpath)
{
	int size = 64;
	int i = 0;
	char *copy_path = NULL;
	char *delim = ":=";

	char **dirs = _calloc(sizeof(char *), size);
	char *token = NULL;

	if (fpath == NULL)
	{
		free(fpath);
		return (0);
	}
	if (dirs == NULL)
	{
		free(fpath);
		perror("Error allocated memory");
		return (NULL);
	}
	copy_path = _strdup(fpath); /* Copy the fpath string */
	token = strtok(copy_path, delim); /* Split the string by the delimiter */

	while (token != NULL)
	{
		dirs[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	return (dirs);
}
