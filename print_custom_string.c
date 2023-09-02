#include "main.h"

/**
 * print_cutstom_string - prints custom string
 * @str: string as parameter to be printed
 * Return: number of characters printed
 */
int print_custom_string(const char *str)
{
	int count = 0;
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar((str[i] / 16) + (str[i] / 16 < 10 ? '0' : 'A' - 10));
			count += _putchar((str[i] / 16) + (str[i] % 16 < 10 ? '0' : 'A' - 10));
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}
