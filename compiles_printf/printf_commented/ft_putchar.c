#include "ft_printf.h" // Include the header file for the ft_printf library

// This function takes a character as input and writes it to the standard output.
// It returns 1 if the character was written successfully, or -1 if there was an error.
int	ft_putchar(int c)
{
	// Write the character to the standard output (file descriptor 1)
	// The write function takes three arguments: the file descriptor to write to, 
	// the address of the data to write, and the number of bytes to write.
	// In this case, we're writing one byte (the character c) to the standard output.
	if (write (1, &c, 1) != 1)
		// If the write function does not return 1, it means there was an error in writing.
		// In that case, we return -1 to indicate an error.
		return (-1);
	// If the write function was successful, it would have returned 1.
	// So we also return 1 to indicate success.
	return (1);
}
