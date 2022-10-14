#include "main.h"

/**
  * _strncat - Concatenates two strings
  * @dest: The destination value
  * @src: The source value
  * @n: The limit of the concatenation
  *
  * Return: A pointer to the resulting string dest
  */
char *_strncat(char *dest, char *src, int n)
{
	int l = 0, i = 0;

	while (dest[l])
	{
		l++;
	}

	while (i < n && src[i])
	{
		dest[l] = src[i];
		l++;
		i++;
	}

	dest[l + n + 1] = '\0';

	return (dest);
}
