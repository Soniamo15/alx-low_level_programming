#include "main.h"
/**
 * _strlen - return the lenghtof a string
 * @s: string
 * Return: lenght
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}
