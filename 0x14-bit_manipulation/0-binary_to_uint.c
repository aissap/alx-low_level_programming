#include "main.h"

/**
* binary_to_unit - convert a binary number to an unsigned int
* @b: pointer to a string of 0 and 1 chars
*
* Return: the converted number, in case there is an invalid character return 0
*/


unsigned int binary_to_unit(const char *b)
{
	unsigned int number = 0;

	if (!b)
		return (0);
	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		/* Calculate the result */
		
		number  = number * 2 + (*b++ - '0');
	}
	return (number);
}
