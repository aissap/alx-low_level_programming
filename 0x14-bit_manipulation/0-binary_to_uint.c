#include "main.h"

/**
 * binary_to_unit - Convert a binary to unsigned int.
 * @b: the binary string to be converted.
 *
 * Returm : the correspending unsigned integer, or 0 if the input is invalid
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
