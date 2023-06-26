#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 *
 * Return: On success, the number of characters written. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Computes the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _printf - Custom printf implementation
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else if (format[i] == 'c')
			{
				char ch = va_arg(args, int);
				_putchar(ch);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				int len = _strlen(str);
				write(1, str, len);
				count += len;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(args, int);
				int digits = 0;

				if (num == 0)
				{
					_putchar('0');
					count++;
				}
				else if (num < 0)
				{
					_putchar('-');
					count++;

					while (num != 0)
					{
						int digit = num % 10;
						_putchar('0' - digit);
						count++;
						num /= 10;
						digits++;
					}
				}
				else
				{
					while (num != 0)
					{
						int digit = num % 10;
						_putchar('0' + digit);
						count++;
						num /= 10;
						digits++;
					}
				}

				/* Reverse the digits if number was negative */
				if (num < 0)
				{
					char *str = malloc((digits + 1) * sizeof(char));
					int j;

					for (j = 0; j < digits; j++)
						str[j] = _putchar('0' - str[j]);

					for (j = digits - 1; j >= 0; j--)
					{
						_putchar(str[j]);
						count++;
					}

					free(str);
				}
			}
		}
		i++;
	}

	va_end(args);

	return (count);
}

