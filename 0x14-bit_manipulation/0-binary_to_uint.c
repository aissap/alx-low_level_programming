#include "main.h"
#include <stddef.h>


/**
* binary_to_unit - convert a binary number to an unsigned int
* @b: pointer to a string of 0 and 1 chars
*
* Return: the converted number, in case there is an invalid character return 0
*/


unsigned int binary_to_unit(const char *b)
{
	unsigned int num = 0;
	int i;

	if (b == NULL)
		return (0);

	/* Traverse the charachters in the given string*/

	for (i = 0; b[i] != '\0'; i++)
	{
		/* verify if characters are not valid binary digits*/

		if (b[i] != '0' && b[i] != '1')
			return (0);

		/* Calculate the result */

		num  = num * 2 + (b[i] - '0');
	}
	return (num);
}
