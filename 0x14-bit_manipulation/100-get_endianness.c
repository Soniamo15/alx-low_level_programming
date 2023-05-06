#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int test_num = 1;

	char *test_char = (char *) &test_num;

	return (*test_char);
}
