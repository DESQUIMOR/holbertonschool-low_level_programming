#include <stdio.h>

/**
 * main - Sum Fibonacci numbers.
 *
 * Return: Always 0.
 */
int main(void)
{
	int prev = 1;
	int current = 2;
	int temp;
	int sum = 2;

	while (current <= 4000000)
	{
		temp = current;
		current = prev + current;
		prev = temp;

		if (current % 2 == 0)
		{
			sum += current;
		}
	}

	printf("%d\n", sum);

	return (0);
}
