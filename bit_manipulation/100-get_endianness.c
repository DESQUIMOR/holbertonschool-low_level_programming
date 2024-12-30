#include "main.h"

/**
 * get_endianness - Check the endianness of the system.
 *
 * This function determines whether the machine is little-endian or
 * big-endian by analyzing the memory representation of an integer.
 *
 * Return: 0 if the system is big-endian, 1 if little-endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *ptr = (char *)&num;

	return (*ptr);
}
