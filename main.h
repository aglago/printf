#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _strlen(const char *s);
int _strclen(int *clen, const char *c);
int _printf(const char *format, ...);

#endif