#include "ft_printf.h" // Include the header file for the ft_printf library

// This function handles the special case where n is the smallest possible int.
// It writes "-2147483648" to the standard output and returns the number of characters written.
static int	int_min(int n)
{
	(void)n; // The parameter n is not used in this function. This line prevents a compiler warning.
	// Write the string "-2147483648" to the standard output (file descriptor 1)
	// If there was an error in writing, return -1
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	// Return the number of characters printed, which is 11 in this case
	return (11);
}

// This function takes an integer as input and prints it out digit by digit.
// It returns the number of digits printed, or -1 if there was an error.
int	ft_putnbr(int n)
{
	int	i; // This variable will hold the number of digits printed

	i = 0; // Initialize i to 0
	// If n is the smallest possible int, handle it as a special case
	if (n == -2147483648)
		return (int_min(n));
	// If n is negative, print a minus sign and make n positive
	if (n < 0 && ++i)
	{
		// Write the character "-" to the standard output
		// If there was an error in writing, return -1
		if (write(1, "-", 1) != 1)
			return (-1);
		// Make n positive
		n = -n;
	}
	// If n is greater than 9, it has more than one digit
	if (n > 9)
	{
		// Recursively call the function with n divided by 10
		// This will print all but the last digit of n
		i += ft_putnbr(n / 10);
		// If there was an error in the recursive call, return -1
		if (i == -1)
			return (-1);
		// Get the last digit of n by taking n modulo 10
		n = n % 10;
	}
	// If n is now less than or equal to 9, it has only one digit
	if (n <= 9)
	{
		// Print the digit. If there was an error, return -1
		if (ft_putchar (('0' + n)) == -1)
			return (-1);
		// Increment i because we've printed another digit
		i++;
	}
	// Return the number of digits printed
	return (i);
}
