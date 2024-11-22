#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * print_error - Imprime un mensaje de error y libera memoria asignada.
 * @result: Puntero al array dinámico que debe ser liberado.
 */
void print_error(int *result)
{
	if (result != NULL)
		free(result);
	printf("Error\n");
	exit(98);
}

/**
 * is_digit - Verifica si una cadena contiene solo dígitos.
 * @str: La cadena a verificar.
 *
 * Return: 1 si la cadena contiene solo dígitos, 0 en caso contrario.
 */
int is_digit(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * multiply - Multiplica dos números positivos representados como cadenas.
 * @num1: El primer número.
 * @num2: El segundo número.
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, *result, i, j, carry, n1, n2, sum;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
		print_error(NULL);

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
	{
		for (; i < len1 + len2; i++)
			printf("%d", result[i]);
	}
	printf("\n");

	free(result);
}

/**
 * main - Multiplica dos números positivos pasados como argumentos.
 * @argc: Cantidad de argumentos.
 * @argv: Vector de argumentos.
 *
 * Return: 0 si tiene éxito, o sale con el estado 98 en caso de error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		print_error(NULL);

	multiply(argv[1], argv[2]);

	return (0);
}
