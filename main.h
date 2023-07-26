#ifndef MAIN_H
#define MAIN_H

/* header files */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/* function prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
int _puts(const char *str);
int print_num(int n);
void specifiers(va_list parameter_list, const char *format, int i, int *count);
int morespec(va_list par, const char *fmt, int i, int *count);
int _revputs(const char *str);

#endif
