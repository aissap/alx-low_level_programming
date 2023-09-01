#include "main.h"

/**
 * binary_to_uint - Convert a binary number to an unsigned int.
 * @b: The binary string to be converted.
 * Return: The converted unsigned int, or 0 if its an invalid input
 */
unsigned int binary_to_unit(const char *b)
{
	unsigned int num;
	int l, base2;
	if (!b)
		return (0);

	num = 0;
	
	for (l = 0; b[l] != '\0'; l++);

	for (l--, base2 = 1; l >= 0; l--, base2 *= 2)
	{
		if (b[l] != '0' && b[l] != '1')
		{
			return (0);
		}
		if (b[l] & 1)
		{
			num += base2;
		}
	}
	return (num);
}
