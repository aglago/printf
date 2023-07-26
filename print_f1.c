#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: destination string
 */

void _strcpy(char *dest, char *src)
{
	int i, length;

	for (i = 0, length = 0; src[i] != '\0'; i++)
		length++;
	for (i = 0; i <= length; i++)
		dest[i] = src[i];
}

char *checknull(char *fmt)
{
	if (fmt == NULL)
	{
		fmt = malloc(sizeof(char) * 7);
		_strcpy(fmt, "(null)");
	}
	return (fmt);
}
