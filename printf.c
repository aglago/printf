#include "main.h"

/**
 * _printf - prints formatted input to stdout
 * @format: string
 * Return: no of bytes printed
 */

int _printf(const char *format, ...)
{
	int err, byte;
	va_list arg;

	if (format == NULL)
		return (-1);
	byte = 0;
	va_start(arg, format);
	err = formatting(arg, format, &byte);
		if (err == -2)
			return (err);
	va_end(arg);
	return (byte);
}

/**
 * formatting - handles the printing
 * @args: variable argument list
 * @format: format string
 * @len: address of total byte
 * Return: probable error message
 */

int formatting(va_list args, const char *format, int *len)
{
	int i, n, slen = 0;
	char t, *tmp;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				t = (char) va_arg(args, int);
				write(1, &t, 1);
				i += 1;
				*len += 1;
			}
			else if (format[i] == 's')
			{
				tmp = va_arg(args, char *);
				if (tmp == NULL)
					return (-2);
				slen = _strlen(tmp);
				write(1, tmp, slen);
				i += 1;
				*len += slen;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				n = va_arg(args, int);
				tmp = int_formatting(n);
				slen = _strlen(tmp);
				write(1, tmp, slen);
				i += 1;
				*len += slen;
				free(tmp);
			}
		}
		write(1, &format[i], 1);
		*len += 1;
	}
		return (0);
}

/**
 * _strlen - gets the length of a string
 * @s: string
 * Return: calculated length
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * int_formatting - converts int to printable format
 * @n: int
 * Return: int as a string of chars
 */

char *int_formatting(int n)
{
	int i, isnegative, d = 0;
	char *number;

	isnegative = 0;
	if (n < 0)
	{
		isnegative = 1;
		n *= -1;
	}
	i = n;
	while (i > 0)
	{
		i /= 10;
		d++;
	}
	number = malloc(sizeof(char) * (d + isnegative + 1));
	if (isnegative == 1)
		number[0] = '-';
	for (i = d + isnegative - 1; i >= isnegative; i--)
	{
		number[i] = '0' + (n % 10);
		n /= 10;
	}
	number[d + isnegative] = '\0';
	return (number);
}
