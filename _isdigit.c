#include "main.h"

/**
 * _isdigit - checks if a char is a number
 * @c: char
 * Return: 1 if true and 0 if false
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
