#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
	int i, overflow;
	unsigned long int fib1 = 1, fib2 = 2, fib3;

	printf("%lu, %lu", fib1, fib2);

	for (i = 0; i < 96; i++)
	{
		fib3 = fib1 + fib2;

		if (fib3 < fib2)
		{
			overflow = 1;
		}
		else
		{
			overflow = 0;
		}

		fib1 = fib2;
		fib2 = fib3;

		if (overflow)
		{
			printf(", 0");
		}
		else
		{
			printf(", %lu", fib3);
		}
	}

	printf("\n");

	return (0);
}
