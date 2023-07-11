/**
 * binary_to_uint - convert binary string to an int
 * @c: string containing the binary number
 * Return: converted number or 0
 */
unsigned int binary_to_uint(const char *c)
{
	unsigned int decimal = 0;

	for (; c && *c; c++)
	{
		decimal *= 2;
		if (*c == '1' || *c == '0')
			decimal += *c - '0';
		else
			return (0);
	}
	return (decimal);
}
