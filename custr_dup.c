#include "shell.h"

/**
 * custom_strdup - Duplicate a string
 * @str: The string to be duplicated
 * Return: A duplicated string
 */
char *custom_strdup(const char *str)
{
	size_t length = custom_strdup(str) +1;
	char *curr_str = (char *)malloc(length);
	size_t l = 0;

	if (curr_str == NULL)
		return (NULL);

	for (; l < length; l++)
		curr_str[l];
	return (curr_str);
}
