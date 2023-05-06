#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @num1: first number
 * @num2: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive_or = num1 ^ num2;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive_or >> i;
		if (current & 1)
		{
			count++;
		}
	}

	return (count);
}
