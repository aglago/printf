#include "main.h"

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
