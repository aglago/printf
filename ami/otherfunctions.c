#include "main.h"

void morespec(va_list par, const char *fmt, int i, int *count)
{
	const char *par_str;

	switch (fmt[i])
	{
		case 'r':
			par_str = va_arg(par, char *);
			if (par_str == NULL)
			{
				(*count) += _puts("(null)");
				return;
			}
			(*count) += _revputs(par_str);
			break;
	}
}

/**
 * _puts - custom puts
 * @str: pointer to array of characters (string)
 * Return: number of characters printed
 */

int _revputs(const char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	for (i -= 1; i >= 0; i--)
		_putchar(str[i]);
	/* _putchar('\n'); */
	return (i);
}
