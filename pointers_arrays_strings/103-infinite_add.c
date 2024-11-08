#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings.
 * @n1: The first number string.
 * @n2: The second number string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 *
 * Description: This function takes two strings representing large numbers
 * and adds them digit by digit from the least significant to the most.
 * The result is stored in the buffer `r` in reverse order and then reversed
 * back to get the correct number representation.
 *
 * Return: Pointer to the result (r), or 0 if the result can't be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, carry = 0, sum = 0;
	int len1 = 0, len2 = 0;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	len1--;
	len2--;
	k = 0;

	while (len1 >= 0 || len2 >= 0 || carry != 0)
	{
		if (k >= size_r - 1)
			return (0);

		sum = carry;
		if (len1 >= 0)
			sum += n1[len1--] - '0';
		if (len2 >= 0)
			sum += n2[len2--] - '0';

		carry = sum / 10;
		r[k++] = (sum % 10) + '0';
	}

	r[k] = '\0';

	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char temp = r[i];

		r[i] = r[j];
		r[j] = temp;
	}

	return (r);
}
