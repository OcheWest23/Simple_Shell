#include"shell.h"
/**
 * get_input - read a line of input
 * Return: dynamically allocated string
 */
char *get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t result;
	char temp_input[MAX_INPUT_LENGTH];

	if (isatty(fileno(stdin)))
		printf("#cisfun$ ");
	if (isatty(fileno(stdin)))
	{
		result = getline(&input, &input_size, stdin);
		if (result == -1 || result == EOF)
		{
			if (isatty(fileno(stdin)))
				printf("\n");
			free(input);
			return (NULL);
		}
		input[strcspn(input, "\n")] = '\0';
		return (input);
	}
	else
	{
		if (fgets(temp_input, sizeof(temp_input), stdin) == NULL)
			return (NULL);
		temp_input[strcspn(temp_input, "\n")] = '\0';
		return (strdup(temp_input));
	}
}
