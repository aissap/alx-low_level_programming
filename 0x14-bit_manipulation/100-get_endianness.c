#include "main.h"

/**
 * * get_endianness - Check the endianness of the system.
 *
 * Return: 0 if big-endian, 1 if little-endian.
 */
int get_endianness(void)
{
	unsigned int test_value = 1;
	char *test_prt = (char *) &test_value;

	return ((int) *test_prt);
}
