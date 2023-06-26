#include "main.h"

/**
<<<<<<< HEAD
 * _printf - Produces output according to a format.
 * @format: Character string containing the format.
 *
 * Return: The number of characters printed.
=======
 * _printf - Prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
>>>>>>> 88bef66271eb05f12e33d0e77e148512365bc02c
 */
int _printf(const char *format, ...)
{
	va_list args;
<<<<<<< HEAD
	va_start(args, format);

	int printed_chars = 0;
	char c;
	char *s;

	while (*format != '\0')
=======
	int count = 0;
	char *str;
	char c;
	int num;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
>>>>>>> 88bef66271eb05f12e33d0e77e148512365bc02c
	{
		if (*format == '%')
		{
<<<<<<< HEAD
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
=======
			_putchar(*format);
			count++;
		}
		else
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
>>>>>>> 88bef66271eb05f12e33d0e77e148512365bc02c
		}

		format++;
	}

	va_end(args);

	return (count);
}
