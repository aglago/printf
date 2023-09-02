#ifndef MAIN_H
#define MAIN_H

/* header files */
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* function prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
int _puts(const char *str);
int print_num(int n);
void specifiers(va_list par_list, const char *format, int *i, int *count);
int morespec(va_list par, const char *fmt, int *i, int *count);
int _revputs(const char *str);
void print_width_int(char c, int n, int *counter);
int _isdigit(char c);
int print_binary(unsigned int n);
void print_null_str(const char *par_str, int *count);
int print_unsignedd(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int u_specifier(va_list par, int *count);
int r_specifier(va_list par, int *count);
int b_specifier(va_list par, int *count);
int o_specifier(va_list par, int *count);
int x_specifier(va_list par, int *count);
int X_specifier(va_list par, int *count);
int S_specifier(va_list par, int *count);
int print_custom_string(const char *str);
#endif
