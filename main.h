#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int _print_number(int n);
int _print_binary(unsigned int num);
int _print_unsigned(unsigned int num);
int _print_octal(unsigned int num);
int _print_hex(unsigned int num, int uppercase);

#endif /* MAIN_H */
