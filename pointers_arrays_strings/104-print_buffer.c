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

	for (j = 0; j < 10; j++)
	{
		if (start + j < size)
		{
			c = b[start + j];

			/* Print printable ASCII characters or '.' for non-printables */
			if (c >= 32 && c <= 126)
				printf("%c", c);
			else
				printf(".");
		}
		else
		{
			printf(" ");
		}
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
		/* Print the position in hexadecimal (8 characters, zero-padded) */
		printf("%08x: ", i);

		/* Print the hexadecimal content */
		print_hex(b, i, size);

		/* Print the ASCII representation */
		print_ascii(b, i, size);

		printf("\n");
	}
}
