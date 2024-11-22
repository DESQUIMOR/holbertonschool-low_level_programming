#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

/**
 * extract_word - Extracts a word from a string.
 * @str: The input string.
 * @start: The start index of the word.
 * @len: The length of the word.
 *
 * Return: A pointer to the new word, or NULL if memory allocation fails.
 */
char *extract_word(char *str, int start, int len)
{
	char *word;
	int i;

	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		word[i] = str[start + i];
	word[i] = '\0';

	return (word);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j = 0, len = 0, word_count, word_start;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			word_start = i;
			len = 0;
			while (str[i] != ' ' && str[i] != '\0')
			{
				len++;
				i++;
			}
			words[j] = extract_word(str, word_start, len);
			if (words[j] == NULL)
			{
				while (j > 0)
					free(words[--j]);
				free(words);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	words[j] = NULL;
	return (words);
}
