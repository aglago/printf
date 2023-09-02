#include "main.h"

/**
 * _revputs - prints string in reverse
 * @str: pointer to array of characters (string)
 * Return: number of characters printed
 */

int _revputs(const char *str)
{
	int len, i = 0;

	while (str[i] != '\0')
		i++;
	len = i;
	for (i -= 1; i >= 0; i--)
		_putchar(str[i]);
	return (len);
}
