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

	return printed_chars;
}
