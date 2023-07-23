#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _strlen(const char *s);
int _strclen(int *clen, const char *c);
int _printf(const char *format, ...);
int fill_array(char *src, char *dest, int pstn, int *push);
void fill(va_list args, const char *src, char *dest, int len);

#endif
