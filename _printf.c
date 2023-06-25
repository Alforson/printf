#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return -1;

	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
			else if (*format == 'c')
			{
				char c = (char) va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				int len = 0;
				while (str[len])
					len++;
				write(1, str, len);
				printed_chars += len;
			}
		}
		format++;
	}

	va_end(args);

	return printed_chars;
}
