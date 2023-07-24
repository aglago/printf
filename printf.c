#include "main.h"

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

int formatting(va_list args, const char *format, int *len)
{
	int i, slen, n;

	for (i = 0; format[i] != '\0'; i++)
	{
		char t, *tmp;
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case '%':
					break;
				case 'c':
					t = va_arg(args, int);
					write(1, &t, 1);
					i++;
					*len += 1;
					break;
				case 's':
					tmp = va_arg(args, char *);
					if (tmp == NULL)
						return (-2);
					slen = _strlen(tmp);
					write(1, tmp, slen);
					i++;
					*len += slen;
					break;
				case 'd':
					n = va_arg(args, int);
					tmp = int_formatting(n);
					slen = _strlen(tmp);
					write (1, tmp, slen);
					i++;
					*len += slen;
					break;
				default:
					break;
			}
		}
		write(1, &format[i], 1);
		*len += 1;
	}
	return (0);
}

int _strlen(char *s)
{
	int i;

	while (s[i] != '\0')
		i++;
	return (i);
}

char *int_formatting(int n)
{
	int i, d = 0;
	char *number;

	i = n;
	while (i > 0)
	{
		i /= 10;
		d++;
	}
	number = malloc(sizeof(char) * d + 1);
	for (i = d - 1; i >= 0; i--)
	{
		number[i] = '0' + (n % 10);
		n /= 10;
	}
	number[d] = '\0';
	return (number);	
}
