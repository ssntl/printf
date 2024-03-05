NAME = libftprintf.a  // The name of the output file (a static library)
CC = gcc  // The C compiler to use
CFLAGS = -Wall -Wextra -Werror  // Compiler flags: enable all warnings and treat warnings as errors
MAKE_LIB = ar -rcs  // Command to create a static library

INCLUDE = .  // Directory where the header files are located

// List of source files
SRC = ft_printf.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_unsigned.c \
	   ft_hex_pointer.c \
	   ft_putstr.c \
	   ft_hex_lower.c \
	   ft_hex_upper.c \

OBJ = $(SRC:.c=.o)  // List of object files, generated from the list of source files by replacing '.c' with '.o'

all : $(NAME)  // Default target: build the library

$(NAME) : $(OBJ) $(LIBFT)  // Rule to build the library: requires the object files
	$(MAKE_LIB) $(NAME) $(OBJ)  // Command to build the library

%.o : %.c  // Rule to build an object file from a source file
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE)  // Command to compile the source file

clean :  // Target to remove the object files
	rm -rf $(OBJ)

fclean : clean  // Target to remove the object files and the library
	rm -rf $(NAME)

re: fclean all  // Target to rebuild everything

.PHONY: all clean fclean re  
// Declare that all, clean, fclean, and re are phony targets tells make that all, clean, fclean, and re are not files, so it wont get confused if there are actual files with these names.
