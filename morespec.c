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
	int par_int;

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
			return (r_specifier(par, count));
		case 'b':
			return (b_specifier(par, count));
		case 'u':
			return (u_specifier(par, count));
		case 'o':
			return (o_specifier(par, count));
		case 'x':
			return (x_specifier(par, count));
		case 'X':
			return (X_specifier(par, count));
		case 'S':
			return (S_specifier(par, count));
		default:
			break;
	}
	return (0);
}
