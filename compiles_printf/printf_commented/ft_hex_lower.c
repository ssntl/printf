#include "ft_printf.h" // Include the header file for the ft_printf library

// This function takes a base string, a number, and a count as input.
// It recursively prints the hexadecimal representation of the number using the characters in the base string.
// It returns the number of characters printed, or -1 if there was an error.
static int	puthex_long(char *base, unsigned long long n, int c)
{
	unsigned long long	b;

	b = ft_strlen(base);  // Get the length of the base string
	// If the number is greater than or equal to the length of the base string
	if (n >= b)
	{
		// Recursively call the function with n divided by the length of the base string
		c = puthex_long(base, n / b, c);
		// If there was an error in the recursive call, return -1
		if (c == -1)
			return (-1);
		// Write the character corresponding to n modulo the length of the base string to the standard output
		if (write (1, &base[n % b], 1) == -1)
			// If there was an error in writing, return -1
			return (-1);
		// Increment the count because we've printed another character
		c++;
	}
	// If the number is less than the length of the base string
	else if (n < b)
	{
		// Write the character corresponding to n to the standard output
		if (write (1, &base[n], 1) == -1)
			// If there was an error in writing, return -1
			return (-1);
		// Increment the count because we've printed another character
		c++;
	}
	// Return the total number of characters printed
	return (c);
}

// This function is similar to puthex_long, but it takes an unsigned integer as input instead of an unsigned long long.
static int	puthex_unsigned(char *base, unsigned int n, int c)
{
	unsigned int	b;

	b = ft_strlen(base);  // Get the length of the base string
	// The rest of the function is the same as puthex_long
	if (n >= b)
	{
		c = puthex_unsigned(base, n / b, c);
		// If there was an error in the recursive call, return -1
		if (c == -1)
			return (-1);
		// Write the character corresponding to n modulo the length of the base string to the standard output
		if (write (1, &base[n % b], 1) == -1)
			// If there was an error in writing, return -1
			return (-1);
		// Increment the count because we've printed another character
		c++;
	}
	// If the number is less than the length of the base string
	else if (n < b)
	{
		// Write the character corresponding to n to the standard output
		if (write (1, &base[n], 1) == -1)
			// If there was an error in writing, return -1
			return (-1);
		// Increment the count because we've printed another character
		c++;
	}
	// Return the total number of characters printed
	return (c);
}

// This function takes an integer as input and prints its hexadecimal representation using lowercase letters.
// It returns the number of characters printed, or -1 if there was an error.
int	ft_hex_lower(int n)
{
	int		let;

	let = 0;
	// If n is non-negative, call puthex_long to print its hexadecimal representation
	if (n >= 0)
		let = puthex_long("0123456789abcdef", n, let);
	// If n is negative, call puthex_unsigned to print its hexadecimal representation
	else if (n < 0)
		let = puthex_unsigned("0123456789abcdef", n, let);
	// Return the total number of characters printed
	return (let);
}
