#include "main.h"

/**
 * print_null_str - prints (null) if va_arg returns null
 * for a string
 *
 * @par_str: string parameter
 * @count: number of characters printed
 */

void print_null_str(const char *par_str, int *count)
{
	if (par_str == NULL)
	{
		(*count) += _puts("(null)");
		return;
	}
	(*count) += _puts(par_str);
}
