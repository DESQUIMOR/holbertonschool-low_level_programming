#include <stdio.h>

/**
 * main - Entry point, prints the first 98 Fibonacci numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned int high1 = 0, low1 = 1; /* First Fibonacci number (1) */
	unsigned int high2 = 0, low2 = 2; /* Second Fibonacci number (2) */
	unsigned int high, low;
	int count;

	printf("%u, %u", low1, low2);

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
			printf(", %u%09u", high, low);
		else
			printf(", %u", low);

		high1 = high2;
		low1 = low2;
		high2 = high;
		low2 = low;
	}

	printf("\n");
	return (0);
}
