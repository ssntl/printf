#include "ft_printf.h" // Include the header file for the ft_printf library

// This function takes a string as input and prints it out character by character.
// It returns the number of characters printed, or -1 if there was an error.
int	ft_putstr(char *c)
{
	size_t	i; // This variable will hold the number of characters printed

	i = 0; // Initialize i to 0
	// If the string is NULL
	if (!c)
	{
		// Write the string "(null)" to the standard output (file descriptor 1)
		// If there was an error in writing, return -1
		if (write (1, "(null)", 6) != 6)
			return (-1);
		// Return the number of characters printed, which is 6 in this case
		return (6);
	}
	// If the string is not NULL, iterate over each character in the string
	while (c[i])
	{
		// Write the current character to the standard output
		// If there was an error in writing, return -1
		if (write(1, &c[i], 1) != 1)
			return (-1);
		// Increment i because we've printed another character
		i++;
	}
	// Return the number of characters printed
	return (i);
}
