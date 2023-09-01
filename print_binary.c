#include "main.h"

/**
 * print_binary - prints decimals in binary
 * @n: decimal number to be converted to binary
 * Return: returns the number of characters printed
 */

int print_binary(unsigned int n)
{
	int count = 0;
	int i = 0;
	int bit = 0;

	/*binary representation has 22 characters*/
	for (i = 21; i >= 0; i--)
	{
		bit = (n >> i) & 1;
		count += _putchar('0' + bit);
	}

	return (count);
}
