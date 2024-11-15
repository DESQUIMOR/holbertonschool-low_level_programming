#include <stdio.h>

/**
 * main - Creates a file with the exact password for crackme2
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	FILE *file;
	const char *password = "your_discovered_password";

	file = fopen("password.txt", "w");
	if (!file)
	{
		perror("Error opening file");
		return (1);
	}

	fputs(password, file);

	fclose(file);
	return (0);
}
