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
	}
	return (0);
}
