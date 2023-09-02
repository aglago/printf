#include "main.h"

/**
 * specifiers - handles format specifiers of out custom printf
 * @i: iterator
 * @par_list: parameter list
 * @format: format string
 * @count: return value tracking
 */
void specifiers(va_list par_list, const char *format, int *i, int *count)
{
	char parameter, *par_str;
	int par_int, status;

	switch (format[*i])
	{
		case 'c':
			parameter = va_arg(par_list, int);
			(*count) += _putchar(parameter);
			break;
		case 's':
			par_str = va_arg(par_list, char *);
			print_null_str(par_str, count);
			break;
		case '%':
			(*count) += _putchar('%');
			break;
		case 'd':
			par_int = va_arg(par_list, int);
			(*count) += print_num(par_int);
			break;
		case 'i':
			par_int = va_arg(par_list, int);
			(*count) += print_num(par_int);
			break;
		default:
			status = morespec(par_list, format, i, count);
			if (status == 0)
			{
				(*count) += _putchar('%');
				(*count) += _putchar(format[*i]);
			}
	}
}
