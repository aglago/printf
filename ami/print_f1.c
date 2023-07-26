#include "main.h"

/**
 * morespec - extends the specifer function for more flags
 * @i: iterator
 * @par: parameter list
 * @fmt: format string
 * @count: return value tracking
 * Return: 0 if no case matched; 1 if case matches
*/
int morespec(va_list par, const char *fmt, int i, int *count)
{
	const char *par_str;

	switch (fmt[i])
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
	int i = 0;

	while (str[i] != '\0')
		i++;
	for (i -= 1; i >= 0; i--)
		_putchar(str[i]);
	return (i);
}
