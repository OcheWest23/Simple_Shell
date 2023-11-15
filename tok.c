#include "shell.h"

void handle_exit(char **maxx, char *line);

/**
 * split_str - Carries out spliting of the string
 * @line: The string to be tokenized
 * @env: Environment variables
 *
 * Return: An array of tokens
 */
char **split_str(char *line, char **env)
{
	char *tokenized_sentence, *separator = " \t\r\n\a";
	char **maxx;
	int max_maxx = 64, tonga = 0;

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
		maxx[tonga] = tokenized_sentence;
		tonga++;
		tokenized_sentence = strtok(NULL, separator);
	}

	if (maxx[0] == NULL)
		maxx[tonga] = "\n";

	if (_strcmp(maxx[0], "exit") == 0)
	{
		if (maxx[1] != NULL)
			handle_exit(maxx, line);

		else
			handle_exit(maxx, line);
	}
	if ((_strcmp(maxx[0], "env") == 0) && maxx[1] == NULL)
		printenv(env);

	return (maxx);

}


/**
 * handle_exit - Controls and takes care of exit
 * @maxx:  maxx which is nlice
 * @line: line line in the mirrorie
 * Returns: nothing
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
 * _atoi - Changes character (char) to int
 * @a: Character to be converted
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
