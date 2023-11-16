#include "shell.h"

/**
 * handle_signal - handles EOF signal
 * @signal: EOF indicator
 * Return: void
 */

void handle_signal(int signal)
{
	(void) signal;
	prints("\n$$$ ");
	fflush(stdout);
}

/**
 * maxx_error - Creates/prints an error output of a file
 * @argv: Program's name
 * @count: Number of prompt
 * @args: The command to input
 * Return: 0 if successful
 */
int *maxx_error(char *argv, int count, char *args)
{
	char *num;

	num = _itoa(count, 10);

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, num, _strlen(num));
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	perror(" ");

	return (0);
}

/**
 * _maxxstat - Create status of a file
 * @cmd: Array of commands
 * @joined: The array of directory paths
 * Return: 1 if successful
 **/
int _maxxstat(char **cmd, char **tonga)
{
	char *concat_str = NULL, *new_concat = NULL;
	int maxx;
	struct stat sb;

	if (tonga == NULL)
	{
		free(tonga);
		free(cmd);
		return (0);
	}
	for (maxx = 0; tonga[maxx] != NULL ; maxx++)
	{
		concat_str = str_concat(tonga[maxx], "/");
		new_concat = str_concat(concat_str, cmd[0]);

		if (stat(new_concat, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			cmd[0] = new_concat;
			free(concat_str);
			free(tonga[0]);
			free(tonga);
			return (1);
		}

		free(concat_str);
		free(new_concat);
	}
	free(tonga[0]);
	free(tonga);
	return (0);
}
