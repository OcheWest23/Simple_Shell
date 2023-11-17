#include "shell.h"

/**
 * display - creates or displays a prompt
 * Return: void
 */
void display(void)
{
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
		prints("$ ");
	free(buffer);
}
