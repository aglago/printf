#include "main.h"
#include <stdio.h>

int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence. %d\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Length:[%d, %i]\n", len, len2);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
	_printf("Hi %s Nice to meet you. I am %s\n", "Samuel", "Mabel");
    return (0);
}
