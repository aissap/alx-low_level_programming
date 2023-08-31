#include "main.h"

/**
 * binary_to_unit - convert a binary number to unsigned int
 * Return : the unsigned int form of b
 */
unsigned int binary_to_unit(const char *b)
{
	unsigned int num = 0;
	
	if (!b) //check if the input string is NULL
	return 0;

	while (*b) //Iterate through each character in the string
	{
		char c = *b;
		if (c != '0' && c != '1')
			return 0; //Invalid binary
		num = num * 2 + (c - '0');
		b++; // move to the next character
	}
	return num;

}
