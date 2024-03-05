#include "ft_printf.h" // Include the header file for the ft_printf library

// Forward declaration of the function format_type
static	int	format_type(char c, va_list ap);

// This function handles the '%' character in the format string of ft_printf
static int	write_percent(char c, va_list ap)
{
	int	i;

	i = 0;
	// If the character after '%' is not another '%', it's a format specifier
	if (c != '%')
	{
		// Call format_type to handle the format specifier
		i = format_type(c, ap);
		// If there was an error in format_type, return -1
		if (i == -1)
			return (-1);
		// Return the number of characters printed by format_type
		return (i);
	}
	else
	{
		// If the character after '%' is another '%', write a single '%' to the standard output
		if (write (1, &c, 1) != 1)
			// If there was an error in writing, return -1
			return (-1);
		// Return 1 because we've printed one character
		return (1);
	}
}

// This function writes a string to the standard output, interpreting '%' characters as format specifiers
static	int	write_str(const char *str, va_list ap, int count)
{
	int		i;

	i = 0;
	// Iterate over each character in the string
	while (str[i])
	{
		// If the current character is '%', handle it as a format specifier
		if (str[i] == '%')
		{
			// Call write_percent to handle the format specifier
			count = count + write_percent(str[i + 1], ap);
			// If there was an error in write_percent, return -1
			if (count == -1)
				return (-1);
			// Skip the next character because it's part of the format specifier
			i++;
		}
		else
		{
			// If the current character is not '%', write it to the standard output
			if (write (1, &str[i], 1) != 1)
				// If there was an error in writing, return -1
				return (-1);
			// Increment the count because we've printed one character
			count++;
		}
		// Move to the next character
		i++;
	}
	// Return the total number of characters printed
	return (count);
}

// This is a custom implementation of the printf function from the standard C library
int	ft_printf(const char *str, ...)
{
	va_list	ap;  // Declare a va_list variable to handle the variable arguments
	int		i;

	i = 0;
	va_start(ap, str);  // Initialize the va_list variable with the variable arguments
	// Call write_str to write the format string to the standard output
	i = write_str(str, ap, i);
	va_end(ap);  // Clean up the va_list variable
	// Return the total number of characters printed
	return (i);
}

// This function handles the format specifiers in the format string of ft_printf
static int	format_type(char c, va_list ap)
{
	// If the format specifier is 'c', print a character
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	// If the format specifier is 's', print a string
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	// If the format specifier is 'p', print a pointer
	if (c == 'p')
		return (ft_hex_pointer(va_arg(ap, void *)));
	// If the format specifier is 'd' or 'i', print an integer
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	// If the format specifier is 'u', print an unsigned integer
	if (c == 'u')
		return (ft_unsigned(va_arg(ap, unsigned int)));
	// If the format specifier is 'x', print a hexadecimal number with lowercase letters
	if (c == 'x')
		return (ft_hex_lower(va_arg(ap, int)));
	// If the format specifier is 'X', print a hexadecimal number with uppercase letters
	if (c == 'X')
		return (ft_hex_upper(va_arg(ap, int)));
	// If the format specifier is not recognized, return 0
	return (0);
}
