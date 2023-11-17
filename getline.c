#include"shell.h"
/**
 * get_input - read line of input from user or stdin
 * Return: dynamically allocated string containing input
 */
char *get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_result;
	char temp_input[MAX_INPUT_LENGTH];

	if (isatty(fileno(stdin)))
		printf("#cisfun$ ");

	if (isatty(fileno(stdin)))
	{
		read_result = getline(&input, &input_size, stdin);
		if (read_result == -1 || read_result == EOF)
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
