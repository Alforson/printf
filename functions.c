#include "main.h"

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
