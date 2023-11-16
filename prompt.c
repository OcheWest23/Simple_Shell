#include "shell.h"

/**
 * prompt - Displays prompt
 * Return: void
 */
void prompt(void)
{
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
		prints("$ ");
	free(buffer);
}

