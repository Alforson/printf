#include "main.h"

/**
 * print_number - Prints a number
 * @num: The number to print
 *
 * Return: The number of digits printed
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
		count += print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}
