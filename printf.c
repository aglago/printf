#include "main.h"
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...)
{
	int i, err, byte;
	va_list arg;

	if (format == NULL)
		return (-1);
	byte = 0;
	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			err = formatting(&arg, &format[++i], &byte, &i);	
			if (err == -2)
				return (err);
		}
		write(1, &format[i], 1);
		byte += 1;
	}

	va_end(arg);
	return (byte);
}

int formatting(va_list *args, const char *format, int *len, int *i)
{
	int slen, n;
	char t, *tmp;

	slen = 0;
	if (*format == 'c')
	{
		t = (char) va_arg(args, int);
		write(1, &t, 1);
		*i += 1;
		*len += 1;
	}
	else if (*format == 's')
	{
		tmp = va_arg(args, char *);
		if (tmp == NULL)
			return (-2);
		slen = _strlen(tmp);
		write(1, tmp, slen);
		*i += 1;
		*len += slen;
	}
	else if (*format == 'd' || *format == 'i')
	{
		n = va_arg(args, int);
		tmp = int_formatting(n);
		slen = _strlen(tmp);
		write(1, tmp, slen);
		*i += 1;
		*len += slen;
		free(tmp);
	}
	return (0);
}

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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
		number[i] = '-';
	for (i = d + isnegative - 1; i >= isnegative; i--)
	{
		number[i] = '0' + (n % 10);
		n /= 10;
	}
	number[d + isnegative] = '\0';
	return (number);
}
