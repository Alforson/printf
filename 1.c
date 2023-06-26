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
	va_start(args, format);

	int printed_chars = 0;
	char c;
	char *s;
	int d;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move to the next character after '%' */

			/* Handle conversion specifiers */
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					putchar(c);
					printed_chars++;
					break;

				case 's':
					s = va_arg(args, char *);
					while (*s != '\0')
					{
						putchar(*s);
						s++;
						printed_chars++;
					}
					break;

				case 'd':
				case 'i':
					d = va_arg(args, int);
					printed_chars += print_number(d);
					break;

				case '%':
					putchar('%');
					printed_chars++;
					break;

				default:
					putchar('%');
					putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * print_number - Prints a number.
 * @n: The number to be printed.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	unsigned int num;
	int digit, count = 0;

	if (n < 0)
	{
		putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}

	digit = num % 10 + '0';
	putchar(digit);
	count++;

	return (count);
}
