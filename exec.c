#include "shell.h"

/**
 * execute_cmd - executes a command as a child process
 * @av: array of arguments
 * @args: array of parsed arguments
 * @environ: environment variables
 * @jay: The main function's status
 * @maxxis: Counts the command
 *
 * Return: 1 if successful
 */

int execute_cmd(char **av, char **args, char **environ, int jay, int maxxis)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			_error(av[0], maxxis, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (jay == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
