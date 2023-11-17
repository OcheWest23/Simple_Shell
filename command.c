#include"shell.h"
/**
 * execute_command - handle commands
 * @command: command to handle
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[MAX_INPUT_LENGTH];
	int status, i = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
