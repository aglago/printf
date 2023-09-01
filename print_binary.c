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
	int leading_zeros = 1;


	/*binary representation has 22 characters*/
	for (i = 31; i >= 0; i--)
	{
		bit = (n >> i) & 1;

		if (bit == 0 && leading_zeros)
			continue;

		count += _putchar('0' + bit);
		leading_zeros = 0;
	}

	if (count == 0)
		count += _putchar('0');

	return (count);
}
