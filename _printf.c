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

	va_start(args, format);

	if (format == NULL)
		return (-1);

	count = print_formatted_string(format, args);

	va_end(args);

	return (count);
}

/**
 * print_formatted_string - Processes the format
 * string and prints the output.
 * @format: Character string containing the format.
 * @args: Variable arguments list.
 *
 * Return: The number of characters printed.
 */
int print_formatted_string(const char *format, va_list args)
{
	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				return (-1);

			count += handle_conversion_specifier(*format, args);
		}
		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	return (count);
}

/**
 * handle_conversion_specifier - Handles the conversion
 * specifier and prints the corresponding value.
 * @specifier: The conversion specifier.
 * @args: Variable arguments list.
 *
 * Return: The number of characters printed.
 */
int handle_conversion_specifier(char specifier, va_list args)
{
	int count = 0;
	char *str;
	char c;
	int num;

	switch (specifier)
	{
		case '%':
			_putchar('%');
			count++;
			break;

		case 'c':
			c = (char)va_arg(args, int);
			_putchar(c);
			count++;
			break;

		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(null)";
			count += print_string(str);
			break;

		case 'd':
		case 'i':
			num = va_arg(args, int);
			count += print_integer(num);
			break;

		default:
			_putchar('%');
			_putchar(specifier);
			count += 2;
			break;
	}

	return (count);
}

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int count = 0;

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}

	return (count);
}

/**
 * print_number - Prints an integer.
 * @num: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num / 10)
		count += print_integer(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}
