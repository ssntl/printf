#include "ft_printf.h" // Include the header file for the ft_printf library

// This function takes a base string, a number, and a count as input.
// It recursively prints the hexadecimal representation of the number using the characters in the base string.
// It returns the number of characters printed, or -1 if there was an error.
static int	hex_pointer(char *base, unsigned long long n, int c)
{
	unsigned long long	b;

	b = ft_strlen(base);  // Get the length of the base string
	// If the number is greater than or equal to the length of the base string
	if (n >= b)
	{
		// Recursively call the function with n divided by the length of the base string
		c = hex_pointer(base, n / b, c);
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

// This function takes a pointer as input and prints its hexadecimal representation.
// It returns the number of characters printed, or -1 if there was an error.
int	ft_hex_pointer(void *p)
{
	unsigned long long	pointer;
	int					i;

	i = 0;
	// Convert the pointer to an unsigned long long
	pointer = (unsigned long long)p;
	// Write the string "0x" to the standard output to indicate that the following number is in hexadecimal
	if (write(1, "0x", 2) != 2)
		// If there was an error in writing, return -1
		return (-1);
	// Call hex_pointer to print the hexadecimal representation of the pointer
	i = hex_pointer("0123456789abcdef", pointer, i);
	// If there was an error in hex_pointer, return -1
	if (i == -1)
		return (-1);
	// Add 2 to the count because we've printed two more characters ("0x")
	i += 2;
	// Return the total number of characters printed
	return (i);
}
