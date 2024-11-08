#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a valid password for `101-crackme`
 *
 * Description: Generates a random password with ASCII values summing
 *              to the target required by 101-crackme.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int target_sum = 2772;
	int sum = 0;
	char password[100];
	int i = 0;

	srand(time(NULL));

	while (sum < target_sum - 126)
	{
		password[i] = (rand() % 94) + 33;
		sum += password[i];
		putchar(password[i]);
		i++;
	}

	password[i] = target_sum - sum;
	putchar(password[i]);
	putchar('\n');

	return (0);
}
