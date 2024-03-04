# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsaager < bsaager@student.42berlin.de >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 19:15:51 by bsaager           #+#    #+#              #
#    Updated: 2024/02/24 19:59:12 by bsaager          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MAKE_LIB = ar -rcs

INCS = .


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
	$(CC) $(CFLAGS) -c $< -I$(INCS)

$(LIBFT) :
	cd $(LIBFT_PATH) && make
	cp $(LIBFT) $(NAME)

clean :
	rm -rf $(OBJ)
	cd $(LIBFT_PATH) && make clean

fclean :
	rm -rf $(OBJ) $(NAME)
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re
