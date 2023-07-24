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
	char parameter;
	const char *par_str;

	va_list parameter_list;

	va_start(parameter_list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				parameter = va_arg(parameter_list, int);
				count += _putchar(parameter);
			}
			else if (format[i] == 's')
			{
				par_str = va_arg(parameter_list, const char*);
				count += _puts(par_str);
			}
			else if (format[i] == '%')
			{
				count += _putchar('%');
			}
			else if (format[i] != 'c' || format[i] != 's' || format[i] != '%')
			{
				_putchar('%');
				_putchar(format[i]);
			}
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
