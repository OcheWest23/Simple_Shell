#include "shell.h"

/**
 * main - Main function of the simple shell. Creates a prompt that reads input,
 *            parses it, executes commands,
 * and waits for another command unless told to exit.
 * @ac: The number of arguments passed to the program.
 * @av: An array of arguments passed to the program.
 * @_stat: Argument path
 * @env: The environment variables.
 * Return: 0 If successful.
 */

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args, **path;
	int maxx = 0, tonga = 0;
	(void) av;
	signal(SIGINT, handle_signal);

	for (;;)
	{
		prompt();
		line = read_input();
		args = split_str(line, env);
		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			maxx += 1;
			path = search(env); /* Search for PATH in the environment variable */
			tonga = _maxxstat(args, path);
			execute_cmd(av, args, env, tonga, maxx);
		}
		else
		{
			free(args);
		}
		free(line);
	}
	return (0);
}
