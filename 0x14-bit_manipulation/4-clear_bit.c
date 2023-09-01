#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @num: pointer to the number to change
 * @index: index of the bit to clear
 *
 * Return: 1 it succed -1 it fails
 */
int clear_bit(unsigned long int *num, unsigned int index)
{
	if (index >= 64)
	{
		return (-1);
	}
	*num = *num & ~(1 << index);

	return (1);
}
