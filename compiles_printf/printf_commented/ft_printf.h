#ifndef FT_PRINTF_H  // If FT_PRINTF_H is not defined yet,
# define FT_PRINTF_H  // then define it. This prevents multiple inclusions of the same header file.

# include <unistd.h>  // Include the unistd.h library for write and read functions
# include <stdio.h>  // Include the stdio.h library for standard input/output functions
# include <stdlib.h>  // Include the stdlib.h library for general purpose functions
# include <stdarg.h>  // Include the stdarg.h library for handling variable argument list

// Function prototypes

// This function is a custom implementation of the printf function from the standard C library.
// It takes a format string and a variable number of arguments, and writes the formatted output to the standard output.
int				ft_printf(const char *format_str, ...);

// This function takes a character as input and writes it to the standard output.
// It returns 1 if the character was written successfully, or -1 if there was an error.
int				ft_putchar(int c);

// This function takes an integer as input and writes it to the standard output digit by digit.
// It returns the number of digits printed, or -1 if there was an error.
int				ft_putnbr(int n);

// This function takes a string as input and writes it to the standard output character by character.
// It returns the number of characters printed, or -1 if there was an error.
int				ft_putstr(char *s);

// This function takes a pointer as input and writes its hexadecimal representation to the standard output.
// It returns the number of characters printed, or -1 if there was an error.
int				ft_hex_pointer(void *p);

// This function takes an integer as input and writes its hexadecimal representation to the standard output using lowercase letters.
// It returns the number of characters printed, or -1 if there was an error.
int				ft_hex_lower(int num);

// This function takes an integer as input and writes its hexadecimal representation to the standard output using uppercase letters.
// It returns the number of characters printed, or -1 if there was an error.
int				ft_hex_upper(int num);

// This function takes a string as input and returns its length.
int				ft_strlen(char *s);

// This function takes an unsigned integer as input and prints it out digit by digit.
// It returns the number of digits printed, or -1 if there was an error.
unsigned int	ft_unsigned(unsigned int num);

#endif  // End of the conditional directive. The code between #ifndef and #endif is included only once.
