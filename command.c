#include"shell.h"
/**
 * execute_command - execute the command
 * @command: pointer to command
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[2];
	int status;

	args[0] = command;
	args[1] = NULL;
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
