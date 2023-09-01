#include "main.h"

/**
 * print_binary - Print the binary representation of a decimal number
 * @decimal: the decimal number to be converted and printed
 */
void print_binary(unsigned long int decimal)
{
	int index, bit_count = 0;
	unsigned long int current_bit;

	for (index = 63; index >= 0; index--)
	{
		current_bit = decimal >> index;

		if (current_bit & 1)
		{
			_putchar('1');
			bit_count++;
		}
		else if (bit_count)
		{
			_putchar('0');
		}
	}
	if (!bit_count)
	{
		_putchar('0');
	}
}
