#include "main.h"

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: The number to print in binary.
 *
 * Return: The number of binary digits printed.
 */

int print_binary(unsigned int num)

{
	int count = 0;

	if (num / 2)
		count += print_binary(num / 2);

	_putchar((num % 2) + '0');
	count++;

	return (count);
}
