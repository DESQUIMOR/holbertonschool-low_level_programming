#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: Double pointer to be updated
 * @to: The string to set the pointer to
 *
 * Description: This function sets the value of a pointer to a char
 * by making the double pointer point to the same address as `to`.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
