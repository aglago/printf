#include "main.h"

/**
 * main - entry point
 * desc: test a mixture of c and s
 * Return: 0 (success)
 */
int main(void)
{
	char ch = 'X';
	char *str = "Custom Printf";

	_printf("Character: %c, String: %s\n", ch, str);
	return (0);
}
