#include <stdio.h>

/**
 * print_hex - Prints the hexadecimal content of a buffer.
 * @b: Pointer to the buffer.
 * @start: Starting index in the buffer.
 * @size: The size of the buffer.
 */
void print_hex(char *b, int start, int size)
{
	int j;

	for (j = 0; j < 10; j++)
	{
		if (start + j < size)
			printf("%02x", b[start + j]);
		else
			printf("  ");

		if (j % 2 != 0)
			printf(" ");
	}
}

/**
 * print_ascii - Prints the ASCII content of a buffer.
 * @b: Pointer to the buffer.
 * @start: Starting index in the buffer.
 * @size: The size of the buffer.
 */
void print_ascii(char *b, int start, int size)
{
	int j;
	char c;

	for (j = 0; j < 10 && (start + j) < size; j++)
	{
		c = b[start + j];
		if (c >= 32 && c <= 126)
			printf("%c", c);
		else
			printf(".");
	}
}

/**
 * print_buffer - Prints the content of a buffer in hexadecimal and ASCII.
 * @b: Pointer to the buffer.
 * @size: The size of the buffer.
 */
void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		print_hex(b, i, size);

		print_ascii(b, i, size);

		printf("\n");
	}
}
