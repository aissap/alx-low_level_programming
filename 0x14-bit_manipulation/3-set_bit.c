#include "main.h"

/**
 * set_bit - Modify a specific bit in a number to 1.
 * @num: pointer  to the number to be modified.
 * @bit_index: index of thr bit to br set to 1.
 * Return: 1 if it  succed , -1 if it fails.
 */
int set_bit(unsigned long int *num, unsigned int bit_index)
{
	if (bit_index >= 64)
	{
		return (-1);
	}

	*num = *num | (1 << bit_index);
	return (1);
}
