#include "main.h"

/**
 * _printf - Prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0;
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            count++;
        }
        else
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str)
                    {
                        while (*str)
                        {
                            _putchar(*str);
                            count++;
                            str++;
                        }
                    }
                    break;
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
                    break;
            }
        }
        i++;
    }

    va_end(args);

    return count;
}
