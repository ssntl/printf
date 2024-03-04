# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 19:15:51 by bsaager           #+#    #+#              #
#    Updated: 2024/03/04 17:30:59 by bsaager          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKE_LIB = ar -rcs

INCLUDE = .

SRC = ft_printf.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_unsigned.c \
	   ft_hex_pointer.c \
	   ft_putstr.c \
	   ft_hex_lower.c \
	   ft_hex_upper.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(MAKE_LIB) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

