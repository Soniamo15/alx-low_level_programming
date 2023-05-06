#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @num: number to search
 * @bit_index: index of the bit
 *
 * Return: value of the bit at the specified index
 */
int get_bit(unsigned long int num, unsigned int bit_index)
{
	int bit_val;

	if (bit_index > 63)
	{
		return (-1);
	}

	bit_val = (num >> bit_index) & 1;

	return (bit_val);
}
