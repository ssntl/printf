#include "ft_printf.h" // Include the header file for the ft_printf library

// This function takes an unsigned integer as input and prints it out digit by digit.
// It returns the number of digits printed, or -1 if there was an error.
unsigned int	ft_num_unsigned(unsigned int num)
{
	int	i; // This variable will hold the number of digits printed

	i = 0; // Initialize i to 0
	// If the number is greater than 9, it has more than one digit
	if (num > 9)
	{
		// Recursively call the function with num divided by 10
		// This will print all but the last digit of num
		i = ft_num_unsigned(num / 10);
		// If there was an error in the recursive call, return -1
		if (i == -1)
			return (-1);
		// Get the last digit of num by taking num modulo 10
		num = num % 10;
	}
	// If num is now less than or equal to 9, it has only one digit
	if (num <= 9)
	{
		// Print the digit. If there was an error, return -1
		if (ft_putchar (('0' + num)) == -1)
			return (-1);
		// Increment i because we've printed another digit
		i++;
	}
	// Return the number of digits printed
	return (i);
}
