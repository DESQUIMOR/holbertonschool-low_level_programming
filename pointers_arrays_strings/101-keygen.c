#include "main.h"

/**
 * generate_key - Generates a random valid key for `101-crackme`
 * Description: Generates a password by calculating random characters
 *              based on specific constraints. Adjust as needed to meet
 *              the program's exact validation rules.
 */
void generate_key(void)
{
	char key[8];
	int i;
	unsigned int rand_seed = 12345;

	for (i = 0; i < 8; i++)
	{
		rand_seed = (rand_seed * 1103515245 + 12345) & 0x7fffffff;
		key[i] = (rand_seed % 26) + 'A';
		_putchar(key[i]);
	}
	_putchar('\n');
}

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	generate_key();
	return (0);
}
