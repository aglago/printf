#include "main.h"

/**
 * print_num - prints integers
 * @n: number to print
 * Return: number of numbers printed
 */
int print_num(int n)
{
	int i, count = 0;
	char *min_int;
	char n_arr[20]; /* up to 20 digits */

	if (n == INT_MIN)
	{
		min_int = "-2147483648";
		count += _puts(min_int);
		return (count);
	}

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	i = 0;
	while (n > 0)
	{
		n_arr[i++] = '0' + n % 10;
		n /= 10;
	} /* printing digits into array */

	count += i; /* taking size of array */

	while (--i >= 0)
		_putchar(n_arr[i]);

	return (count);
}
