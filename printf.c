#include "main.h"

/**
 * _printf - writes chars and strings to stdout
 * @format: string constant and formatting to print
 * Return: total bytes printed
*/

int _printf(const char *format, ...)
{
	int i, j, tlen, clen, slen;
	char *temp, *print;
	char t;
	va_list arg;

	clen = _strlen(format);
	tlen = _strclen(&clen, format);
	va_start(arg, format);
	for (i = 0, slen = 0; i < clen; i++)
	{
		if ((format[i] == '%'))
		{
			i++;
			if (format[i] == 's')
			{
				temp = va_arg(arg, char *);
				slen += _strlen(temp);
				i += 1;
			}
		}
	}
	tlen += slen;
	va_end(arg);
	va_start(arg, format);
	print = malloc(sizeof(char) * tlen + 1);
	for (i = 0, j = 0; i < tlen; i++, j++)
	{
		if (format[j] == '%')
		{
			if (format[j + 1] == 's')
			{
				temp = va_arg(arg, char *);
				i = fill_array(temp, print, i, &j);
			}
			else if (format[j + 1] == 'c')
			{
				t = va_arg(arg, int);
				print[i] = t;
				i++;
				j += 2;
			}
			else
				print[i] = format[j];
		}
		print[i] = format[j];
	}

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

int _strclen(int *len, const char *c)
{
	int i, true_len;

	for (i = 0, true_len = 0; i < *len; i++)
	{
		switch (c[i])
		{
		case '%':
			switch (c[i + 1])
			{
			case 'c':
				i += 1;
				true_len++;
				break;
			case 's':
				i += 1;
				break;
			default:
				true_len++;
				break;
			}
			break;
		default:
			true_len++;
			break;
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
 * fill_array - the things i do for betty
 * @src: source array
 * @dest: destination array
 * @pstn: original i
 * @push: increment j
 * Return: new i
*/
int fill_array(char *src, char *dest, int pstn, int *push)
{
	int i;

	i = 0;
	for (i = 0; src[i] != '\0'; i++, pstn++)
		dest[pstn] = src[i];
	*push += 2;
	return (pstn);
}
