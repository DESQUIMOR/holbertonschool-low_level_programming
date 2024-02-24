#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 1
 *
 * Return: Always 0
 */
int main(void)
{
	int i, overflow;
	unsigned long int fib1 = 1, fib2 = 1, fib3;

	printf("%lu", fib1);

	for (i = 1; i < 98; i++)
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

		if (overflow)
		{
			printf(", 0");
		}
		else
		{
			printf(", %lu", fib3);
		}

		fib1 = fib2;
		fib2 = fib3;
	}

	printf("\n");

	return (0);
}
