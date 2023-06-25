#include "main.h"

/**
 * _printf - Printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr != '%')
		{
			_putchar(*ptr);
			count++;
			continue;
		}

		ptr++;

		if (*ptr == '\0')
			return (-1);

		switch (*ptr)
		{
			case 'c':
				_putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				count += _puts(va_arg(args, char *));
				break;
			case 'd':
			case 'i':
				count += _print_number(va_arg(args, int));
				break;
			case '%':
				_putchar('%');
				count++;
				break;
			default:
				_putchar('%');
				_putchar(*ptr);
				count += 2;
				break;
		}
	}
	va_end(args);

	return (count);
}

/**
 * _print_number - Print a number
 * @n: Number to print
 *
 * Return: Number of digits printed
 */
int _print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += _print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}
