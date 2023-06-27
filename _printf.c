#include "main.h"

/**
 * _printf - Prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	va_list args;
	va_start(args, format);

	int count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);

			count += handle_conversion_specifier(*format, args);
		}

		format++;
	}

	va_end(args);
	return (count);
}
