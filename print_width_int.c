#include "main.h"

/**
 * print_width_int - pads our print num function with spaces
 * @c: char containing width information
 * @n: int to print
 * @counter: address of the number of bytes counter
 */
void print_width_int(char c, int n, int *counter)
{
	int i, sp_len, width, copy, digits;

	width = c - '0'; /* set c to an int */
	digits = (n == 0) ? 1 : 0;
	copy = n;
	if (copy < 0)
	{
		copy *= -1;
		digits++;
	}
	while (copy > 0)
	{
		copy /= 10;
		digits++;
	}
	if (digits >= width)
		*counter += print_num(n);
	else
	{
		sp_len = width - digits;
		for (i = 0; i < sp_len; i++)
			_putchar(' ');
		*counter += sp_len;
		*counter += print_num(n);
	}
}
