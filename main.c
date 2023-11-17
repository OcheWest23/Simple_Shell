<<<<<<< HEAD
#include "shell.h"

/**
 * main - Simple Shell main function. Creates a prompt that reads input,
 *            parses it, executes commands,
 * and waits for another command unless told to exit.
 * @ac: The number of arguments passed to the program.
 * @av: An array of arguments passed to the program.
 * @env: The environment variables.
 * Return: 0 upon successful execution.
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args, **path;
	int maxxis = 0, jayzzi = 0;
	(void) av;
	signal(SIGINT, handle_signal);

	for (;;)
	{
		display();
		line = save_input();
		args = splitter_str(line, env);
		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			maxxis += 1;
			path = find(env); /* Search for PATH in the environment variable */
			jayzzi = _stat(args, path);
			execute_cmd(av, args, env, jayzzi, maxxis);
		}
		else
		{
			free(args);
		}
		free(line);
=======
#include"shell.h"
/**
 * main - runs the shell program
 * Return: 0
 */
int main(void)
{
	char *input;

	while (1)
	{
		input = get_input();
		if (input == NULL || strlen(input) == 0)
			break;

		if (strcmp(input, "exit") == 0)
			exit_shell();

		if (strcmp(input, "env") == 0)
			print_env();

		execute_command(input);
		free(input);
>>>>>>> 3a99a0eaa0203c586d9814d1e35880e73bf65730
	}
	return (0);
}
