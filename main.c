#include"shell.h"
/**
 * main - execute the shell program
 * Return: 0
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *prompt = "#cisfun$ ";

	while (1)
	{
		printf("%s", prompt);
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strlen(input) > 0)
			execute_command(input);
	}
	return (0);
}
