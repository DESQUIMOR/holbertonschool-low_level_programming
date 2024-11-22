#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program into a single string.
 * @ac: The number of arguments.
 * @av: The array of arguments.
 *
 * Description: Each argument is followed by a newline character in the new
 * string. If `ac == 0` or `av == NULL`, the function returns NULL.
 *
 * Return: A pointer to the new string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, total_len = 0;
	char *result;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			total_len++;
		total_len++;
	}

	result = malloc(sizeof(char) * (total_len + 1));
	if (result == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[k++] = av[i][j];
		}
		result[k++] = '\n';
	}
	result[k] = '\0';

	return (result);
}
