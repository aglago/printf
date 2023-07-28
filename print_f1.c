#include "main.h"

/**
 * morespec - extends the specifer function for more flags
 * @i: iterator
 * @par: parameter list
 * @fmt: format string
 * @count: return value tracking
 * Return: 0 if no case matched; 1 if case matches
*/
int morespec(va_list par, const char *fmt, int *i, int *count)
{
	const char *par_str;
	int par_int, bin;

	if (_isdigit(fmt[*i]))
	{
		if (fmt[*i + 1] == 'd' || fmt[*i + 1] == 'i') /* make unsigned */
		{
			par_int = va_arg(par, int);
			print_width_int(fmt[*i], par_int, count);
			*i += 1;
			return (1);
		}
		else
			return (0);
	}
	switch (fmt[*i])
	{
		case 'r':
			par_str = va_arg(par, char *);
			if (par_str == NULL)
			{
				(*count) += _puts("(null)");
				return (1);
			}
			(*count) += _revputs(par_str);
			return (1);
		case 'b':
			bin = va_arg(par, int);
			(*count) += print_binary(bin);
			return (1);
		default:
			break;
	}
	return (0);
}

/**
 * _revputs - prints string in reverse
 * @str: pointer to array of characters (string)
 * Return: number of characters printed
 */

int _revputs(const char *str)
{
	int len, i = 0;

	while (str[i] != '\0')
		i++;
	len = i;
	for (i -= 1; i >= 0; i--)
		_putchar(str[i]);
	return (len);
}

/**
 * _isdigit - checks if a char is a number
 * @c: char
 * Return: 1 if true and 0 if false
*/
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

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
	copy = n;
	for (digits = 0; copy != 0; digits++)
		copy /= 10;
	if (digits >= width)
		*counter += print_num(n);
	else
	{
		sp_len = width - digits;
		for (i = 0; i < sp_len; i++)
			_putchar(' ');
		*counter += print_num(n);
	}
}
