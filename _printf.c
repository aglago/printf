#include "main.h"

/**
 * _printf - custom printf function
 * desc: acts as printf
 * @format: format string to be outputed
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list parameter_list;

	va_start(parameter_list, format);

	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			specifiers(parameter_list, format, i, &count);
		}
		else
		{
			count += _putchar(format[i]);
		}
	}
	va_end(parameter_list);
	return (count);
}


/**
 * _putchar - prints character
 *
 * desc: character is being printed to standard output
 *
 * @c: character to be printed
 *
 * Return: the number of characters printed to standard output
 * i.e 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - custom puts
 * @str: pointer to array of characters (string)
 * Return: number of characters printed
 */

int _puts(const char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		_putchar(str[i]);
	/* _putchar('\n'); */
	return (i);
}


/**
 * specifiers - handles format specifiers of out custom printf
 * @i: iterator
 * @parameter_list: parameter list
 * @format: format string
 * @count: return value tracking
 */
void specifiers(va_list parameter_list, const char *format, int i, int *count)
{
	char parameter;
	const char *par_str;
	int par_int, status;

	switch (format[i])
	{
		case 'c':
			parameter = va_arg(parameter_list, int);
			(*count) += _putchar(parameter);
			break;
		case 's':
			par_str = va_arg(parameter_list, const char*);
			if (par_str == NULL)
			{
				(*count) += _puts("(null)");
				return;
			}
			(*count) += _puts(par_str);
			break;
		case '%':
			(*count) += _putchar('%');
			break;
		case 'd':
			par_int = va_arg(parameter_list, int);
			(*count) += print_num(par_int);
			break;
		case 'i':
			par_int = va_arg(parameter_list, int);
			(*count) += print_num(par_int);
			break;
		default:
			status = (morespec(parameter_list, format, i, count) == 1) ? 1 : 0;
			if (status == 0)
			{
				(*count) += _putchar('%');
				(*count) += _putchar(format[i]);
			}
	}
}


/**
 * print_num - prints integers
 * @n: number to print
 * Return: number of numbers printed
 */
int print_num(int n)
{
	int i, count = 0;
	char *min_int;
	char n_arr[20]; /* up to 20 digits */

	if (n == -2147483648)
	{
		min_int = "-2147483648";
		count += _puts(min_int);
		return (count);
	}

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	i = 0;
	while (n > 0)
	{
		n_arr[i++] = '0' + n % 10;
		n /= 10;
	} /* printing digits into array */

	count += i; /* taking size of array */

	while (--i >= 0)
		_putchar(n_arr[i]);

	return (count);
}

