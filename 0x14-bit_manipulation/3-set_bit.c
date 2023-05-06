#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @num_ptr: pointer to the number to change
 * @bit_index: index of the bit to set to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *num_ptr, unsigned int bit_index)
{
	if (bit_index > 63)
	{
		return (-1);
	}

	*num_ptr = ((1UL << bit_index) | *num_ptr);

	return (1);
}
