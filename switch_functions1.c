#include "main.h"

/**
 * r_specifier - handle r
 * @par: parameter list
 * @count: number of characters
 * Return: integer (count)
 */
int r_specifier(va_list par, int *count)
{
	const char *par_str = va_arg(par, char *);

	par_str = va_arg(par, char *);
	if (par_str == NULL)
	{
		(*count) += _puts("(null)");
		return (1);
	}
	(*count) += _revputs(par_str);
	return (1);
}

/**
 * b_specifier - handles b
 * @par: parameter list
 * @count: number of characters
 * Return: integer (count)
 */
int b_specifier(va_list par, int *count)
{
	int bin = va_arg(par, int);

	(*count) += print_binary(bin);
	return (1);
}

/**
 * u_specifier - handle r
 * @par: parameter list
 * @count: number of characters
 * Return: integer (count)
 */
int u_specifier(va_list par, int *count)
{
	unsigned int par_int = va_arg(par, unsigned int);

	(*count) += print_unsignedd(par_int);
	return (1);
}

/**
 * o_specifier - handle o
 * @par: parameter list
 * @count: number of characters
 * Return: integer (count)
 */
int o_specifier(va_list par, int *count)
{
	int par_int = va_arg(par, unsigned int);

	(*count) += print_octal(par_int);
	return (1);
}



/**
 * x_specifier - handle x
 * @par: parameter list
 * @count: number of characters
 * Return: integer (count)
 */
int x_specifier(va_list par, int *count)
{
	int par_int = va_arg(par, unsigned int);

	(*count) += print_hex(par_int, 0);
	return (1);
}
