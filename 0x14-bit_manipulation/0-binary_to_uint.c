#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary string to be converted.
 *
 * Return: The converted unsigned int, or 0 if invalid inpt.
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int r = 0;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		r = 2 * r + (b[i] - '0');
	}
	return (r);
}
