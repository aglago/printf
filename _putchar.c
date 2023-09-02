#include "main.h"
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
