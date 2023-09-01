#include "main.h"

/**
 * flip_bits - Count the number of different bits between two numbers.
 * @first_num: The first number.
 * @second_num: The second number.
 *
 * Return: The number of bits that differ between the two numbers.
 */
unsigned int flip_bits(unsigned long int first_num, unsigned long int second_num)
{
	unsigned long int differing_bits = first_num ^ second_num;
	int bit_count = 0;

	while (differing_bits > 0)
	{
	bit_count++;
	differing_bits &= (differing_bits - 1);
	}

	return (bit_count);
}
