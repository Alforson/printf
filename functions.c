/**
 * print_number - Prints an integer
 * @num: The integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int num)
{
	int count = 0;

	if (num / 10)
		count += print_number(num / 10);

	_putchar('0' + (num % 10));
	count++;

	return (count);
}

/**
 * print_binary - Prints an unsigned int in binary format
 * @num: unsigned int to print
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int num)
{
	int count = 0;

	if (num / 2)
		count += print_binary(num / 2);

	_putchar('0' + (num % 2));
	count++;

	return (count);
}

/**
 * handle_conversion_specifier - Handles a conversion specifier
 * @specifier: The conversion specifier character
 * @args: The va_list arguments
 *
 * Return: The number of characters printed for the specifier
 */
int handle_conversion_specifier(char specifier, va_list args)
{
	int count = 0;

	if (specifier == '%')
	{
		_putchar('%');
		count++;
	}
	else if (specifier == 'c')
	{
		char c = (char)va_arg(args, int);
		_putchar(c);
		count++;
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";

		while (*str)
		{
			_putchar(*str);
			count++;
			str++;
		}
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);
		count += print_number(num);
	}
	else if (specifier == 'b')
	{
		unsigned int num = va_arg(args, unsigned int);
		count += print_binary(num);
	}
	else
	{
		_putchar('%');
		_putchar(specifier);
		count += 2;
	}

	return (count);
}
