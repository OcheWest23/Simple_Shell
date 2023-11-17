#include "shell.h"

void handle_exit(char **maxx, char *line);

/**
 * splitter_str - Helps to splits string
 * @line: string to be tokenized
 * @environ: environment variables
 *
 * Return: array of tokens
 */
char **splitter_str(char *line, char **environ)
{
	char *tokenized_sentence, *separator = " \t\r\n\a";
	char **maxx;
	int max_maxx = 64, maxxis = 0;

	if (line == NULL)
	{
		return (0);
	}
	maxx = _calloc(sizeof(char *), max_maxx);
	if (maxx == NULL)
	{
		prints("error");
		exit(EXIT_FAILURE);
	}

	tokenized_sentence = strtok(line, separator);
	while (tokenized_sentence != NULL)
	{
		maxx[maxxis] = tokenized_sentence;
		maxxis++;
		tokenized_sentence = strtok(NULL, separator);
	}

	if (maxx[0] == NULL)
		maxx[maxxis] = "\n";

	if (_strcmp(maxx[0], "exit") == 0)
	{
		if (maxx[1] != NULL)
			handle_exit(maxx, line);

		else
			handle_exit(maxx, line);
	}
	if ((_strcmp(maxx[0], "env") == 0) && maxx[1] == NULL)
		printenv(environ);

	return (maxx);

}


/**
 * handle_exit - Function handles the exit
 * @maxx:  maxx which is not bad
 * @line: line line in the mirrori
 * Returns: void
 *
 */

void handle_exit(char **maxx, char *line)
{
	int status = 0;

	if (maxx[1] != NULL)
	{
		status = _atoi(maxx[1]);
		if (status == 0 && _strcmp(maxx[1], "0") != 0)
			status = 2;
	}

	free(line);
	free(maxx);
	exit(status);
}

/**
 * _atoi - converts char to int
 * @a: char to be converted
 * Return: int
 */

int _atoi(char *a)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (a[i] == ' ')
	{
		i++;
	}

	if (a[i] == '-' || a[i] == '+')
	{
		sign = (a[i] == '-') ? -1 : 1;
		i++;
	}

	while (a[i] > '\0' && a[i] <= '9')
	{
		result = result * 10 + (a[i] - '0');
		i++;
	}

	return (result * sign);
}
