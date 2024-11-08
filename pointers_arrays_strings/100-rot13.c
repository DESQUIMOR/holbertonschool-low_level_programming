#include "main.h"

/**
 * rot13 - Encodes a string using ROT13.
 * @s: The input string to encode.
 *
 * Description: This function takes a string and encodes it using ROT13,
 * which shifts each letter by 13 positions in the alphabet. It preserves
 * the case of each letter and leaves non-alphabetic characters unchanged.
 *
 * Return: The encoded string.
 */
char *rot13(char *s)
{
	char *p = s;
	char rot13_map[52] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char alphabet[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int i;

	while (*p)
	{
		for (i = 0; i < 52; i++)
		{
			if (*p == alphabet[i])
			{
			*p = rot13_map[i];
			break;
			}
		}
		p++;
	}
	return (s);
}
