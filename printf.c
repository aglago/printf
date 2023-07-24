#include "main.h"

/**
 * _printf - writes chars and strings to stdout
 * @format: string constant and formatting to print
 * Return: total bytes printed
*/

int _printf(const char *format, ...)
{
	int tlen, clen, slen;
	char *print;
	va_list arg;

	if (format == NULL)
		return (-1);
	clen = _strclen(0, format, 'c');
	tlen = _strclen(clen, format, 't');
	va_start(arg, format);
	slen = format_length(arg, format, clen);
	if (slen == -1)
		return (-1);
	tlen += slen;
	va_end(arg);
	va_start(arg, format);
	print = malloc(sizeof(char) * tlen + 1);
	fill(arg, format, print, tlen);
	va_end(arg);
	print[tlen] = '\0';
	write(1, print, tlen);
	free(print);
	return (tlen);
}


/**
 * _strclen - gets length of sting constant alone
 * @len: length of format string
 * @c: format string
 * Return: length of string constant
*/

int _strclen(int len, const char *s,char type)
{
	int i, true_len;

	if (type == 'c')
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else
	{
	for (i = 0, true_len = 0; i < len; i++)
	{
		if (s[i] == '%')
		{
			switch (s[i + 1])
			{
			case 'c':
				i++;
				true_len++;
				break;
			case 's':
				i++;
				break;
			case '%':
				i++;
				true_len++;
				break;
			case 'd':
				i++;
				break;
			default:
				true_len++;
				break;
			}
		}
		else
			true_len++;
	}
	}
	return (true_len);
}
/**
 * _strlen - Returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * fill - Expands our formatted array
 * @args: varaibale list of array
 * @src: format array
 * @dest: destination array
 * @len: length of expanded array
 */

void fill(va_list args, const char *src, char *dest, int len)
{
	int i, j, k;
	char *tmp, t;

	for (i = 0, j = 0; i < len; i++, j++)
	{
		if (src[j] == '%')
		{
			if (src[j + 1] == 's')
			{
				tmp = va_arg(args, char *);
				for (k = 0; tmp[k] != '\0'; i++, k++)
					dest[i] = tmp[k];
				j += 2;
			}
			else if (src[j + 1] == 'c')
			{
				t = va_arg(args, int);
				dest[i] = t;
				i++;
				j += 2;
			}
			else if (src[j + 1] == '%')
			{
				dest[i] = '%';
				i++;
				j += 2;
			}
			else
				dest[i] = src[j];
		}
		dest[i] = src[j];
	}
}

/**
 * format_length - runs through the variable arguments
 * @args: argument list
 * @format: string
 * @len: length of format constant
 * Return: lemgth of char * in args
 */
int format_length(va_list args, const char *format, int len)
{
	int i, slen;
	char *tmp;

	for (i = 0, slen = 0; i < len; i++)
	{
		if ((format[i] == '%'))
		{
			if (format[i + 1] == 'c')
			{
				va_arg(args, int);
				i += 2;
			}
			else if (format[i + 1] == 's')
			{
				tmp = va_arg(args, char *);
				if (tmp == NULL)
					return (-1);
				slen += _strlen(tmp);
				i += 2;
			}
			else if (format[i + 1] == '%')
				i += 2;
			else if (format[i + 1] == 'd')
			{}

		}
	}
	return (slen);
}

