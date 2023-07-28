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
				tmp = checknull(tmp);
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
			if (format[i] == '\0')
				break;
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
	int i, isnegative, d;
	char *number;

	isnegative = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			number = malloc(sizeof(char) * 12);
			if (number == NULL)
				return (NULL);
			_strcpy(number, "-2147483648");
			return (number);
		}
		isnegative = 1;
		n *= -1;
	}
	d = (n == 0) ? 1 : 0;
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

#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: destination string
 */

void _strcpy(char *dest, char *src)
{
	int i, length;

	for (i = 0, length = 0; src[i] != '\0'; i++)
		length++;
	for (i = 0; i <= length; i++)
		dest[i] = src[i];
}

char *checknull(char *fmt)
{
	if (fmt == NULL)
	{
		fmt = malloc(sizeof(char) * 7);
		_strcpy(fmt, "(null)");
	}
	return (fmt);
}
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	len2 = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
