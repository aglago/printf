#include "main.h"

/**
 * _printf - writes chars and strings to stdout
 * @format: string constant and formatting to print
 * Return: total bytes printed
*/

int _printf(const char *format, ...)
{
	int i, j, k, tlen, clen, slen;
	const char *temp;
	char t;
	char *print;
	va_list arg;

	clen = _strlen(format);
	tlen = _strclen(&clen, format);
	va_start(arg, format);
	for (i = 0, slen = 0; i < clen; i++)
	{
		switch (format[i])
		{
			case '%':
				switch (format [i + 1])
				{
					case 's':
						temp = va_arg(arg, char *);
						if (temp == NULL)
							break;
						slen += _strlen(temp);
						i+=1;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
	tlen += slen;
	va_end(arg);
	va_start(arg, format);
	print = malloc(sizeof(char) * tlen + 1);
	for (i = 0, j = 0, k = 0; i < tlen; i++, j++)
	{
		switch (format[j])
		{
			case '%':
				switch (format [j + 1])
				{
					case 's':
						temp = va_arg(arg, char *);
						while (temp[k])
						{
							print[i] = temp[k];
							k++;
							i++;
						}
						j += 2;
						break;
					case 'c':
						t = va_arg(arg, int);
						print[i] = t;
						i++;
						j+= 2;
						break;
					default:
						print[i] = format[j];
						i++;
						j++;
						break;
				}
				print[i] = format[j];
				break;
			default:
				print[i] = format[j];
				break;
		}
	}
	print[tlen] = '\0';
	write(1, print, tlen);
	free(print);
	return(tlen);
}


/**
 * _strclen - gets length of sting constant alone
 * @len: length of format string
 * @c: format string
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
				i+=1;
				true_len++;	
				break;
			case 's':
				i+=1;
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
