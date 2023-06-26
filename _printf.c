#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Character string containing the format.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str;
	char c;
	int num;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				return (-1);

			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					_putchar(*str);
					count++;
					str++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);
				if (num < 0)
				{
					_putchar('-');
					count++;
					num = -num;
				}
				count += print_number(num);
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}

