#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _strlen(char *s);
int formatting(va_list args, const char *format, int *len);
char *int_formatting(int n);
void _strcpy(char *dest, char *src);

#endif
