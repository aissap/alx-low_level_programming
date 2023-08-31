#include "main.h"

/**
 * * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */
void print_binary(unsigned long int n){

	int bit = sizeof(n) * 8; //number of bits in n

	while (bit--){
		_putchar((n >> bit)& 1 ? '1' : '0');// Print the bit at the current position
	}
}
