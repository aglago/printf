#include "main.h"

/**
 * print_binary - prints decimals in binary
 * @n: decimal number to be converted to binary
 */

void print_binary(unsigned int n)
{
	if (n > 1)
		print_binary(n / 2);
	_putchar('0' + n % 2);
}
