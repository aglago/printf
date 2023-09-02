#include "main.h"

/**
 * X_specifier - handle X
 * @par: parameter list
 * @count: number of characters
 * Return: integer (count)
 */
int X_specifier(va_list par, int *count)
{
	int par_int = va_arg(par, unsigned int);

	(*count) += print_hex(par_int, 1);
	return (1);
}

/**
 * S_specifier - handle S
 * @par: parameter list
 * @count: number of characters
 * Return: integer (count)
 */
int S_specifier(va_list par, int *count)
{
        const char *par_str = va_arg(par, char *);
	if (par_str == NULL)
	{
		(*count) += _puts("(null)");
		return (1);
	}
	(*count) += print_custom_string(par_str);

	return (1);
}
