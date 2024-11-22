#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * _is_digit - Checks if a string is composed only of digits.
 * @str: The string to check.
 *
 * Return: 1 if the string is composed only of digits, 0 otherwise.
 */
int _is_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * print_error - Prints an error message and exits with status 98.
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - Multiplies two positive numbers represented as strings.
 * @num1: The first number.
 * @num2: The second number.
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1), len2 = _strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	int i, j, carry, n1, n2, sum;

	if (result == NULL)
		print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;
	if (i == len1 + len2)
		printf("0");
	else
		for (; i < len1 + len2; i++)
			printf("%d", result[i]);
	printf("\n");
	free(result);
}

/**
 * main - Multiplies two positive numbers from command-line arguments.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or exit with status 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !_is_digit(argv[1]) || !_is_digit(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}
