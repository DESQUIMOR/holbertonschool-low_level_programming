#include <stdio.h>

/**
 * main - Entry point, prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long high1 = 0, low1 = 1; /* First Fibonacci number (1) */
	unsigned long high2 = 0, low2 = 2; /* Second Fibonacci number (2) */
	unsigned long high, low;
	int count;

	printf("%lu, %lu", low1, low2);

	for (count = 3; count <= 98; count++)
	{
		high = high1 + high2;
		low = low1 + low2;

		if (low >= 1000000000)
		{
			low -= 1000000000;
			high += 1;
		}

		if (high != 0)
			printf(", %lu%09lu", high, low);
		else
			printf(", %lu", low);

		high1 = high2;
		low1 = low2;
		high2 = high;
		low2 = low;
	}

	printf("\n");
	return (0);
}
