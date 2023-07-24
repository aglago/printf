#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _strlen(const char *s);
int _strclen(int len, const char *c, char type);
int _printf(const char *format, ...);
void fill(va_list args, const char *src, char *dest, int len);
int format_length(va_list args, const char *format, int len);

#endif
