#include "shell.h"

/**
 *_calloc - Allocated memory for nmaxx element de size bytes
 *@nmaxx: The number of element in the array
 *@size: Size of bytes for each position in the array
 *Return: Pointer void
 */


void *_calloc(unsigned int nmaxx, unsigned int size)
{
	char *x;
	unsigned int y;

	if (nmaxx == 0 || size == 0)
		return (NULL);

	x = malloc(nmaxx * size);
	if (x == NULL)
		return (NULL);

	for (y = 0; y < nmaxx * size; y++)
		x[y] = 0;

	return (x);

}

/**
 *_puts - prints a string
 *@str: A to be printed
 *
 *Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * search - Reaches the path to execute the commands
 * @environ: Environment variable
 * Return: maxx_path (array of directories carrying the command)
 *	or NULL on failure
 **/
char **search(char **environ)
{
	int position = 0;
	char **maxx_path;

	for (; environ[position] != NULL ; position++)
	{
		if (environ[position][0] == 'P' && environ[position][2] == 'T')
		{
			maxx_path = _maxx(environ[position]);
		}
	}
	return (maxx_path);
}

/**
 * _itoa - Changes integer to ASCII
 * @num: number
 * @base: base
 * Return: character string
 **/
char *_itoa(int num, int base)
{
	static char *digits = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = (unsigned long)num;

	if (num < 0)
	{
		n = (unsigned long)(-num);
		sign = '-';
	}

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = digits[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * str_concat - Concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: Points to the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *place;
	unsigned int x, y, size;

	/* If the array is empty */
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";
	/* Count total size */

	size = (_strlen(s1) + _strlen(s2) + 1);

	/* Allocate memory */

	place = (char *) malloc(size * sizeof(char));

	if (place == 0)
	{
		return (NULL);
	}

	/* Concatenate arrays */
	for (x = 0; *(s1 + x) != '\0'; x++)
		*(place + x) = *(s1 + x);

	for (y = 0; *(s2 + y) != '\0'; y++)
	{
		*(place + x) = *(s2 + y);
		x++;

	}
	place[x] = '\0';
	return (place);

}
