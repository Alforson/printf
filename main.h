#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_number(int num);
int print_formatted_string(const char *format, va_list args);
int handle_conversion_specifier(char specifier, va_list args);
int print_string(char *str);
int print_integer(int num);

#endif /* MAIN_H */

