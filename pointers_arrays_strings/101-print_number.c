#include "main.h"

/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to print.
 *
 * Description: This function handles positive and negative integers
 * by recursively dividing the number and printing each digit. It only
 * uses the _putchar function for output.
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}
