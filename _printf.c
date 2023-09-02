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
	va_list par_list;

	va_start(par_list, format);

	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			specifiers(par_list, format, &i, &count);
		}
		else
		{
			count += _putchar(format[i]);
		}
	}
	va_end(par_list);
	return (count);
}
