#include "main.h"

/**
 * print_unsigned - prints unsigned
 * @n: parameter
 * Return: integer
 */
int print_unsigned(unsigned int n)
{
	int count = 0;
	int i = 0;
	char n_arr[20];

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (n > 0)
	{
		n_arr[i++] = '0' + n % 10;
		n /= 10;
	}

	count += i;

	while (--i >= 0)
		_putchar(n_arr[i]);

	return (count);
}

/**
 * print_octal - prints octal as format specifier
 * @n: parameter
 * Return: (int) number of characters printed
 */
int print_octal(unsigned int n)
{
	int count = 0;
	int i = 0;
	char octal[20];

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (n > 0)
	{
		octal[i++] = '0' + n % 8;
		n /= 8;
	}

	count += i;

	while (--i >= 0)
		_putchar(octal[i]);

	return (count);
}

/**
 * print_hex - prints to hexadecimal
 * @n: first parameter
 * @uppercase: second parameter
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	int i = 0;
	int digit = 0;
	char hex[20];

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (n > 0)
	{
		digit = n % 16;
		if (digit < 10)
			hex[i++] = '0' + digit;
		else if (uppercase)
			hex[i++] = 'A' + digit - 10;
		else
			hex[i++] = 'a' + digit - 10;
		n /= 16;
	}

	count += i;

	while (--i >= 0)
		_putchar(hex[i]);

	return (count);
}
