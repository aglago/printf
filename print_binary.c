#include "main.h"

/**
 * print_binary - prints decimals in binary
 * @n: decimal number to be converted to binary
 * Return: returns the number of characters printed
 */

int print_binary(unsigned int n)
{
	int count = 0;

	if (n > 1)
		print_binary(n / 2);
	count += _putchar('0' + n % 2);
	return (count);
}
