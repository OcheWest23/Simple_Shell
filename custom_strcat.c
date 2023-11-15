#include "shell.h"

/**
 * custom_strlen - Calculate the length of a string
 * @str: The input string
 * Return: The number of characters in the string
 */

size_t custom_strlen(const char *str)
{
	size_t lengthil = 0;

	while (str[lengthil] != '\0')
		lengthil++;

	return (lengthil);
}
