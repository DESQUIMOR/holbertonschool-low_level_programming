#include <limits.h>
/**
 * _atoi - convierte una cadena en un entero
 * @s: cadena a convertir
 *
 * Return: entero convertido
 */
int _atoi(char *s)
{
	int sign = 1, res = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign = -sign;
		} else if (*s >= '0' && *s <= '9')
		{
			int digit = (*s - '0');

			if (res > INT_MAX / 10 || (res == INT_MAX / 10 &&
						digit > INT_MAX % 10))
			{
				return ((sign == 1) ? INT_MAX : INT_MIN);
			}
			res = res * 10 + digit;
		} else if (res != 0)
		{
			break;
		}
		s++;
	}

	return (sign * res);
}
